#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
int generate_random_number(int range)
{
    srand(time(0));
    return (rand()%range);
}

void get_characters(char a[])
{
    int no,i;
    printf("\nEnter the number of characters to practice = ");
    scanf("%d",&no);
    printf("\nEnter the characters to practice\n");
    for(i=0;i<no;i++)
        a[i]=getche();
    a[i]='\0';
}
void run(int choice)
{
    int length=0;

    char pressed;
    char got;

    int right=0;
    int wrong=0;
    int counter=0;

    char characters[40];

    //  All Character Practice
    //char characters[]={'a','s','d','f','g','h','j','k','l',';','q','w','e','r','t','y','u','i','o','p','z','x','c','v','b','n','m',',','.','/','\0'};

    //  Upper Line Practice
    char upper_line_characters[]={'q','w','e','r','t','y','u','i','o','p','\0'};

    //  Middle Line Practice
    char middle_line_characters[]={'a','s','d','f','g','h','j','k','l',';','\0'};

    //  Lower Line Practice
    char lower_line_characters[]={'z','x','c','v','b','n','m',',','.','/','\0'};

    switch(choice)
    {
    case 1:
        strcpy(characters,upper_line_characters);
        break;

    case 2:
        strcpy(characters,middle_line_characters);
        break;

    case 3:
        strcpy(characters,lower_line_characters);
        break;

    case 4:
        strcpy(characters,upper_line_characters);
        strcat(characters,middle_line_characters);
        strcat(characters,lower_line_characters);
        break;

    case 5:
        get_characters(characters);
        break;
    }
    printf("\nPress the character you see\n ( Press Esc / Escape to exit )\n");
    length=strlen(characters);
    while(1)
    {
        counter++;
        got=characters[generate_random_number(length)];
        printf("\n%c",got);
        pressed=getche();
        if(pressed==(char)27)
        {
            counter--;
            break;
        }
        else if(pressed == got)
            right++;
        else
            wrong++;
    }
    if(counter>0)
    {
        printf("\n\n\tTotal\t%d\n",counter);
        printf("\n\tCorrect\t\t%d\t%.2f %c\n",right,(((float)right/(float)counter)*100),37);
        printf("\n\tIncorrect\t%d\t%.2f %c\n",wrong,(((float)wrong/(float)counter)*100),37);
    }


}
void check()
{
    int choice=-1;
    printf("\n*******************************************************************");
    printf("\n\tWelcome to Typing Practice by Debdeep\n");
    printf("\n*******************************************************************\n");
    while(choice!=0)
    {
        printf("\n\nTo Practice Upper Line Characters Enter\t\t\t 1\n");
        printf("\nTo Practice Middle Line Characters Enter\t\t 2\n");
        printf("\nTo Practice Lower Line Characters Enter\t\t\t 3\n");
        printf("\nTo Practice All Combinations of Characters Enter\t 4\n");
        printf("\nTo Practice Custom Characters Enter\t\t\t 5\n");
        printf("\nTo Exit Enter\t\t\t\t\t\t 0\n");
        printf("\nEnter your choice = ");
        scanf("%d",&choice);
        if(choice==0)
            break;
        else if(choice>=1 && choice<=5)
        {
            run(choice);
            break;
        }
        else
        {
            printf("\n!!!!!!!       Invalid Choice..   Please Try Again.... ");
            delay(2);
            system("cls");
            continue;
        }
    }
    printf("\n\nPress any key to exit....");
    getch();
}

int main()
{
    check();
    return 0;
}
