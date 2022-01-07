int checkboxes (int row,int col,int size,char comp[size][size],char gamearr[size][size],int gamer,int totallines,int movesplayed[totallines][7],int nofmoves)
{
int check=0;
    if (row%2==0)          // vertical
    {
        if (col+2<size)      // right box
        {
            if (gamearr[row][col+2]==comp[row][col+2])
            {
                if (gamearr[row+1][col+1]==comp[row+1][col+1])
                {
                    if (gamearr[row-1][col+1]==comp[row-1][col+1])
                    {
                        if (gamer==1)
                        {
                            gamearr[row][col+1]='A';
                        }
                        else if (gamer==2)
                        {
                            gamearr[row][col+1]='B';
                        }

                        movesplayed[nofmoves-1][3]=row;
                        movesplayed[nofmoves-1][4]=col+1;
                  }
                check++;
                }
            }
        }

        if (col-2>0)      // left box
        {
            if (gamearr[row][col-2]==comp[row][col-2])
            {
                if (gamearr[row+1][col-1]==comp[row+1][col-1])
                {
                    if (gamearr[row-1][col-1]==comp[row-1][col-1])
                    {
                        if (gamer==1)
                        {
                            gamearr[row][col-1]='A';
                        }
                        else if(gamer==2)
                        {
                            gamearr[row][col-1]='B';
                        }

                        movesplayed[nofmoves-1][5]=row;
                        movesplayed[nofmoves-1][6]=col-1;
                    }
                check++;
                }
            }
        }
    }

if(row%2==1)          // horizontal
{
    if (row+2<size)      // down box
    {
        if (gamearr[row+2][col]==comp[row+2][col])
        {
            if (gamearr[row+1][col+1]==comp[row+1][col+1])
            {
                if (gamearr[row+1][col-1]==comp[row+1][col-1])
                {
                    if (gamer==1)
                    {
                        gamearr[row+1][col]='A';
                    }
                    else if(gamer==2)
                    {
                        gamearr[row+1][col]='B';
                    }
                    movesplayed[nofmoves-1][3]=row+1;
                    movesplayed[nofmoves-1][4]=col;
                }
                                check++;

            }
        }
    }

    if (row-2>0)      // up box
    {
        if (gamearr[row-2][col]==comp[row-2][col])
        {
            if (gamearr[row-1][col+1]==comp[row-1][col+1])
            {
                if (gamearr[row-1][col-1]==comp[row-1][col-1])
                {
                    if (gamer==1)
                    {
                        gamearr[row-1][col]='A';
                    }
                    else if(gamer==2)
                    {
                        gamearr[row-1][col]='B';
                    }

                    movesplayed[nofmoves-1][5]=row-1;
                    movesplayed[nofmoves-1][6]=col;
                }
              check++;
            }
        }
    }
}
return check ;
}
