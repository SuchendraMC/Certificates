#include<stdio.h>
#include<conio.h>
main()
{
enum day {mon=1,tue=2,wed=3,thu=4,fri=5,sat=6,sun=7};
enum day wk_st,wk_end,wk_mid;

clrscr();
wk_st=mon;
wk_end=sun;
wk_mid=thu;

printf("\nDefined by enumerators:\tStarting week_day %d.\n",wk_st);
printf("\nDefined by enumerators:\tMiddle week_day %d.",wk_mid);
printf("\nDefined by enumerators:\tEnding week_day %d.",wk_end);

getch();
}