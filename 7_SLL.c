/*
Develop a menu driven Program in C for the following operations on Singly Linked List (SLL) of
Student Data with the fields: USN, Name, Programme, Sem,PhNo 
a. Create a SLL of N Students Data by using front insertion. 
b. Display the status of SLL and count the number of nodes in it 
c. Perform Insertion / Deletion at End of SLL 
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) 
e. Exit
*/

# include<stdio.h>
# include<stdlib.h>

struct student
{
    char USN[10];
    char name[20];
    char prog[10];
    int sem;
    long int phno;
    struct student * link;
};

typedef struct student * STU;
STU start = NULL;
STU create()
{
    STU gnode;

    gnode = (STU)malloc(sizeof(struct student));

    if(gnode == NULL)
    {
        printf("Memory not allocated ");
        return;
    }

    printf("\nEnter the details of the student \n");

    printf("Enter the name ");
    scanf("%s",gnode->name);

    printf("Enter the USN ");
    scanf("%s",gnode->USN);

    printf("Enter the Program ");
    scanf("%s",gnode->prog);

    printf("Enter the Sem ");
    scanf("%d",&gnode->sem);

    printf("Enter the Ph no : ");
    scanf("%ld",&gnode->phno);

    gnode->link = NULL;
    return gnode;
}

void insert_front()
{
    STU node;
    node = create();
    if(start == NULL)
    {
        start = node;
    }

    else
    {
        node->link = start;
        start = node;
    }
}

void delete_front()
{
    STU temp;
    if(start == NULL)
    {
        printf("The list is empty ");
    }
    else 
    {
        temp = start;
        start = temp->link;
        printf("The deleted USN is %s : ",temp->USN);
        free(temp);
    }
}

void insert_end()
{
    STU node,temp;
    node = create();

    if(start == NULL)
    {
        start = node;
    }
    else
    {
        temp = start;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = node;
    }
}

void delete_end()
{
    STU temp,prev;
    if(start == NULL)
    {
        printf("The list id empty ");
    }
    else if(start->link == NULL)
    {
        start == NULL;
    }
    else
    {
        temp =start;
        prev = NULL;
        while(temp->link!=NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        printf("The deleted USN is %s : ",temp->USN);

        prev->link = NULL;
        free(temp);
    }
}

void display()
{
    STU temp;
    int count=0;
    if(start == NULL)
    {
        printf("The list is empty ");
        return;
    }
    else
    {
    temp = start;
    printf("\n            Student Details         \n");
    while(temp!=NULL)
    {
        printf("%s\t%s\t%s\t%d\t%ld\n",temp->USN,temp->name,temp->prog,temp->sem,temp->phno);
        temp = temp->link;
        count++;
    }
    printf("The number of students are %d",count);
    }
}

void create_lst()
{
    int n,i;
    printf("Enter the number of students : ");
    scanf("%d",&n);

    for(i = 0;i<n;i++)
    {
        insert_front();
    }
}

void stack_op()
{
    int ch,n;
    for(;;)
    {
        printf("\n         Stack Operations         \n");
        printf("\n 1. Push\n 2. Pop\n 3. Status of the stack\n 4. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insert_front();
                     break;

            case 2 : delete_front();
                     break;

            case 3 : display();
                     break;

            case 4 : exit(0);
                     break;

            default: printf("Invalid Choice ");
            
        }
    }
}

int main()
{
    int choice;
    for(;;)
    {
        printf("\n         SLL Operations         \n");
        printf("\n 1. create List\n 2. Status\n 3. Insert Front\n 4. Delete Front\n 5. Insert End\n 6. Delete End \n 7. Stack Operations \n 8. Exit \nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)    
        {
            case 1 : create_lst();
                     break;

            case 2 : display();
                     break;

            case 3 : insert_front();
                     break;

            case 4 : delete_front();
                     break;

            case 5 : insert_end();
                     break;

            case 6 : delete_end();
                     break;

            case 7 : stack_op();
                     break;

            case 8 : exit(0);
                     break;

            default: printf("Invalid Choice ");
            
        }
    }
    return 0;
}


