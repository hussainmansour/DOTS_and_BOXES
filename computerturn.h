#ifndef COMPUTERTURN_H_INCLUDED
#define COMPUTERTURN_H_INCLUDED
void compturn(int *row,int *col,int size,char gamearr[size][size],char compgame[size][size],int gamer,int totallines, int nofmoves, int movesplayed[totallines][7], int v, int h, int dot)
{
    int foundmove=0, i1,j1, i, j, check,ai=1;
    for(i=1; i<size; i++)
    {
        for(j=1; j<size; j++)
        {
            if(gamearr[i][j]==' '&&(compgame[i][j]== h ||compgame[i][j]==v))
            {
                gamearr[i][j]=compgame[i][j];
                check=checkboxes(i,j,size,compgame,gamearr,gamer,totallines,movesplayed,nofmoves,ai);
                if(check==1||check==2)        // a move that close a box
                {
                    foundmove=1;
                    break;
                }
                else
                {
                    gamearr[i][j]=' ';
                }
            }
        }
        if(foundmove)
            break;
    }

    if(foundmove==0)
    {

        for(i=1; i<size; i++)
        {
            for(j=1; j<size ; j++)
            {
                if(gamearr[i][j]==' '&&(compgame[i][j]== h ||compgame[i][j]==v)) //try any move
                {
                    gamearr[i][j]=compgame[i][j];
                    int nothelpuser=1, helpuser=0;
                    for(i1=1; i1<size; i1++)
                    {
                        for(j1=1; j1<size; j1++)
                        {
                            if(gamearr[i1][j1]==' '&&(compgame[i1][j1]== h ||compgame[i1][j1]==v)) //try all possibility of any move that the player can made
                            {
                                gamearr[i1][j1]=compgame[i1][j1];
                                check=checkboxes(i1,j1,size,compgame,gamearr,gamer,totallines,movesplayed,nofmoves,ai);
                                if(check==1||check==2)
                                {
                                    gamearr[i][j]=' ';
                                    gamearr[i1][j1]=' ';
                                    helpuser=1;
                                    nothelpuser=0;
                                    break;
                                }
                                else
                                    gamearr[i1][j1]=' ';
                            }
                        }
                        if(helpuser)
                            break;
                    }
                    if(nothelpuser)
                    {
                        foundmove=1;
                        break;
                    }
                }
            }
            if(foundmove)
                break;
        }

    }
    if(foundmove == 0) //choose any valid move as there is no move that get box or not helping player
    {
        int validmove = 0;
        for(i = 1; i < size; i++)
        {
            for(j = 1; j < size; j++)
            {
                if(gamearr[i][j] == ' ' && (compgame[i][j] == h || compgame[i][j]== v))
                {
                    validmove = 1;
                    break;
                }
            }
            if (validmove)
                break;
        }
    }
    *row = i;
    *col = j;
}

#endif // COMPUTERTURN_H_INCLUDED
