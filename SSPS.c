#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void delay(int milli_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

struct pattern
{
    char str1[30];
    char str2[30];
    char str3[30];
};

int score=0;

void select_check(char* ptr1,char* ptr2,char* ptr3,int n)
{
    if(n==0)
    {
        fflush(stdin);
        fflush(stdout);
        n=(rand()%3)+1;
    }

    if(n==1)
    {
        char temp1[30]=" __________";
        char temp2[30]="| ** ** ** |";
        char temp3[30]="|___*__*___|";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
    }
    else if(n==2)
    {
        char temp1[30]=" __________";
        char temp2[30]="| // // // |";
        char temp3[30]="|___/__/___|";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
    }
    else if(n==3)
    {
        char temp1[30]=" __________";
        char temp2[30]="| ++ ++ ++ |";
        char temp3[30]="|___+__+___|";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
    }
}

void last_block(char* ptr1,char* ptr2,char* ptr3)
{
    char temp1[30]=" ";
    char temp2[30]=" ";
    char temp3[30]=" ";
    strcpy(ptr1,temp1);
    strcpy(ptr2,temp2);
    strcpy(ptr3,temp3);
}

void count_score(char* ptr1,char* ptr2,char* ptr3,struct pattern* node)
{
    int new_score=0;
    for(int i=5; i>0; i--)
    {
        if(strcmp(((node+i)->str2),ptr2)!=0)
            break;
        new_score=new_score+1;
    }
    score=score+new_score;
    node=(struct pattern*)realloc(node,(6-new_score)*sizeof(struct pattern));
    node=(struct pattern*)realloc(node,6*sizeof(struct pattern));
    for(int i=5; i>(5-new_score); i--)
    {
        last_block((node+i)->str1,(node+i)->str2,(node+i)->str3);
    }
    if(new_score>0)
    {
        select_check(ptr1,ptr2,ptr3,0);
        // COLOR
        int x=0;
        while(x<2)
        {
            delay(100);
            if(x==0)
                system("COLOR 20");
            else if(x==1)
                system("COLOR 01");
            x++;
        }
    }
}

int length(int n)
{
    int count=0;
    for(int i=0; n!=0; i++)
    {
        n=n/10;
        count++;
    }
    return count;
}

int power(int x,int y)
{
    if(y==0)
        return 1;
    else if(y==1)
        return x;
    else
        return x*power(x,y-1);
}

