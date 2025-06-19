// Calender 

# include<stdio.h>
# include<stdlib.h>
# include<string.h>

struct Day
{
    char *dayName;
    int date;
    char *Activity;
};

struct Day create()
{
    struct Day newDay;

    newDay.dayName = (char *)malloc(20 * sizeof(char));
    newDay.Activity = (char *)malloc(100 * sizeof(char));

    printf("Enter the Name day : ");
    scanf("%s",newDay.dayName);

    printf("Enter the date : ");
    scanf("%d",&newDay.date);

    printf("Enter the Activity for the day : ");
    scanf("%s",newDay.Activity);

    return newDay;
}

void read(struct Day calender[], int numDays)
{
    int i;
    for(i=0;i<numDays;i++)
    {
        printf("Enter the details for the day %d\n",i+1);
        calender[i]=create();
    }
}

void display(struct Day calender[], int numDays)
{
    printf("\n Calender \n");
    printf("Day\tDate\tActivity\n");
    for(int i=0;i<numDays;i++)
    {
        printf("%s\t%d\t%s\n",calender[i].dayName,calender[i].date,calender[i].Activity);
    }
}

int main()
{
    int i;
    int numDays = 7;

    struct Day calender[7];

    read(calender,numDays);
    display(calender,numDays);

    for(i=0;i<numDays;i++)
    {
        free(calender[i].dayName);
        free(calender[i].Activity);
    }

    return 0;
}