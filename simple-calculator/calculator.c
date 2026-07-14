#include <stdio.h>

int main(void)
{
    int choice;
    int a;
    int b;
    int result;
    float divisionResult;

    printf("Simple Calculator\n");

    choice = -1;

    while (choice != 0)
    {
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Bye!\n");
        }
	if (choice == 1)
	{
		printf("A: ");
		scanf("%d", &a);

		printf("B: ");
		scanf("%d", &b);

		result = a + b;

		printf("Result: %d\n", result);
	}
	else if (choice == 2)
	{
		printf("A: ");
		scanf("%d", &a);

		printf("B ");
		scanf("%d", &b);

		result = a - b;

		printf("Result: %d\n", result);
	}
	else if (choice == 3)
	{
		printf("A: ");
		scanf("%d", &a);

		printf("B ");
		scanf("%d", &b);

		result = a * b;

		printf("Result: %d\n", result);
	}
	else if (choice == 4)
	{
		printf("A: ");
		scanf("%d", &a);

		printf("B: ");
		scanf("%d", &b);

		if (b == 0)
		{
			printf("Error: division by zero\n");
		}
		else
		{
			divisionResult = (float)a / b;
			printf("Result: %.1f\n", divisionResult);
		}
	}
        else if (choice >= 1 && choice <= 4)
        {
            printf("You selected option %d\n", choice);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