void design(char* ptr1,char* ptr2,char* ptr3,char* ptr4,char* ptr5,int n)
{
    if(n==0)
    {
        char temp1[60]="  mmmm    ";
        char temp2[60]=" m\"  \"m ";
        char temp3[60]=" #    #   ";
        char temp4[60]=" #    #   ";
        char temp5[60]="  #mm#    ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==1)
    {
        char temp1[60]=" mmm   ";
        char temp2[60]="   #   ";
        char temp3[60]="   #   ";
        char temp4[60]="   #   ";
        char temp5[60]=" mm#mm ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==2)
    {
        char temp1[60]="  mmmm    ";
        char temp2[60]=" \"   \"# ";
        char temp3[60]="    m\"   ";
        char temp4[60]="   m\     ";
        char temp5[60]=" m#mmmm   ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==3)
    {
        char temp1[60]="  mmmm   ";
        char temp2[60]=" \"   \"# ";
        char temp3[60]="   mmm\" ";
        char temp4[60]="     \"# ";
        char temp5[60]=" #mmm#   ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==4)
    {
        char temp1[60]="    mm  ";
        char temp2[60]="   m\"# ";
        char temp3[60]="  #\" # " ;
        char temp4[60]=" #mmm#m ";
        char temp5[60]="     #  ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==5)
    {
        char temp1[60]=" mmmmm      ";
        char temp2[60]=" #  \       ";
        char temp3[60]=" \"\"\"\"mm ";
        char temp4[60]="      #     ";
        char temp5[60]=" \"mmm#\"   ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==6)
    {
        char temp1[60]="   mmm    ";
        char temp2[60]=" m\"     ";
        char temp3[60]=" #m\"\"#m ";
        char temp4[60]=" #    #   ";
        char temp5[60]="  #mm#\"  ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==7)
    {
        char temp1[60]="mmmmmm  ";
        char temp2[60]="    #\" ";
        char temp3[60]="   m\"  ";
        char temp4[60]="  m\"   ";
        char temp5[60]=" m\"    ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==8)
    {
        char temp1[60]="  mmmm    ";
        char temp2[60]=" #    #   ";
        char temp3[60]=" \"mmmm\" ";
        char temp4[60]=" #   \"#  ";
        char temp5[60]=" \"#mmm\" ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==9)
    {
        char temp1[60]="  mmmm     ";
        char temp2[60]=" #\"  \"m  ";
        char temp3[60]=" #m  m#    ";
        char temp4[60]="  \"\"\" # ";
        char temp5[60]=" \"mmm\"  ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }

}

void out(int n)
{
    int len;
    len=length(n);
    char help1[4]=" ";
    char help2[4]="  ";
    char help3[4]="   ";
    char help4[4]="    ";
    char curr_str1[60];
    char curr_str2[60];
    char curr_str3[60];
    char curr_str4[60];
    char curr_str5[60];
    char str1[60]="";
    char str2[60]="";
    char str3[60]="";
    char str4[60]="";
    char str5[60]="";
    /*strcat(str2,help2);
    strcat(str3,help1);
    strcat(str4,help4);
    strcat(str5,help1);*/
    for(int j=0; j<=len; j++)
    {
        len--;
        design(curr_str1,curr_str2,curr_str3,curr_str4,curr_str5,n/power(10,len));
        // for generalizing the digits
        strcat(str1,curr_str1);
        strcat(str2,curr_str2);
        strcat(str3,curr_str3);
        strcat(str4,curr_str4);
        strcat(str5,curr_str5);
        //  extra space for alignment
        if(n>89)
        {
            strcat(str2,help2);
            strcat(str4,help3);
            strcat(str5,help2);
            strcat(str5,help1);
        }
        else if(n>79)
        {
            strcat(str3,help2);
            strcat(str4,help1);
            strcat(str5,help2);
        }
        else if(n>69)
        {
            strcat(str2,help1);
            strcat(str3,help1);
            strcat(str4,help1);
            strcat(str5,help1);
        }
        else if(n>59)
        {
            strcat(str2,help2);
            strcat(str3,help2);
            strcat(str5,help1);
        }
        else if(n>49)
        {
            strcat(str2,help1);
            strcat(str3,help3);
            strcat(str3,help1);
            strcat(str5,help2);
        }
        else if(n>39)
        {
            strcat(str2,help1);
            strcat(str3,help1);
        }
        else if(n>29)
        {
            strcat(str2,help1);
            strcat(str3,help1);
            strcat(str4,help1);
        }
        else if(n>19)
        {
            strcat(str2,help1);
            strcat(str2,help1);
            strcat(str3,help1);
            strcat(str4,help1);
        }
        n=n-(n/power(10,len))*(power(10,len));
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t__    __                             ____                                                 ");
    printf("%s",str1);
    printf("\n\t\\ \\  / /  ____    _   _    _ __     / ___|    ___    ____     _ __    ___                 ");
    printf("%s",str2);
    printf("\n\t \\ \\/ /  / __ \\  | | | |  | \'__|    \\___ \\   / __|  / __ \\   | \'__|  / _ \\                ");
    printf("%s",str3);
    printf("\n\t  |  |  | (__) | | |_| |  | |        ___) | | (__  | (__) |  | |    |  __/                ");
    printf("%s",str4);
    printf("\n\t  |__|   \\____/   \\__,_|  |_|       |____/   \\___|  \\____/   |_|     \\___|                ");
    printf("%s",str5);
    printf("\n\n\n\n\n\n\n\n");
    // COLOR
    int x=0;
    while(!kbhit())
    {
        delay(100);
        if(x==0)
            system("COLOR 3B");
        else
            system("COLOR 72");
        x=1-x;
    }
}

int main()
{
    int counter=0;
    char load[51]="                                                  ";
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
    for(int i=1;i<=100;i++)
    {
        system("CLS");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t   __________________________________________________");
        printf("\n\t\t\t\tLOADING\t  |%s|",load);
        if(i%2==0)
            load[counter]=35;
        counter++;
    }
    system("CLS");
    system("COLOR 01");
    int n=0,location,flag=0;
    struct pattern* node;
    node=(struct pattern*)malloc(6*sizeof(struct pattern));
    char check1[30]=" __________";
    char check2[30]="| ** ** ** |";
    char check3[30]="|___*__*___|";
    srand ( time(NULL) );     //   TO completely generate random numbers {new numbers when program runs again}
    for(int i=0; i<5; i++)
    {
        select_check(check1,check2,check3,n);
        select_check((node+i)->str1,(node+i)->str2,(node+i)->str3,n);
    }
    //  manually initializing last block

    last_block((node+5)->str1,(node+5)->str2,(node+5)->str3);

    while(1)
    {
        system("CLS");
        printf("\n\t\t\t\t  S . S .  P .  S     GAME\t\t\t\t\t\" FOUNDER cum IMPLEMENTER - @man");
        printf("\n\t\t\t\tsame_same_puppy_same\t\t\t\t\t\t\tCO-FOUNDER - FAUZ \"");
        printf("\n\t\t---------------------------------------------------------------------------------------------------------------");
        printf("\n\tRULES:\tYou have to maximize your score by matching the list elements with the matcher ");
        printf("\n\t\t\tINPUT 1- block of ****stars");
        printf("\n\t\t\tINPUT 2- block of ////blades");
        printf("\n\t\t\tINPUT 3- block of ++++addition");
        printf("\n\t\t\tINPUT 0- random block ");
        printf("\n\t\t\tINPUT -ve - to end program");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t SCORE:\t%d\n",score);
        printf("\n\t\tLOCATION\t      1\t\t     2\t\t     3\t\t\t\t\t%s",check1);
        printf("\n\t\t\t\t       \t\t      \t\t      \t\t\tMATCHER  ->     %s",check2);
        printf("\n\t\t\t\t      |\t\t     |\t\t     |\t\t\t\t\t%s",check3);
        printf("\n\t\t\t\t      V\t\t     V\t\t     V");
        printf("\n\t\t");
        for(int i=0; i<=5; i++)
        {
            printf("\t%s",(node+i)->str1);
        }
        printf("\n\tLIST  ->   ");
        for(int i=0; i<=5; i++)
        {
            printf("\t%s",(node+i)->str2);
        }
        printf("\n\t\t");
        for(int i=0; i<=5; i++)
        {
            printf("\t%s",(node+i)->str3);
        }
        if(flag==1)
            printf("\n\t ERROR:\t Please enter valid value");
        flag=0;
        printf("\n\n\n\tINPUT LOCATION:\t");
        scanf("%d",&location);
        if(location<0)
        {
            out(score);
            break;
        }
        if(location>3)
        {
            flag=1;
            continue;
        }
        if(location==0)
            n=0;
        else
        {
            printf("\n\n\tINPUT TYPE:\t");
            scanf("%d",&n);
            if(n<0||n>3)
            {
                flag=1;
                continue;
            }
        }

        for(int i=5; i>n; i--)
        {
            strcpy((node+i)->str1,(node+i-1)->str1);
            strcpy((node+i)->str2,(node+i-1)->str2);
            strcpy((node+i)->str3,(node+i-1)->str3);
        }
        select_check((node+location)->str1,(node+location)->str2,(node+location)->str3,n);

//  SCORING
        count_score(check1,check2,check3,node);
    }
    free(node);
    return 0;
}
