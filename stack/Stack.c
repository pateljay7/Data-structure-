#include<stdio.h>
#include<conio.h>
int top = 0;
int max=10;
int main ()
{

    int stack[max];
    int n;
    printf("Choices : \n");
    printf ("1. push\n");
    printf ("2. pop\n");
    printf ("3. print\n");
    printf ("4. exit\n");

    while (n != 4)
    {
        printf ("enter your choise:");
        scanf ("%d", &n);

        if (n == 1)
        {
            push (stack);
        }
        else if (n == 2)
        {
            pop (stack);
        }
        else if (n == 3)
        {
            print (stack);
        }
    }
}
void push (int stack[])
{
    int no;
    if (top == max)
    {
        printf ("your stack is full!\n");
    }
    else
    {
        printf ("enter your number:");
        scanf ("%d", &no);
        stack[top] = no;
        top = top + 1;
    }
}

void pop (int stack[])
{

    if (top == 0)
    {
        printf ("your stack is empty!\n");
    }
    else
    {
        top = top - 1;
        printf ("your number:%d\n", stack[top]);
    }
}

void print (int stack[])
{
    int i = 0;

    for (i = 0; i < top; i++)
    {
        printf ("%d\n", stack[i]);
    }
}
