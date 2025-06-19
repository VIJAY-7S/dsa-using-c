/*
AIM: Develop a menu driven Program in C for the following operations on STACK of Integers
(Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations
*/

# include<stdio.h>
# define MAX 5
int top = -1;
int s[MAX-1];

void push(int elem)
{
    if(top == MAX-1)
    {
        printf("Stack overflow Element not added!");
        return;
    }

    top++;
    s[top]=elem;
    printf("Element added is %d",s[top]);
}

int pop()
{
    if(top == -1)
    {
        printf("The stack is empty");
        return -1;
    }
    else
    {
        printf("The deleted element is %d",s[top]);
        int del = s[top];
        top = top-1;
        return del;
    }
}

void pallindrome()
{
    int n,flag,p[10],i;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        push(p[i]);
    }

    for(i=0;i<n;i++)
    {
        if(p[i]!=pop())
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("Palindrome!");
    }

    else
    {
        printf("Not Palindrome");
    }
}

void display()
{

    if(top ==-1)
    {
        printf("The stack is empty !");
        return;
    }
    int i;
    printf("The elmeents are :");

    for(i=top;i>=0;i--);
    {
        printf("%d",s[i]);
    }
}

int main()
{
    int ch,elem;

    for(;;)
    {
        printf("\nSTACK OPERATIONS\n 1.Push\n 2.Pop\n 3.Display\n 4.Palindrome\n 5.Exit\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : printf("Enter the element to be pushed : ");
                     scanf("%d",&elem);
                     push(elem);
                     break;

            case 2 : pop();
                     break;

            case 3 : display();
                     break;

            case 4 : pallindrome();
                     break;

            case 5 : return 0;

            default : printf("Invalid Choice !");

        }
    }
    return 0;
}