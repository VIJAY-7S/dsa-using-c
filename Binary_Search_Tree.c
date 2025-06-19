/*
Develop a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers .
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit
*/

# include<stdio.h>
# include<stdlib.h>

struct tree
{
    int data;
    struct tree *right,*left;
};

typedef struct tree * TREE;

TREE create()
{
    TREE node;
    node = (TREE)malloc(sizeof(struct tree));

    if(node == NULL)
    {
        printf("Not allocated");
    }
    return(node);
}

TREE create_bst(TREE root)
{
    TREE cur,prev,node;
    node = create();

    printf("Enter the data : ");
    scanf("%d",&node->data);
    node->left = NULL;
    node->right = NULL;

    if(root == NULL)
    {
        root = node;
        return root;
    }
    else
    {
        cur = root;
        prev = NULL;

        while (cur!=NULL)
        {
            prev = cur;

            if(node->data < cur->data)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }

        }
        if(node->data < prev->data)
        {
            prev->left = node;
        }
        else
        {
            prev->right = node;
        }
        return root;
    }
}

void inorder(TREE root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void preorder(TREE root)
{
    if(root == NULL)
    {
        return;
    }

    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TREE root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

TREE bst(TREE root)
{
    int key,flag = 0;
    TREE temp;

    printf("Enter the key element to be searched : ");
    scanf("%d",&key);

    temp = root;

    while(temp!=NULL)
    {
        if(key == temp->data)
        {
            flag = 1;
            break;
        }
        else if(key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (flag == 1)
    {
        printf("Key found ");
    }

    else
    {
        printf("Key not found ");
    }

}

int main()
{
    int ch,n;
    TREE root;
    root = NULL;

    for(;;)
    {
        printf("\nBST OPERATIONS\n");
        printf(" 1.Create List\n 2.Inorder\n 3.Preorder\n 4.Postorder\n 5.BST Search\n 6. Exit\nEnter ur choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : printf("Enter the number of elements : ");
                     scanf("%d",&n);

                     for(int i =0;i<n;i++)
                     {
                        root = create_bst(root);
                     }
                     break;

            case 2 : inorder(root);
                     break;

            case 3 : preorder(root);
                     break;

            case 4 : postorder(root);
                     break;

            case 5 : bst(root);
                     break;

            case 6 : exit(0);
            default: printf("Invalid Choice ");

        }
    }
    return 0;
}
