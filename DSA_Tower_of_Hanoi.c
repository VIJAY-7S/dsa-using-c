# include<stdio.h>

void TOH(int n, char src,char aux,char dst)
{
    if(n>0)
    {
        TOH(n-1,src,dst,aux);
        printf("Disk is moved from %c to %c \n",src,dst);
        TOH(n-1,aux,src,dst);
    }
}
int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    TOH(n,'A','B','C');
}