/*By Muhammad Shahzad Bajwa
Water Program*/

#include <stdio.h>
#include <cs50.h>

int BottlesCalc(int b);
int main()
{
    int bottles=0;  //declaring and defining bottles
    printf("Enter the length of shower in minutes: \n");//prompting the user
    int minutes=GetInt();//taking user value as minutes
    bottles=BottlesCalc(minutes);//changing the value of bottles
    printf("minutes: %i\n",minutes);
    printf("bottles: %i\n",bottles);
    return 0;
}
  int BottlesCalc(int b)
  {
      return b*12;
  }