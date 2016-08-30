/* Mario By Muhammad Shahzad Bajwa
Prints A Pyramid Of Height Specified By the USER*/


#include <stdio.h>
#include <cs50.h>
int main()
{
    int n=0;
    
    do
    {
        printf("Height: \n");
        n=GetInt();
    } while(n>23 || n<0);
    
    
        for(int i=1;i<=n;i++)  //for height
        {
           for(int l=(n-i);l>0;l--)     //for spaces
           {
               printf(" ");
           }
            for(int j=1;j<=(i+1);j++)  //for hashes
            {
                printf("#");
            }
            printf("\n");
        }
    
    return 0;
}