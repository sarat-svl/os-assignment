#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include"arrow.h"
#define DOWN "\033[1B"
#define UP "\033[1A"
int getch(void);

int cursor(void)
{
int j=1;
while(1)
{ 
if(getch()=='\033')
getch();
int v=getch();
if(v=='A')
printf("%s",UP);
else if(v=='B')
printf("%s",DOWN);
else
break;
}
 return 0;
}
int getch(void)
{
 int ch;
 struct termios oldt;
 struct termios newt;
 tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
 newt = oldt; /* copy old settings to new settings */
 newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
 ch = getchar(); /* standard getchar call */
 tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
 return ch; /*return received char */
}
