#include <stdio.h>
int main(void)
{
    int Choice;
    while (1)
    {
        printf("Simple Calculator\n");
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");
        printf("choice: ");
        scanf("%d", &Choice);
        if (Choice == 0)
        {
            printf("Bye!\n");
            break;
        }
    }
    return (0);
}