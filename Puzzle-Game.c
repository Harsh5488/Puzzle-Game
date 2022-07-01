#include<stdio.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int,int);                                           //Function for going to a specific point
void Restart(int [4][4]);                                       //Function for resetting the game

int main()
{
    int i,j,counter=0,temp,a=3,b=3;
    char ch;
    int arr[4][4]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,0};      //4x4 array for storing numbers
    while(1)
    {
        system("cls");                                          //clearing screen for every iteration
        printf("\n\t\tPuzzle Game %c\n",16);
        printf("\n\t* Arrange the Numbers in ascending order"); //Instructions
        printf("\n\t* Use the Arrow keys to move");
        printf("\n\t  %c Move up        %c Move down",24,25);
        printf("\n\t  %c Move Right     %c Move Left",26,27);
        printf("\n\t* Press Escape (ESC) to quit!");
        printf("\n\t* Press R or r to restart");
        printf("\n");
        for(i=0;i<=3;i++)
        {
            printf("\n\n\t\t");
            for(j=0;j<=3;j++)
            {
                if(arr[i][j]==0)
                    printf("%4c  ",32);
                else
                    printf("%4d  ",arr[i][j]);
            }
        }
        printf("\n\n\t\t");
        printf("Moves = %d",counter);
        printf("\n\n");
        ch=_getch();
        switch(ch)
        {
        case 72://up
            if(a==0)
                break;
            else
            {
                temp=arr[a][b];
                arr[a][b]=arr[a-1][b];
                arr[a-1][b]=temp;
                counter++;
                a--;
                break;
            }
        case 80://down
            if(a==3)
                break;
            else
            {
                temp=arr[a][b];
                arr[a][b]=arr[a+1][b];
                arr[a+1][b]=temp;
                counter++;
                a++;
                break;
            }
        case 75://left
            if(b==0)
                break;
            else
            {
                temp=arr[a][b-1];
                arr[a][b-1]=arr[a][b];
                arr[a][b]=temp;
                counter++;
                b--;
                break;
            }
        case 77://right
            if(b==3)
                break;
            else
            {
                temp=arr[a][b];
                arr[a][b]=arr[a][b+1];
                arr[a][b+1]=temp;
                counter++;
                b++;
                break;
            }
        case 82://Capital R
        case 114://Small r
            Restart(arr);
            a=3;
            b=3;
            counter=0;
            break;
        case 27:
            exit(0);
        }
    }
    return 0;
}
void gotoxy(int x,int y)                                        //Definition of Gotoxy function
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Restart(int A[4][4])                                       //Resets the game
{
    int i,j;
    int temp[4][4]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,0};
    for(i=0;i<=3;i++)
        for(j=0;j<=3;j++)
            A[i][j]=temp[i][j];
}
