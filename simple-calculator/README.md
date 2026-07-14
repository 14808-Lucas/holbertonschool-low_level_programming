C-Simple calculator:

Task 0- I declared " int choice" as my integer and gave choice an initial valueof -1 before the loop starts, because the values 0-5 are selections for the calculator menu. we use print f to display the menu and scanf("%d", &choice); to display/ select the input picked. %d shows the decimal integer.  

Task 1 - made program loop if selecting "invalid choice" by having else if (choice >= 1 && choice <= 4) it gives a limiter to which numbers are valid.  by having the " else" afterward printf invalid choice, creates loop until valid number is given.

Task 2 - I declared integers, int a,b, and result. put in an "if" loop, if (choice == 1).used printf " A: " to print and declare what value you would like to be. scanf("%d", &a); holds the value in a which is what the "&" represents so you can hold the value and do a+b to print its result in result int. adjusted else if choice 2-4 as they are not in use currently.

Task 3 - did the same as above but for subtraction. adjust else if choice 3-4 as they are not currently in use.\

Task 4 - did the same program as above but adjusted result = a * b to represent multiplication of held values.

Task 5 - Was hard.. I had to use a float integer. so i declared float divisionResult;  both a and b are integers and they store whole numbers instead of decimals. while a float can store decimals. if i divided a / b with just %d it would print as 2 and not 2.5. float changes an int to a float which holds a value of 10.0 for example instead of just 10. to print the float value we have to use printf("%f\n". which prints out a decimal number. you can adjust the decimal to one digit if you but a "1" before the f. by declaring float and when we divide our a / b with it we get a decimal printed out.  


