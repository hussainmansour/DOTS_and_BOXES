void undo (int *row,int *col,int *noundo,int totallines,int movesplayed[totallines][7],int size,char gamearr[size][size],int *moves1,int *moves2,int *nofmoves,int *score1,int *score2,int *gamer,int mode)
{
    int noofmoves=*nofmoves;
    if (noofmoves==0)
    {
        printf("there is no moves to undo");
    }
    else
    {
        if (mode ==2)
        {
            gamearr[movesplayed[noofmoves-1][0]][movesplayed[noofmoves-1][1]]=' '; // remove lines
            if (movesplayed[noofmoves-1][2]==1)
            {
                *moves1-=1;
            }
            else
            {
                *moves2-=1;
            }
            *gamer=movesplayed[noofmoves-1][2];

            if (movesplayed[noofmoves-1][3]!=0)       //check if won
            {
                gamearr[movesplayed[noofmoves-1][3]][movesplayed[noofmoves-1][4]]=' '; // remove the closed box
                if (*gamer==1)
                {
                    *score1-=1;
                }
                else
                {
                    *score2-=1;
                }
            }

            if (movesplayed[noofmoves-1][5]!=0)
            {
                gamearr[movesplayed[noofmoves-1][5]][movesplayed[noofmoves-1][6]]=' ';// remove the closed box
                if (*gamer==1)
                {
                    *score1-=1;
                }
                else
                {
                    *score2-=1;
                }
            }
            *noundo+=1;  //help in redo
            noofmoves-=1;
        }
        else
        {
            while(1)
            {
                if (movesplayed[noofmoves-1][2]==1)  //to go back to your turn again // that won't happen in every time computer will be the last player
                {
                    gamearr[movesplayed[noofmoves-1][0]][movesplayed[noofmoves-1][1]]=' ';    // remove last lines
                    if (movesplayed[noofmoves-1][3]!=0)                                   // check if the last move closed the box
                    {
                        gamearr[movesplayed[noofmoves-1][5]][movesplayed[noofmoves-1][6]]=' '; // remove the box
                        *score1-=1;                                                        //reducing the score
                    }
                    if (movesplayed[noofmoves-1][5]!=0)                                   // check if the last move closed the box
                    {
                        gamearr[movesplayed[noofmoves-1][5]][movesplayed[noofmoves-1][6]]=' ';// remove the box
                        *score1-=1;                                                       //reducing the score
                    }
                    *moves1-=1;
                    *noundo+=1;
                    noofmoves-=1;
                    *gamer=1;
                    break;
                }
                else
                {
                    // removing the computer moves
                    gamearr[movesplayed[noofmoves-1][0]][movesplayed[noofmoves-1][1]]=' ';
                    if (movesplayed[noofmoves-1][3]!=0)
                    {
                        gamearr[movesplayed[noofmoves-1][5]][movesplayed[noofmoves-1][6]]=' ';// remove the box
                        *score2-=1;
                    }
                    if (movesplayed[noofmoves-1][5]!=0)
                    {
                        gamearr[movesplayed[noofmoves-1][5]][movesplayed[noofmoves-1][6]]=' ';// remove the box
                        *score2-=1;
                    }
                    *moves2-=1;
                    noofmoves-=1;
                }

            }
        }
        *nofmoves=noofmoves ;
    }
}


