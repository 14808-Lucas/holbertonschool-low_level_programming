 Valgrind Analysis  heap_example.c and aliasing_example.c

 Programs analyzed:
-heap_example.c
-aliasing_example.c

stack_example.c has no heap activity and is out of scope for this
task.

Command used:

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./<binary>

--leak-check=full  and --show-leak-kinds=all  were used so that
every leak category (not just a summary count) would be shown in
detail, per the task's requirement to capture *all* reported issues.
--track-origins=yes was included specifically to catch and localize
any value errors.

Part 1  heap_example.c

Full captured Valgrind output

==559== HEAP SUMMARY:
==559==     in use at exit: 6 bytes in 1 blocks
==559==   total heap usage: 5 allocs, 4 frees, 4,138 bytes allocated
==559==
==559== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
==559==    at 0x4846828: malloc (vgpreload_memcheck-amd64-linux.so)
==559==    by 0x109211: person_new (heap_example.c:21)
==559==    by 0x1092FA: main (heap_example.c:51)
==559==
==559== LEAK SUMMARY:
==559==    definitely lost: 6 bytes in 1 blocks
==559==    indirectly lost: 0 bytes in 0 blocks
==559==      possibly lost: 0 bytes in 0 blocks
==559==    still reachable: 0 bytes in 0 blocks
==559==         suppressed: 0 bytes in 0 blocks
==559==
==559== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

Error classification heap_example.c :
one leak, classified precisely (definitely lost, due to lost ownership), person_new makes two separate malloc calls per Person (the struct, and the name string), but person_free_partial only ever frees the struct, so alice's name string is left with no pointer to it and  gets flagged as definitely lost. bob doesn't have this problem, since main manually frees bob

 Explanation of the lifetime violation

person_new performs two separate heap allocations
per Person it creates: the `Person` struct itself malloc(sizeof(Person), and a second, independent block for the
name string malloc(len + 1), stored in p->name. These
are two distinct objects with two distinct lifetimes, linked only by
the struct field that happens to point from one to the other.

person_free_partial  frees exactly one of thes

main calls person_free_partial(alice) as its only
cleanup step for alice. At the moment that call returns, the
Person struct is gone, and with it, the only remaining pointer to
alice's name block p->name since p itself no longer exists to
be dereferenced. The 6-byte name block therefore becomes definitely
lost.

---
Part 2 aliasing_example.c

Full captured Valgrind output


==561== Invalid read of size 4
==561==    at 0x1092F5: main (aliasing_example.c:42)
==561==  Address 0x4a7d088 is 8 bytes inside a block of size 20 free'd
==561==    at 0x484988F: free (vgpreload_memcheck-amd64-linux.so)
==561==    by 0x1092D1: main (aliasing_example.c:38)
==561==  Block was alloc'd at
==561==    at 0x4846828: malloc (vgpreload_memcheck-amd64-linux.so)
==561==    by 0x1091E4: make_numbers (aliasing_example.c:12)
==561==    by 0x109272: main (aliasing_example.c:30)
==561==
==561== Invalid write of size 4
==561==    at 0x109315: main (aliasing_example.c:44)
==561==  Address 0x4a7d08c is 12 bytes inside a block of size 20 free'd
     [same free()-at-line-38 / malloc()-at-line-12 trace]
==561==
==561== Invalid read of size 4
==561==    at 0x109323: main (aliasing_example.c:45)
     [same trace again]
==561==
==561== HEAP SUMMARY:
==561==     in use at exit: 0 bytes in 0 blocks
==561==   total heap usage: 2 allocs, 2 frees, 4,116 bytes allocated
==561== All heap blocks were freed -- no leaks are possible
==561==
==561== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)


Error classification aliasing_example.c :

Three errors total, matching Valgrind's All three trace back to a single root cause: b = a; made b an alias of a, so when free(a) ran at line 38, it invalidated the one block both names pointed to
The heap summary confirms 2 allocs, 2 frees, all blocks freed by exit. Every reported error here is a use-after-free, not a leak; the two categories are not the
same and shouldn't be conflated (a leak is memory that's never
freed; a use-after-free is memory that was freed but is still being
accessed).

Explanation of the lifetime violation:
make_numbers allocates one heap block, and b = a makes b an alias pointing to that exact same block rather than a separate one. free(a) ends that block's lifetime for both names at once, since they were never independent but b's own stored address value is left ompletely unchanged by the free. The program then reads and writes through b three more times after this point, each access a use-after-free on memory whose lifetime had already ended.

Alias AI explanation ( incorrect):
Valgrind reported 3 errors for aliasing_example.c, so there are three separate bugs in this program: an invalid read, an invalid write, and a second invalid read, each representing a distinct memory-safety violation that would need to be fixed independently."

That is incorrect because it treated Valgrind's error count as the same thing as the number of root causes which isn't the case. Reading the full backtraces not just the top-line error message shows all three errors trace back to the exact same malloc and exact same free.
