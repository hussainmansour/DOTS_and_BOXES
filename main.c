#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
        printf("\n\t\t\t Hope To Enjoy\n\n \t\t\t DOTES AND BOXES GAME\n\n\n\n");         // √‰« ⁄œ·  «·Õ … œÌ
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

        FILE *userread =fopen("s.txt","r") ;
        fseek(userread,0,SEEK_END);
        int sz_userread = ftell(userread);
        fseek(userread,0,SEEK_SET);
        int q =0 ;
        while(usersarray[q].namelen!=0||q<sz_userread)
        {
        fread(&usersarray[q].namelen,sizeof(int),1,userread);
        fread(usersarray[q].name,sizeof(char),usersarray[q].namelen,userread);
        fread(&usersarray[q].score,sizeof(int),1,userread);
        q++;
        }
        fclose(userread);
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
            one.lenname=strlen(one.name);
            if(mode==2)
            {
                printf(" \n enter the second name: ");
                gets(two.name);
                strlwr(two.name);
                two.lenname=strlen(two.name);
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

            gamer = gameloop(nb,mode,size,gamearr,totallines,nofmoves,&one.score,&two.score,one.moves,two.moves,one.lenname,one.name,two.lenname,two.name,gamer,movesplayed);



        }




        else if(menu==2)   //for load game
        {
            int s_n ;
            printf("select one of these files(1,2,3):\n");
            s_n = readint();
            if (s_n==1||s_n==2||s_n==3)
            {
                system("cls");
                char fname[5];
                sprintf(fname,"%d.txt",s_n);
                FILE *load =fopen(fname,"r");
                if (load ==NULL)
                {
                    printf("there is no existing file \n");

                }
                else
                {
                    fseek(load,0,SEEK_END);
                    int fsize = ftell(load);
                    if (fsize == 0)
                    {
                        fclose (load);
                        printf("file is empty\n");
                        char runkey;
                        scanf("%c", &runkey);
                        continue;
                    }
                    else
                    {
                        fclose(load);
                        load=fopen(fname,"r");

                    }

                    fread(&nb, sizeof(int), 1, load);
                    fread(&mode, sizeof(int), 1, load);

                    int size = 2 * nb +2, totallines = 2*nb*(nb+1), nofmoves;
                    fread(&nofmoves,  sizeof(int), 1, load);
                    fread(&one.moves, sizeof(int), 1, load);
                    fread(&two.moves, sizeof(int), 1, load);
                    fread(&one.score, sizeof(int), 1, load);
                    fread(&two.score, sizeof(int), 1, load);
                    fread(&gamer,     sizeof(int), 1, load);

                    int movesplayed[totallines][7];
                    fread(movesplayed, sizeof(int), totallines * 7, load);

                    char gamearr[size][size];
                    fread(gamearr, sizeof(char), size * size, load);

                    fread(&one.lenname, sizeof(int), 1, load);
                    fread(one.name, sizeof(char), one.lenname, load);
                    one.name[one.lenname] = '\0';
                    //we do not save computer if mode = 1
                    if(mode == 2)
                    {
                        fread(&two.lenname, sizeof(int), 1, load);
                        fread(two.name, sizeof(char), two.lenname, load);
                        two.name[two.lenname] = '\0';
                    }
                    fclose(load);
                    if (mode == 1)
                    {
                        strcpy(two.name, "computer");
                    }
                    two.lenname = strlen(two.name);
                    gamer = gameloop(nb,mode,size,gamearr,totallines,nofmoves,&one.score,&two.score,one.moves,two.moves,one.lenname,one.name,two.lenname,two.name,gamer,movesplayed);
                }


            }
            else
            {
                // if he enters wrong number
                printf("there is no existing file \n");


            }
        }
        if(menu == 1 || menu == 2)
        {
            if (gamer == 1)
            {
                int i = 0, m = 0,nfound=1;
                for(i=0; i<50; i++)      //check if he played before
                {
                    if(strcmp(one.name,usersarray[i].name) == 0)
                    {
                        m = 1;
                        break;
                    }

                }
                if (m)
                {
                    //if he played before choose the bigger score
                    if(usersarray[i].score < one.score)
                    {
                        usersarray[i].score = one.score;
                    }
                }
                else
                {
                    for(int k =0; k<50; k++)
                    {

                        if(usersarray[k].score==0)
                        {
                            nfound=0;
                            usersarray[k].namelen = one.lenname;
                            strcpy(usersarray[k].name,one.name);
                            usersarray[k].score = one.score;
                            break;
                        }
                    }
                    if(nfound)
                    {
                        for(int k=0; k<50; k++)
                        {

                            if(usersarray[k].score < one.score)
                            {
                                usersarray[k].namelen = one.lenname;
                                strcpy(usersarray[k].name,one.name);
                                usersarray[k].score = one.score;
                                break;
                            }

                        }

                    }

                }



            }
            //if the winner is the computer so we will not save it
            else if (gamer == 2 && mode == 2)
            {

                int i = 0, m = 0,nfound=1;
                for(i=0; i<50; i++)      //check if he played before
                {
                    if(strcmp(two.name,usersarray[i].name) == 0)
                    {
                        m = 1;
                        break;
                    }

                }
                if (m)
                {
                    //if he played before choose the bigger score
                    if(usersarray[i].score < two.score)
                    {
                        usersarray[i].score = two.score;
                    }
                }
                else
                {
                    for(int k =0; k<50; k++)
                    {

                        if(usersarray[k].score==0)
                        {
                            nfound=0;
                            usersarray[k].namelen = two.lenname;
                            strcpy(usersarray[k].name,two.name);
                            usersarray[k].score = two.score;
                            break;
                        }
                    }
                    if(nfound)
                    {
                        for(int k=0; k<50; k++)
                        {

                            if(usersarray[k].score < two.score)
                            {
                                usersarray[k].namelen = two.lenname;
                                strcpy(usersarray[k].name,two.name);
                                usersarray[k].score = two.score;
                                break;
                            }

                        }

                    }

                }

            }


            //save it in file.
            FILE *userwrite = fopen("s.txt", "w");
            int counter = 0;
            while(counter < 50 && usersarray[counter].namelen != 0)
            {
                fwrite(&usersarray[counter].namelen, sizeof(int), 1, userwrite);
                fwrite(usersarray[counter].name,sizeof(char), usersarray[counter].namelen, userwrite);
                fwrite(&usersarray[counter].score, sizeof(int), 1, userwrite);
                counter++;
            }
            fclose(userwrite);





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
        else if(menu==3)     //for top ten
        {

            sortusers(usersarray);
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
