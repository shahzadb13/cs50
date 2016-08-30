/***
 * Vigenere.c 
 * By Muhammad Shahzad Bajwa
 */



#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,string argv[])

{
      if(argc!=2)
     {
         printf("I want one ALPHABETICAL key!\n");
         return 1;
     }
    string k=argv[1];
    for (int i=0;i<strlen(k);i++)
{
  
    if (isalpha(k[i]))
    {
                        
        }
    
     else
     {
         printf("ALPHABETS PLEASE!\n");
         return 1;
     }
}
int indexkey[strlen(k)];
for (int j=0,nk=strlen(argv[1]);j<nk;j++)
    {
        if(isupper(k[j]))
        {
            indexkey[j]=(int)k[j]-'A';
        }
        else if(islower(k[j]))
        {
            indexkey[j]=(int)k[j]-'a';

        }
    }

 string message=GetString();
 
        for(int i=0,j=0;i<strlen(message);i++)
        {
            int n=strlen(k);
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                     {
                      int c=((((int)(message[i])-'A')+(int)(indexkey[j%n]))%26)+'A';
                    
                        printf("%c",c);
                  
                     }
                  else if(islower(message[i]))
                        {
                        int g=((((int)(message[i])-'a')+(int)(indexkey[j%n]))%26)+'a';
                    
                        printf("%c",g);
                
                        }
            j++;
               
            }
            else
            {
                printf("%c",message[i]);
            }
            
        }
        printf("\n");

  
}