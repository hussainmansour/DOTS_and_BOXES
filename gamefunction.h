#ifndef GAMEFUNCTION_H_INCLUDED
#define GAMEFUNCTION_H_INCLUDED
#include "printgame.h"
#include "scannum.h"
#include"check_boxes.h"
#include<time.h>
#include"undo.h"

int gameloop(int nb,int mode,int size,char gamearr[size][size],int totallines,int nofmoves,int *score1,int *score2, int moves1, int moves2,char name1[],char name2[],int gamer,int movesplayed[totallines][7])
{   time_t t1 =time(0);int noundo;  //30/12/2021
    //initializing the arrays of complete game
    int j, i,availablemove=1;
    char h = 205, v = 186, dot = 254;  //205 186 254
    char compgame[size][size];
    for(j=0; j < size; j++)
    {
        compgame[0][j] = j;
        compgame[j][0] = j;
        if(j%2 != 0)
        {
            for(i=1; i < size; i=i+2)
            {
                compgame[i][j] = dot;
                compgame[i+1][j] =v;
            }
        }
        else if(j%2 == 0)
        {
            for(i=1; i < size; i = i+2)
            {
                compgame[i][j] = h;
                compgame[i+1][j] =' ';
            }
        }
    }

    int row,col,gameon=1,check=0 ;
    printgrid(size,gamearr,name1,name2,moves1,moves2,*score1,*score2,totallines,nofmoves,t1);
    while(gameon)
    {
        printf("\n\n\tenter number of row and column by hexadecimal digits\nenter 0, 0 for undo\t1, 1 for redo\t 2, 2 for save\t 3, 3 for main menu\n");

        if(gamer==1)
            SetColor(Blue);
        else
            SetColor(Red);
        printf("\n\tplayer %d's turn\n\n",gamer);

        if(gamer==2 && mode == 1) //computer turn function
        {

        }
        else
        {
            if(gamer==1)
            {
                SetColor(Blue);
            }
            else
            {
                SetColor(Red);
            }
            printf("\tENTER ROW: ");
            row = readint();
            printf(("\tENTER COL: "));
            col = readint();
        }

        SetColor(White);
        system("cls");

        if(row==0 && col==0)  //function of undo

        {
           undo ( &row, &col,&noundo,totallines,movesplayed,size ,gamearr,&moves1,&moves2,&nofmoves,score1,score2,&gamer , mode );//30/12/2021

        }
        else if(row == 2 && col == 2)
        {
            //save game


        }
        else if (row == 3 && col == 3) //if user want to return to main menu
        {
            gamer =0;
            return gamer;
        }

        else if( row > 0 && row < size && col > 0 && col < size )
        {


            if(compgame[row][col] == h || compgame[row][col] == v || (row == 1 && col == 1))
            {
                if (row == 1 && col == 1)  //for redo
                {
                      if (noundo>0)
                      {
                           row =movesplayed[nofmoves][0];
                           col=movesplayed[nofmoves][1];
                           gamer=movesplayed[nofmoves][2];
                           noundo--;
                      }else{printf("there is no moves to redo ");
                      printgrid(size,gamearr,name1,name2,moves1,moves2,*score1,*score2,totallines,nofmoves,t1);
                      continue;

                      }
                }

                //check if we played this move before
                for(i=0; i < nofmoves; i++)
                {
                    if(row == movesplayed[i][0] && col == movesplayed[i][1])
                    {
                        availablemove = 0;
                        printf("\nnot available move\n\n");
                        break;
                    }
                }

                if(availablemove)
                {
                    gamearr[row][col]=compgame[row][col];
                    movesplayed[nofmoves][0]=row;
                    movesplayed[nofmoves][1]=col;
                    movesplayed[nofmoves][2]=gamer;
                    if(gamer == 1)
                        moves1++;
                    else
                        moves2++;
                    nofmoves++;


                    //check=checkbox();    //function
                   check=checkboxes ( row, col, size,compgame, gamearr, gamer,totallines,movesplayed,nofmoves);

                    if(check)
                    {
                        if(gamer == 1)
                            *score1 += check;
                        else
                            *score2 += check;


                    }
                    else
                    {
                        if(gamer==1)
                            gamer=2;
                        else
                            gamer=1;
                    }

                }
                else
                    availablemove = 1;
            }
            else
                printf("\nnot available move\n\n");

        }
        else
            printf("\nnot available move\n\n");

        printgrid(size,gamearr,name1,name2,moves1,moves2,*score1,*score2,totallines,nofmoves,t1);

        if(nofmoves == totallines)  //end the game
        {
            gameon = 0;
            printf("\n\n\t\t\t\t END GAME\n\n");
            if(*score1 > *score2)
            {
                SetColor(Blue);
                printf("congratulation %s you are win", name1);
                SetColor(Green);
                gamer = 1;
            }
            else if(*score2 > *score1)
            {
                SetColor(Red);
                printf("congratulation %s you are win", name2);
                SetColor(Green);
                gamer = 2;
            }
            else
            {
                printf("Tie Game");
                gamer = 0;
            }
            return gamer;
        }

    }

}














#endif // GAMEFUNCTION_H_INCLUDED
