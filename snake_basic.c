#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>

struct step
{
    int step;
};

struct food_locations
{
    int x,y;
};

struct snake_locations
{
    int x,y;
};
void delay(int milli_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void food(struct food_locations* ptr)
{
    ptr->x=(rand()%57)+2;
    ptr->y=(rand()%21)+2;
    if(ptr->x>58||ptr->x<1||ptr->y>21||ptr->y<1)
        food(ptr);
}

void which_operation(int n,int* c,int* r)
{
    switch(n)
        {
        case(1):
            *c=*c+1;
            break;
        case(2):
            *c=*c-1;
            break;
        case(3):
            *r=*r-1;
            break;
        case(4):
            *r=*r+1;
            break;
        }
}

int check_tail_cut(struct snake_locations* ptr,int length)
{
    for(int i=0;(i<length-2)&&length>=5;i++)
    {
        if((ptr+i)->x==(ptr+length-1)->x&&(ptr+i)->y==(ptr+length-1)->y)
            return 0;
    }
    return 1;
}

char opposite(char ch)
{
        if(ch==77)
            ch=75;
        else if(ch==75)
            ch=77;
        else if(ch==72)
            ch=80;
        else if(ch==80)
            ch=72;
        return ch;
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
        char temp1[60]="  mmmm  ";//benchmark
        char temp2[60]=" m\"  \"m ";
        char temp3[60]=" #    # ";
        char temp4[60]=" #    # ";
        char temp5[60]="  #mm#  ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==1)
    {
        char temp1[60]=" mmm   ";//benchmark
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
        char temp1[60]="  mmmm  ";//benchmark
        char temp2[60]=" \"   \"# ";
        char temp3[60]="    m\"  ";
        char temp4[60]="  m\"    ";
        char temp5[60]=" m#mmmm ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==3)
    {
        char temp1[60]="  mmmm  ";//benchmark
        char temp2[60]=" \"   \"# ";
        char temp3[60]="   mmm\" ";
        char temp4[60]="     \"# ";
        char temp5[60]=" #mmm#  ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==4)
    {
        char temp1[60]="    mm  ";//benchmark
        char temp2[60]="   m\"#  ";
        char temp3[60]="  #\" #  ";
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
        char temp1[60]=" mmmmm  ";//benchmark
        char temp2[60]=" #      ";
        char temp3[60]=" \"\"\"\"mm ";
        char temp4[60]="      # ";
        char temp5[60]=" \"mmm#\" ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==6)
    {
        char temp1[60]="   mmm  ";//benchmark
        char temp2[60]=" m\"     ";
        char temp3[60]=" #m\"\"#m ";
        char temp4[60]=" #    # ";
        char temp5[60]="  #mm#\" ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==7)
    {
        char temp1[60]="mmmmmm ";//benchmark
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
        char temp1[60]="  mmmm  ";//benchmark
        char temp2[60]=" #    # ";
        char temp3[60]=" \"mmmm\" ";
        char temp4[60]=" #   \"# ";
        char temp5[60]=" \"#mmm\" ";
        strcpy(ptr1,temp1);
        strcpy(ptr2,temp2);
        strcpy(ptr3,temp3);
        strcpy(ptr4,temp4);
        strcpy(ptr5,temp5);
    }
    else if(n==9)
    {
        char temp1[60]="  mmmm  ";//benchmark
        char temp2[60]=" #\"  \"m ";
        char temp3[60]=" #mmmm# ";
        char temp4[60]="      # ";
        char temp5[60]=" \"mmm## ";
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
    //   for bug fixing printing 0
    int bug=0;
    if(n==0)
    {
        char temp1[60]="  mmmm  ";//benchmark
        char temp2[60]=" m\"  \"m ";
        char temp3[60]=" #    # ";
        char temp4[60]=" #    # ";
        char temp5[60]="  #mm#  ";
        strcpy(str1,temp1);
        strcpy(str2,temp2);
        strcpy(str3,temp3);
        strcpy(str4,temp4);
        strcpy(str5,temp5);
        bug=1;
    }
    else if(n>=100)
    {
        system("CLS");
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("\n\t\t\t__    __                   __            __            _   _                        ");printf("%s",str1);
        printf("\n\t\t\t\\ \\  / /  ____    _   _    \\ \\    __    / /   ____    | \\ | |        ");printf("%s",str2);
        printf("\n\t\t\t \\ \\/ /  / __ \\  | | | |    \\ \\  /  \\  / /   / __ \\   |  \\| |   ");printf("%s",str3);
        printf("\n\t\t\t  |  |  | (__) | | |_| |     \\ \\/ /\\ \\/ /   | (__) |  | |\\  |    ");printf("%s",str4);
        printf("\n\t\t\t  |__|   \\____/   \\__,_|      \\__/  \\__/     \\____/   |_| \\_|     ");
        getch();
        getch();
        getch();
        getch();
        return;
    }

    for(int j=0; j<=len&&bug==0; j++)
    {
        len--;
        design(curr_str1,curr_str2,curr_str3,curr_str4,curr_str5,n/power(10,len));
        // for generalizing the digits
        strcat(str1,curr_str1);
        strcat(str2,curr_str2);
        strcat(str3,curr_str3);
        strcat(str4,curr_str4);
        strcat(str5,curr_str5);
        n=n-(n/power(10,len))*(power(10,len));
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t                                                                                ");// benchmark
    printf("\n\t__    __                             ____                                       ");printf("%s",str1);
    printf("\n\t\\ \\  / /  ____    _   _    _ __     / ___|    ___    ____     _ __    ___       ");printf("%s",str2);
    printf("\n\t \\ \\/ /  / __ \\  | | | |  | \'__|    \\___ \\   / __|  / __ \\   | \'__|  / _ \\      ");printf("%s",str3);
    printf("\n\t  |  |  | (__) | | |_| |  | |        ___) | | (__  | (__) |  | |    |  __/      ");printf("%s",str4);
    printf("\n\t  |__|   \\____/   \\__,_|  |_|       |____/   \\___|  \\____/   |_|     \\___|      ");printf("%s",str5);
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

    getch();
    getch();
    getch();
    getch();

}

int main()
{
    //   COUNTER
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

    //  SNAKE  ANIMATION
    int value=1,flag=1;
    while(1)
    {
        char enter_key;
animation_again:
        system("CLS");
        switch(value)
        {
        case(1):
            system("COLOR FB");
            printf("\n\t                    ^                                   ");//benchmark
            printf("\n\t                   //                                   ");
            printf("\n\t                  ( (                                   ");
            printf("\n\t                   \\ \"\\                                 ");
            printf("\n\t                    \"\\ `\"\\                              ");
            printf("\n\t                      \")  \"\\                            ");
            break;
        case(2):
            system("COLOR F3");
            printf("\n\t                     ^                                   ");//benchmark
            printf("\n\t                   / /                                   ");
            printf("\n\t                   | |                                   ");
            printf("\n\t                    \\ \"\\                                 ");
            printf("\n\t                     \\ `\"\\                              ");
            printf("\n\t                      \")  \"\\                            ");
            break;
    case(3):
            system("COLOR FD");
            printf("\n\t                       ^                                   ");//benchmark
            printf("\n\t                      / /                                   ");
            printf("\n\t                      | |                                   ");
            printf("\n\t                      | \"\\                                 ");
            printf("\n\t                      | ` \\                              ");
            printf("\n\t                      |    \\                            ");
            break;
        case(4):
            system("COLOR F1");
            printf("\n\t                          ^                                      ");//benchmark
            printf("\n\t                          \\\\                                   ");
            printf("\n\t                          | |                                   ");
            printf("\n\t                         / \\                                 ");
            printf("\n\t                        / `\\                              ");
            printf("\n\t                      /   \\                            ");
            break;
    case(5):
            system("COLOR F5");
            printf("\n\t                         ^                                      ");//benchmark
            printf("\n\t                          \\\\                                   ");
            printf("\n\t                           ) )                                   ");
            printf("\n\t                          / /                                 ");
            printf("\n\t                        /\"`(                              ");
            printf("\n\t                      /\"  \\                            ");
            break;
        }
        //   calculating value for animation   12345432123454321   want to generate this pattern...
        if(flag==1)
        {
            value++;
            if(value>=5)
                flag=0;
        }
        else
        {
            value--;
            if(value<=1)
                flag=1;
        }

    printf("\n\t                     /\"     \"\\                          ");printf("\t\t\t@copyright   AMAN SHRIVASTAVA");
    printf("\n\t                   /\"         \"\\                        ");
    printf("\n\t                _/\"             \"\\                      ");printf("\t      ____     _   _       _       _  _    _____     ");
    printf("\n\t         ______/_                 \"\\  ________          "); printf("\t     / ___|   | \\ | |     / \\     | |/ /  | ____|    ");
    printf("\n\t        /        \\                 \"\\/        \\         ");printf("\t     \\___ \\   |  \\| |    / _ \\    | \' /   |  _|      ");;
    printf("\n\t      /`   _____  \\                 / _______  `\\       "); printf("\t      ___) |  | |\\  |   / ___ \\   | . \\   | |___     ");
    printf("\n\t    /`   (??????/  \\_______________/  \\??????)   `\\     ");printf("\t     |____/   |_| \\_|  /_/   \\_\\  |_|\\_\\  |_____|    ");
    printf("\n\t  /`      \\????/                       \\????/      `\\   ");printf("\t                                   ");
    printf("\n\t (         \\??/                         \\??/         )  "); printf("\t         ____       _      __  __    _____                  ");
    printf("\n\t  \\         \\/                           \\/         /   ");printf("\t        / ___|     / \\    |  \\/  |  | ____|                  ");
    printf("\n\t   \\     _           ==         ==           _     /    ");  printf("\t       | |  _     / _ \\   | |\\/| |  |  _|               ");
    printf("\n\t    \\    \\`.                               .`/    /     "); printf("\t       | |_| |   / ___ \\  | |  | |  | |___                  ");
    printf("\n\t     \\    \\ \\_.--.         #         .--._/ /    /      ");printf("\t        \\____|  /_/   \\_\\ |_|  |_|  |_____|              ");
    printf("\n\t      \\    \\      \\       / \\       /      /    /       ");
    printf("\n\t       \\    \\      \\     /   \\     /      /    /        ");
    printf("\n\t        \\    \\      \\   /     \\   /      /    /         ");
    printf("\n\t         \\    \\      \\ /       \\ /      /    /          ");
    printf("\n\t          \\    \\      V         V      /    /           ");
    printf("\n\t           \\    \\                     /    /            ");printf("\t PRESS ENTER KEY TO CONTINUE");
    printf("\n\t            \\    \\    /\\       /\\    /    /             ");
    printf("\n\t             \\    \\  /  \\     /  \\  /    /              ");
    printf("\n\t              \\    \\/    \\___/    \\/    /               ");
    printf("\n\t               \"\\                      /\"               ");
    printf("\n\t                 \"\\__________________/\"                 ");

    delay(200);
    while(!kbhit())
        {
            goto animation_again;
        }
        //   asking what to do next
        enter_key=getch();
        if(enter_key==13)
            break;
    }

    system("CLS");
    system("COLOR F0");     //  redefining color

    int after=0;
    //  for tracing location of snake initializing locations
    struct snake_locations* where;
    where=(struct snake_locations*)malloc(sizeof(struct snake_locations));

    //   for recording the movement of snake
    int snake_length=1,skip=0,food_count=1;
    struct step* node;
    node=(struct step*)malloc(sizeof(struct step));
    struct food_locations* food_node;
    food_node=(struct food_locations*)malloc(sizeof(struct food_locations));

    srand(time(NULL));     //   TO completely generate random numbers {new numbers when program runs again}
    int score=0;   //   initializing  score
    //     basic block diagram
    char str[23][70]=
    {
        {"TVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVT"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {">                                                         <"},
        {"|_^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^_|"}
    };

//  initializing head of snake
    int h_r=11,h_c=35,t_r,t_c,n;
    str[h_r][h_c]='@';

//   FOR FOOD
again1_food:
    food(food_node+food_count-1);
    //  test   case
    if((food_node+food_count-1)->x==h_c&&(food_node+food_count-1)->y==h_r)
        goto again1_food;
    str[(food_node+food_count-1)->y][(food_node+food_count-1)->x]='#';

//   Printing  First time
    printf("\n\n\n");
    for(int i=0; i<23; i++)
    {
        printf("\n\t\t\t%s",str[i]);
        if(i==0)
            printf("\t\tSCORE:\t%d",score);
    }
    char ch,previous,oppo;
    ch=getch();
    ch=getch();
    previous=ch;

    //  initially head and tail are same
    t_r=h_r;
    t_c=h_c;

    while(1)
    {
        previous=ch;
        //   calculating what to do
        if(ch==77)
            n=1;
        else if(ch==75)
            n=2;
        else if(ch==72)
            n=3;
        else if(ch==80)
            n=4;
again:
        delay(200);

        //  which operation for head
        which_operation(n,&h_c,&h_r);

        //updating location in array storage
        (where+snake_length-1)->x=h_c;
        (where+snake_length-1)->y=h_r;

        // updating what to do for tail
        (node+snake_length-1)->step=n;

        //  which operation for tail  (implementation)
        if(skip==0)
            str[t_r][t_c]=' ';

        if(skip==0)
            which_operation(node->step,&t_c,&t_r);

        //shifting
        for(int i=0;(i<snake_length-1)&&skip==0;i++)
        {
            (node+i)->step=(node+i+1)->step;
            (where+i)->x=(where+i+1)->x;
            (where+i)->y=(where+i+1)->y;
        }
        if(skip==1)
        {
            snake_length=snake_length+1;
            node=(struct step*)realloc(node,(snake_length)*sizeof(struct step));
            where=(struct snake_locations*)realloc(where,(snake_length)*sizeof(struct snake_locations));
        }
        if(t_c==(food_node)->x&&t_r==(food_node)->y)
            skip=skip+1;

        if(skip==2)
        {
            //   deleting the last food
            for(int i=0;(i<food_count-1);i++)   //      you can simplify this
            {
                (food_node+i)->x=(food_node+i+1)->x;
                (food_node+i)->y=(food_node+i+1)->y;
            }
            food_count=food_count-1;
            food_node=(struct food_locations*)realloc(food_node,food_count*sizeof(struct food_locations));
            skip=0;
        }
        str[h_r][h_c]='@';

        //   checking for tail cut
        if(check_tail_cut(where,snake_length)==0)
        {
            out(score);
            break;
        }

        system("CLS");
        printf("\n\n\n");
        for(int i=0; i<23; i++)
        {
            printf("\n\t\t\t%s",str[i]);
            if(i==0)
                printf("\t\tSCORE:\t%d",score);
        }
// OUT OR NOT
        if(h_r<=0||h_c<=0||h_c>=58||h_r>=22)
        {
            out(score);
            break;
        }

        // new food   +   score  renew

        if((food_node+food_count-1)->x==h_c&&(food_node+food_count-1)->y==h_r)
        {
            score++;
           // (node+snake_length-1)->step=n;
           food_count=food_count+1;
           food_node=(struct food_locations*)realloc(food_node,food_count*sizeof(struct food_locations));
again2_food:
            food(food_node+food_count-1);
        }
        //  test   case
        if((food_node+food_count-1)->x==h_c&&(food_node+food_count-1)->y==h_r)
        goto again2_food;
    str[(food_node+food_count-1)->y][(food_node+food_count-1)->x]='#';

        while(!kbhit())
        {
            goto again;
        }
        //   asking what to do next
        ch=getch();
        ch=getch();
        oppo=opposite(previous);
        if(oppo==ch&&after==1)
            ch=previous;
        after=1;
    }
    free(node);
    free(food_node);
    free(where);
    return 0;
}
