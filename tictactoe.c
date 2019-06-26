#include <stdio.h>

struct node{
    int i;
    char ch;
}fun();

void play();
int check(char*, char*, int);
struct node fun(char*,int);
void main()
{
    char ch1[1];
    system("COLOR 17");
    again:
    system("cls");
    play();
    printf("\n\n\nPress 1 to play again else press any other key:\n");
    scanf("%s", ch1);
    if(*ch1=='1')
        goto again;
    else
    {
        exit(0);
    }
}
void play(){
    int count=0;
    struct node info;
    char symbols[] = {'1','2','3','4','5','6','7','8','9'};
    show(symbols);
    again:
    info = fun(symbols,count);
    symbols[info.i]=info.ch;
    system("cls");
    show(symbols);
    if(check(symbols,info.ch,count)==1);
    else
    {
       count++;
       goto again;
    }

}
int check(char sym[9], char ch[1], int count)
{
    int i;
    if(sym[0]==ch && sym[1]==ch && sym[2]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    if(sym[3]==ch && sym[4]==ch && sym[5]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    if(sym[6]==ch && sym[7]==ch && sym[8]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    if(sym[0]==ch && sym[3]==ch && sym[6]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    if(sym[1]==ch && sym[4]==ch && sym[7]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    if(sym[2]==ch && sym[5]==ch && sym[8]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    if(sym[0]==ch && sym[4]==ch && sym[8]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    if(sym[2]==ch && sym[4]==ch && sym[6]==ch)
        {
            printf("\n\n%c Won", ch);
            return 1;
        }
    else if(count==8)
    {
        printf("\n\nGame is draw");
        return 1;
    }
    else
        return 0;
}
struct node fun(char sym[9] ,int count){
    char value[1];
    int i;
    struct node info;
    Again:
    if(count%2==0)
        printf("\nEnter your choice X:");
    else
        printf("\nEnter your choice O:");
    scanf("%s", value);
    for(i=0;i<9;i++)
    {
        if(*value==sym[i])
        {
            info.i=i;
            if(count%2==0)
                info.ch='X';
            else
                info.ch='O';
            break;
        }
        else{
            info.i=-1;
            info.ch="";
        }

    }
    if(info.i==-1)
    {
        printf("Invalid input");
        goto Again;
    }
    return info;
}
void show(char sym[9]){
    printf("\t\t\t\t\t\t\t TIC TAC TOE\n");
    printf("\n\n");
    printf("Player 1 Symbol is: X\n");
    printf("Player 2 Symbol is: O");
    printf("\n\t\t\t      |       |      ");
    printf("\n\t\t\t   %c  |   %c   |   %c   ",sym[0],sym[1],sym[2]);
    printf("\n\t\t\t------|-------|------");
    printf("\n\t\t\t   %c  |   %c   |   %c   ",sym[3],sym[4],sym[5]);
    printf("\n\t\t\t------|-------|------");
    printf("\n\t\t\t   %c  |   %c   |   %c   ",sym[6],sym[7],sym[8]);
    printf("\n\t\t\t      |       |      ");
}
