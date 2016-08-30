/*Greedy By Muhammad Shahzad Bajwa
Determines the least possible coins to be given.
Available Coins: Quartes 25cents
                 Dimes 10cents    
                 Nickels 5cents
                 Pennies 1cent       */

#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main()
{
    int y,counter=0;         //counter to calculate the number of coins used, y for cents after coverting from dollars
    float x;      //x for user input
    do{
    printf("How much amount is owed: \n");   //prompt the user for input
    x=GetFloat();
    }while(x<0);          //checking the validity of the given value
        y=roundf(x*100);     //converting to cents and rounding off
        //Now starting with coins
        
        while(y>=25){      //checking for quarters
            y=y-25;
            counter++;
        }
        while(y<25 && y>=10){        //checking for dimes
            y=y-10;
            counter++;
        }
        while(y<10 && y>=5){          //checking for nickels
            y=y-5;
            counter++;
        }
        while(y<5 && y>=1){            //checking for pennies
            y=y-1;
            counter++;
        }
        printf("%i\n",counter);  //printing the answer
        return 0;
}
