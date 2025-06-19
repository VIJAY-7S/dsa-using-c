// Pattern Match

# include<stdio.h>

char str[100],pat[100],rep[100];
int pat_len;
void read_str()
{
    int i;

    printf("Enter the Main String : ");
    gets(str);

    printf("Enter the Pattern String : ");
    gets(pat);

    printf("Enter the Replacement String : ");
    gets(rep);

    for(i=0;pat[i]!='\0';i++)
        pat_len++;
}

void pat_match()
{
    int i,j,k,z=0,count=0;
    char final[100];

    for(i=0;str[i]!='\0';i++)
    {
        j=0;
        while((str[i+j]==pat[j]) && (j<pat_len))
        j++;

        if (pat[j]=='\0')
        {
            count++;

            for(k=0;rep[k]!='\0';k++,z++)
            {
                final[z]=rep[k];
            }
            i=i+pat_len-1;
        }
        else
        {
            final[z]=str[i];
            z++;
        }
    }

    if (count==0)
    {
        printf("There is no pattern match");
    }
    else
    {
        final[z]='\0';
        printf("\nThe number of pattern matched is : %d",count);
        printf("\nThe main string is : %s\n",str);
        printf("The String after the replacement : %s\n",final);
    }
}

int main()
{
    read_str();
    pat_match();
    return 0;
}