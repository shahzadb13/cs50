#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,string argv[])
{
    int k;
    if (argc ==2)
    {
         k=atoi(argv[1]);
        
         string code=GetString();
            for (int i=0;i<strlen(code);i++)
            {
               if(isalpha(code[i]))
               {
                   if(isupper(code[i]))
                   {
                        int c=((int)code[i]-64)+k;
                        if(c>26){
                            c=c%26;
                            c=c+64;
                            printf("%c",c);
                        }
                        else if (c<26){
                            c=c+64;
                            printf("%c",c);
                        }
                       
                       
                       
                   }
                   else if(islower(code[i]))
                   {
                      int c=((int)code[i]-96)+k; 
                      if(c>26)
                      {
                            c=c%26;
                            c=c+96;
                            printf("%c",c);
                      }
                            else if (c<26)
                            {
                            c=c+96;
                            printf("%c",c);
                            }
                       
                     
                   }
                   
               }
               else if(isdigit(code[i]))
                    {
                        int j=(code[i])-48;
                        
                        
                       printf("%d",j);
                   }
                else if(isblank(code[i]))
                {
                    printf(" ");
                }
                else if(ispunct(code[i])){
                    printf("%c",code[i]);
                }
                }   
                printf("\n");
         
    }
    
    else{    
        printf("I need  one A key!\n");
        return 1;
        }
    
}

