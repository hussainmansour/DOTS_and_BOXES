#ifndef PRINTGAME_H_INCLUDED
#define PRINTGAME_H_INCLUDED
#include<time.h>
void printgrid(int size,char gamearr[size][size],char nameone[],char nametwo[],int movesone,int movestwo,int scoreone,int scoretwo,int totallines,int nofmoves,time_t t1)
{



        printf("\n\t\t\t\t\t ");       //moving the grid to the center of the terminal
        for (int i =1; i<size; i++)
        {
            SetColor(White);
            printf("%x ",gamearr[0][i]);  // printing row of numbers

        }
        printf("\n");
        for (int i =1; i<size ; i++)
        {
            printf("\t\t\t\t\t%x",gamearr[i][0]); // printing column numbers and grid

            for (int j=1; j<size; j++)
            {
                printf("%c",gamearr[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        SetColor(Blue);                                    // information about players
        printf("\n \t player one name:%s ",nameone);
        SetColor(Red);
        printf("\t\tplayer two name:%s\n\n",nametwo);
        SetColor(Blue);
        printf("\tnumber of moves player one:%d",movesone);
        SetColor(Red);
        printf("\tnumber of moves player two :%d\n\n",movestwo);
        SetColor(Blue);
        printf("\tscore player's one=%d",scoreone);
        SetColor(Red);
        printf("\t\t score player's one=%d\n\n",scoretwo);
        SetColor(Yellow);
        printf("\tNumber of remaining lines:%d",totallines-nofmoves);


        time_t t2=time(0);
        double allsec = difftime(t2,t1);
        int min =allsec/60;                             // to get time
        int sec =(int)allsec%60;
        printf("\t\ttime=%.2d:%.2d",min,sec);
        SetColor(White);

    }


#endif // PRINTGAME_H_INCLUDED
