# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<ctype.h>

int i,top =-1;
int op1,op2,res,s[20];
char suffix[100],symb;

void push(int elem)
{
    top = top+1;
    s[top]=elem;
}

int pop()
{
    int item;
    item = s[top];
    top = top-1;
    return item;
}

void main()
{
    float val;
    printf("\n Enter the Suffix Expression : ");
    scanf("%s",suffix);

    for(i=0;suffix[i]!='\0';i++)
    {
        symb = suffix[i];

        if(isdigit(symb))
        {
            push(symb-'0');
        }

        else if (isalpha(symb))
        {
            printf("Enter the value of %c : ",symb);
            scanf("%f",&val);
            push(val);
        }

        else
        {
            op2 = pop();
            op1 = pop();

            switch(symb)
            {
                case '+' : push(op1+op2);
                           break;

                case '-' : push(op1-op2);
                           break;

                case '*' : push(op1*op2);
                           break;

                case '/' : push(op1/op2);
                           break;

                case '^' : push(pow(op1,op2));
                           break;

                case '%' : push(fmod(op1,op2));
                           break;
            }
        }
    }
    res = pop();
    printf("Result : %d",res);
}
