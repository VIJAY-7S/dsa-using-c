/*
Develop a menu driven Deptram in C for the following operations on Doubly rlinked List (DLL) of
Employee Data with the fields: SSN, Name, Dept, Designation,Sal, PhNo 
a. Create a DLL of N Employees Data by using end insertion. 
b. Display the status of DLL and count the number of nodes in it 
c. Perform Insertion and Deletion at End of DLL 
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue. 
f. Exit
*/

# include<stdio.h>
# include<stdlib.h>

struct employee
{
    char SSN[10];
    char name[20];
    char Dept[10];
    char dsgn[10];
    int sal;
    long int phno;
    struct employee * llink;
    struct employee * rlink;
};

typedef struct employee * EMP;
EMP start = NULL;
EMP create()
{
    EMP gnode;

    gnode = (EMP)malloc(sizeof(struct employee));

    if(gnode == NULL)
    {
        printf("Memory not allocated ");
    }

    printf("\nEnter the details of the employee \n");

    printf("Enter the SSN ");
    scanf("%s",gnode->SSN);

    printf("Enter the name ");
    scanf("%s",gnode->name);

    printf("Enter the Department ");
    scanf("%s",gnode->Dept);

    printf("Enter the Designation ");
    scanf("%s",gnode->dsgn);

    printf("Enter the sal ");
    scanf("%d",&gnode->sal);

    printf("Enter the Ph no : ");
    scanf("%ld",&gnode->phno);

    gnode->rlink = NULL;
    gnode->llink = NULL;
    return gnode;
}

void insert_front()
{
    EMP node;
    node = create();
    if(start == NULL)
    {
        start = node;
    }

    else
    {
        start->llink = node;
        node->rlink = start;
        start = node;
    }
}

void delete_front()
{
    EMP temp;
    if(start == NULL)
    {
        printf("The list is empty ");
    }
    else 
    {
        temp = start;
        start = temp->rlink;
        start->llink = NULL;
        printf("The deleted SSN is %s : ",temp->SSN);
        free(temp);
    }
}

void insert_end()
{
    EMP node,temp;
    node = create();

    if(start == NULL)
    {
        start = node;
    }
    else
    {
        temp = start;
        while(temp->rlink!=NULL)
        {
            temp = temp->rlink;
        }
        temp->rlink = node;
        node->llink = temp;
    }
}

void delete_end()
{
    EMP temp,prev;
    if(start == NULL)
    {
        printf("The list id empty ");
    }
    else if(start->rlink == NULL)
    {
        start == NULL;
    }
    else
    {
        temp =start;
        prev = NULL;
        while(temp->rlink!=NULL)
        {
            prev = temp;
            temp = temp->rlink;
        }
        printf("The deleted SSN is %s : ",temp->SSN);

        prev->rlink = NULL;
        free(temp);
    }
}

void display()
{
    EMP temp;
    int count=0;
    if(start == NULL)
    {
        printf("The list is empty ");
        return;
    }
    else
    {
    temp = start;
    printf("\n            Employee Details         \n");
    while(temp!=NULL)
    {
        printf("%s\t%s\t%s\t%s\t%d\t%ld\n",temp->SSN,temp->name,temp->Dept,temp->dsgn,temp->sal,temp->phno);
        temp = temp->rlink;
        count++;
    }
    printf("The number of employees are %d",count);
    }
}

void create_lst()
{
    int n,i;
    printf("Enter the number of employees : ");
    scanf("%d",&n);

    for(i = 0;i<n;i++)
    {
        insert_end();
    }
}

void queue_op()
{
    int ch,n;
    for(;;)
    {
        printf("\n         Queue Operations         \n");
        printf("\n 1. Insert Front \n 2. Delete Front \n 3. Insert Rear\n 4. Delete Rear \n 5. Display Queue\n 6. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insert_front();
                     break;

            case 2 : delete_front();
                     break;

            case 3 : insert_end();
                     break;

            case 4 : delete_end();
                     break;

            case 5 : display();
                     break;

            case 6 : exit(0);
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
        printf("\n         DLL Operations         \n");
        printf("\n 1. create List\n 2. Status\n 3. Insert Front\n 4. Delete Front\n 5. Insert End\n 6. Delete End \n 7. Queue Operations \n 8. Exit \nEnter your choice : ");
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

            case 7 : queue_op();
                     break;

            case 8 : exit(0);
                     break;

            default: printf("Invalid Choice ");
            
        }
    }
    return 0;
}
