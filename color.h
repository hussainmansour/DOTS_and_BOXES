#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#define Black           0
#define Blue            1
#define Green           2
#define Cyan            3
#define Red             4
#define Magenta         5
#define Brown           6
#define Light Gray      7
#define Dark Gray       8
#define Light Blue      9
#define Light Green     10
#define Light Cyan      11
#define Light Red       12
#define Light Magenta   13
#define Yellow          14
#define White           15

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}





#endif // COLOR_H_INCLUDED
