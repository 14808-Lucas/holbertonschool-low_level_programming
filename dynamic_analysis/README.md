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

