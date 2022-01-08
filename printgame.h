#ifndef PRINTGAME_H_INCLUDED
#define PRINTGAME_H_INCLUDED

void printgrid(int size,char gamearr[size][size],char nameone[],char nametwo[],int movesone,int movestwo,int scoreone,int scoretwo,int totallines,int nofmoves,time_t t1,int movesplayed[totallines][7])
{

    printf("\n\n\t\t\t\t ");       //moving the grid to the center of the terminal
    for (int i =1; i<size; i++)
    {

        SetColor(White);
        printf("%x",gamearr[0][i]);  // printing row of numbers
        printf(" ");
    }
    printf("\n");
    for (int i =1; i<size ; i++)
    {
        printf(" ");
        printf("\t\t\t\t%x",gamearr[i][0]); // printing column numbers and grid
        for (int j=1; j<size; j++)

            if(gamearr[i][j] == 'A')
            {
                SetColor(Blue);
                printf(" %c ", gamearr[i][j]);
            }
            else if(gamearr[i][j] == 'B')
            {
                SetColor(Red);
                printf(" %c ", gamearr[i][j]);
            }
            else if (j%2 == 0)
            {
                for(int c = 0; c < nofmoves; c++)
                {
                    if(movesplayed[c][0] == i && movesplayed[c][1] == j)
                    {
                        if(movesplayed[c][2] == 1) //change the color
                        {
                            SetColor(Blue);
                        }
                        else
                        {
                            SetColor(Red);
                        }
                    }
                }
                printf("%c%c%c",gamearr[i][j],gamearr[i][j],gamearr[i][j]);
                SetColor(White);
            }

            else
            {
                for(int c = 0; c < nofmoves; c++)
                {
                    if(movesplayed[c][0] == i && movesplayed[c][1] == j)
                    {
                        if(movesplayed[c][2] == 1)
                        {
                            SetColor(Blue);
                        }
                        else
                        {
                            SetColor(Red);
                        }
                    }
                }
                printf("%c", gamearr[i][j]);
                SetColor(White);
            }
        printf("\n");
        SetColor(White);
    }
    printf("\n");
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
    printf("\t\t score player's two=%d\n\n",scoretwo);
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
