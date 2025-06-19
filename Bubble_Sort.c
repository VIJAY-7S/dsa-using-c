# include<stdio.h>
int main()
{
    int n,i,j,temp;
    int Arr[20];
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&Arr[i]);
    }
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (Arr[j]>Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
    printf("The sorted elements are : ");
    for (i=0;i<n;i++)
    {
        printf("%d  ",Arr[i]);
    }
    return 0;
}