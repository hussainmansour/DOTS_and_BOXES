#ifndef SCANNUM_H_INCLUDED
#define SCANNUM_H_INCLUDED

int readint() //function to read int to avoid errors when entering char it accepts the hexadecimal numbers
{
    char readstr[256];
    int read=0, n;
    int  i, len;
    gets(readstr);
    len = strlen(readstr);
    for(i=0; i < len; i++)
    {
        if(readstr[i] > 47 && readstr[i] < 58)  // 0 - 9
        {
            n = readstr[i]- 48;
        }
        else if (readstr[i] > 96 && readstr[i] < 103)  //a - f         a = 10
        {
            n = readstr[i]- 87;
        }
        else
        {
            return -1;
        }
        read = read*16+ n; //hexadecimal
    }
    return read;
}






#endif // SCANNUM_H_INCLUDED
