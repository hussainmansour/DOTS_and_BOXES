#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "color.h"
#include "player info.h"
#include "gamefunction.h"


int main()
{

    while(1)
    {

        system("cls");
        int menu;
        SetColor(Yellow);
        printf("\n\t\t\t Hope To Enjoy\n\n \t\t\t DOTES AND BOXES GAME\n\n\n\n");         // ÃäÇ ÚÏáÊ ÇáÍÊÉ Ïí
        SetColor(Green);
        printf("\t new game (enter:1)\n\n \t load game (enter:2)\n\n \t top ten (enter:3)\n\n \t exit (enter:4)\n\n \t enter your choose :");
        menu=readint();
        system("cls");

        //nb number of box in row
        //mode is for 1 or 2 player
        //player is struct has name,score,move

        int nb,mode,gamer;
        player one,two;
        users usersarray[50] = {0};  //array of struct(name,score)

        if(menu == 1)   //for new game
        {
            SetColor(Cyan);
            printf("\t choose the degree of difficulty\n\n Easy (enter:1):\n\n Medium (enter:2):\n\n Hard (enter:3):\n");

            while(1)   //check the nb boxes 1,2,3
            {
                nb=readint();
                if(nb>0 && nb<4)
                    break;
                else
                    printf("not valid choose\n");

            }

            switch (nb)
            {
            case 1:
                nb = 2;
                break;
            case 2:
                nb = 3;
                break;
            case 3:
                nb = 5;
                break;
            }
            system("cls");
            printf(" \n\n one player(enter:1):\n\n two players(enter:2):\n");

            while(1)   //make sure user enter 1 or 2
            {
                mode= readint();
                if(mode==1||mode==2)
                    break;
                else
                    printf(" not valid enter 1 or 2\n");
            }
            system("cls");

            printf(" enter your name: ");
            gets(one.name);
            strlwr(one.name);
            if(mode==2)
            {
                printf(" \n enter the second name: ");
                gets(two.name);
                strlwr(two.name);
            }
            else
                strcpy(two.name, "computer");

            system("cls");

            int size = 2*nb + 2;  //initialize the game array
            char gamearr[size][size];
            for(int j=0; j < size; j++)
            {
                gamearr[0][j] = j;
                gamearr[j][0] = j;
                if(j%2 != 0)
                {
                    for(int i=1; i < size; i=i+2)
                    {
                        gamearr[i][j] = 254; // ascii code for dot

                        gamearr[i+1][j] =' ';
                    }
                }
                else if(j%2 == 0)
                {
                    for(int i=1; i < size; i = i+2)
                    {
                        gamearr[i][j] =' ';
                        gamearr[i+1][j] =' ';
                    }
                }
            }
            int totallines = 2*nb*(nb+1),nofmoves=0;
            int movesplayed[totallines][7];//movesplayed[row][column][player made this move]
            for(int i=0; i<totallines; i++)
            {
                for(int j=0; j < 7; j++)
                    movesplayed[i][j]=0;
            }

            one.score=0;
            two.score=0;
            one.moves= 0;
            two.moves = 0;
            gamer=1;

            gamer = gameloop(nb,mode,size,gamearr,totallines,nofmoves,&one.score,&two.score,one.moves,two.moves,one.name,two.name,gamer,movesplayed);
            printf("\n\n enter 1 to return to main menu\n enter 2 to exit\n");
            while(1)
            {
                int key;
                key = readint();
                if(key==1)
                    break;
                else if(key ==2)
                    return 0;
            }



        }




        else if(menu==2)   //for load game
        {

        }
        else if(menu==3)     //for top ten
        {
         //   sortusers(usersarray);
            int i,j;
            for(i=0; i<10; i++)
            {
                printf("%d.",i+1);
                for(j=0; usersarray[i].name[j]!='\0'; j++)
                    printf("%c",usersarray[i].name[j]);
                printf("  his score is = %d\n",usersarray[i].score);
            }
            printf("\n press enter to return to main menu\n");
            char returnkey;
            scanf("%c",&returnkey);

        }
        else if(menu==4)  //for exit
        {
            return 0;
        }

        else
        {
            printf("\n not valid choose\n");
            system("pause");
        }

    }

    return 0;
}
