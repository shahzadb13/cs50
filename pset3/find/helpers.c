/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <stdio.h>       
#include <cs50.h>
#include <string.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int start= 0;
    int end = n-1;
    
    while (start<=end)
    {
        int mid=(start+end)/2;
        if (values[mid]==value){
            return true;
            printf("found %d\n",value);
            break;
        }
    else if (value > values[mid])
    {
        start=mid+1;
        
        
    }
    else
    {
        end=mid-1;
        
    }
    }
    
    
       return false;
    
  
  
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
       
        if(values[j]>values[j+1]){
        int temp=values[j];
        values[j]=values[j+1];
        values[j+1]=temp;
    
        
             }
           
        }
    }
    
}


