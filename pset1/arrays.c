#include <stdio.h>
#include <cs50.h>
int main()
{
    int key=0;
    int d=0;
    printf("Enter the number");
    d=GetInt();
    int array23[d][d];
    for(int i=0;i<d;i++)
    {
        
        for(int j=0;j<d;j++)
        {
            key++;
            array23[i][j]=(d*d)-key;
            
           
        }
        
        
         
        
    }
    if(d%2==0)
    {
        int temp=0;
        temp=array23[d-1][d-2];
        array23[d-1][d-2]=array23[d-1][d-3];
        array23[d-1][d-3]=temp;
        
    }
for(int i=0;i<d;i++)
    {
        
        for(int j=0;j<d;j++)
        {
            printf("%d ",array23[i][j]);
           
        }
        printf("\n");
        
    }

    
    
}