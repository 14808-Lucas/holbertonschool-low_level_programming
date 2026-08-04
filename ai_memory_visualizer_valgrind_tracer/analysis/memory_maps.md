
Programs intended for analysis are stack_example.c & aliasing_example.c as both are displayed as part of the memory task. heap_example.c is optional and made for the memory tracer task.

Identify key execution points where memory state changes:

stack_example.c: recurses from depth 0 to 3, and at each depth walk_stack creates a local marker, then calls dump_frame twice, once entering, once exiting. Every call gets its own fresh stack frame, and as recursion deepens, frame addresses consistently decrease, confirming the stack grows downward on this platform. A stack frame becomes invalid the instant the function that owns it returns, its memory isn't cleared or marked in any special way, it's simply free to be handed to the next function call, which is exactly why the later "exit" call can land on the same address. The "enter" call at each depth is fully created and destroyed before the next recursive call happens, so by the time the matching "exit" call runs later, it lands on a new frame that just happens to reuse that same now-freed address. Only walk_stack's own frames persist across the recursion, and they're destroyed in reverse order (depth 3 first, depth 0 last), the direct result of each call waiting for the one it called to finish first. This entire program uses only stack memory, there is no heap allocation anywhere in it.

aliasing_example.c: allocates a single 20-byte heap block in make_numbers, initializes it, and returns its address into a. b = a then makes b an alias for the exact same block, not a separate copy. a is the owner of the heap block returned by make_numbers, and is responsible for freeing it; b, as an alias, shares access to the same block but not ownership, since there's only one block in total, freeing it through either name has the identical effect, invalidating both at once. free(a) releases that block, but critically leaves both a and b's stored address values completely unchanged; only whether dereferencing that address is valid has changed. This turns b into a dangling pointer, and the program goes on to read and write through it three more times regardless, none of which crash, since the underlying memory page is still mapped. a and b themselves are ordinary stack variables that live and die with main, while the 20-byte block they point to lives on the heap, with a lifetime controlled entirely separately by malloc/free.

AI example:

Correction 1, stack growth direction, stack_example.c.
The initial AI-generated claim (wrong): "As the recursion gets deeper, each new stack frame is placed on top of the previous one, so walk_stack's and dump_frame's local variables will be allocated at progressively higher memory addresses as depth increases from 0 to 3."
Why it was wrong: "stack" as a data structure conceptually grows "up," so it's easy to assume that maps onto higher memory addresses. The actual convention is the opposite: the call stack grows toward lower addresses as more frames get pushed.
How it got caught: by checking it against the real captured addresses, which went 0x7ffec0fc5564, 0x7ffec0fc5534, 0x7ffec0fc5504, 0x7ffec0fc54d4 as depth increased, strictly decreasing, the opposite of the claim.

Correction 2, what actually happens to a pointer's value after free(), aliasing_example.c.
The initial AI-generated claim (wrong): "After free(a) is called, b will become NULL, and reading through it afterward should either look obviously wrong or crash immediately."
Why it was wrong: free() only receives the one address passed to it, it has no way to reach into every other variable holding a copy of that same address and reset them. The claim describes behavior C doesn't have.
How it got caught: b's printed value was identical before and after the free (0x557fb40522b0 both times), and reading b[2] afterward didn't crash, it printed ordinary-looking data with no built-in warning sign.
