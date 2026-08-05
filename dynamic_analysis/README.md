C - Dynamic Analysis & Reverse Logic with GDB


Learning Objectives:
By completing this project, you will be able to:

Use GDB to:

run a program under controlled execution,

set breakpoints,

step through code,

inspect variables and function arguments,

observe control flow decisions.

Use Visual Studio Code as a debugging frontend while understanding the underlying debugger behavior.

Infer an algorithm by observing runtime behavior rather than guessing from source code.


Header file
[clickable link name to file](./filename)

Project File Table
The following files are included in this project:

| File           | Description |
|--------- |-------------|
|                    |                        |


Line 1: I used grep -n "user_pin" source.c to find the lines user pin was used before G_state. i determeined it was line 83. I then set the breakpoint at 83 and ran the program using 123456. It stopped at the breakpoint confirming the address of the issue. I then used pprint 0r p  printf "0x%08X\n", x and it came out with 0xF2EF340B

line 2 : I used grep -n "return x;" and found lines 22 & 88. we used 88 as it is inside the derive key. we put the break at line 88 and ran the program using 123456. it stopped at the break point and we were able to get the value of x by p "0x%08X\n", x. 0x449BC842

line 3 : I used list compute target to find the function in the program because i needed to find the exact line for the end iteration of i == 0. which was line 105                     acc += 0x7F4A7C15u; . i ran the program to check it stops on that line and printed the address 0x65735AA6
