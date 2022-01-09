#ifndef PLAYER_INFO_H_INCLUDED
#define PLAYER_INFO_H_INCLUDED


typedef struct
{
    char name[256];
    int moves;
    int score;
    int lenname ;                     // 8/1/2022
} player;

typedef struct
{
    int namelen;                     // 8/1/2022
    char name[256];
    int score;
} users;



#endif // PLAYER_INFO_H_INCLUDED
