#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
   string name=GetString();
   printf("%c",toupper(name[0]));
   for(int i=0;i<strlen(name);i++)
   {
      if(isblank(name[i]))
       {
           printf("%c",toupper(name[i+1]));
          
       }

   }
printf("\n");
return 0;
}