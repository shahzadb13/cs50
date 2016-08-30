/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"
#define BUCKETS 27
//integer for counting dict words added
int counter=0;
//struct for hash table
typedef struct tnode
{
    char cword[LENGTH+2];
    struct tnode* next;
}node;
//node pointer array as buckets
node* dic[BUCKETS];

//hash function for hash table
int hash_f(char* word);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
   
 const int currlen=strlen(word);
  
 char cbuffer[LENGTH+1];
 
 for(int i=0;i<currlen;i++)
     {
       cbuffer[i]=tolower(word[i]);
       
     }
 cbuffer[currlen]='\0';
 int cbucket=hash_f(cbuffer);
 node *cursor = dic[cbucket];
 //iterate over the linked list at cbucket
 while(cursor!=NULL)
 {
     //printf("%i %s %s \n",cbucket,cbuffer,cursor->cword);  for debugging purpose
     if(strcmp(cbuffer,cursor->cword)==0)
     {
         return true;
     }
     else
         cursor=cursor->next;
 }
 
  return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE *ptr = fopen(dictionary,"r");
    char buffer[LENGTH+2];
    int bucket;
    //check for availability of dictionary file
    if(ptr==NULL)
    {
        printf("could not open file \n");
        return false;
    }
    else
    {
        //iterate over dic
        while(fgets(buffer,sizeof(buffer),ptr))
        {
            node* temp=malloc(sizeof(node));
            if(temp==NULL)
            {
                fclose(ptr);
                printf("SORRY NO MEMORY FOR TEMP!\n");
                return false;
            }
            buffer[strlen(buffer)-1]='\0'; // for debugging purpose
            strcpy(temp->cword,buffer);
            bucket=hash_f(temp->cword);
            //if no word in that bucket
            if(dic[bucket]==NULL)
            {
                
                temp->next=NULL;
                dic[bucket]=temp;
            }
            //if there is word before
            else
            {
                
                temp->next=dic[bucket]->next;
                dic[bucket]->next=temp;
                
                
            }
            
           
            counter++;
            
        }
    }
    fclose(ptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i=0;i<BUCKETS;i++)
    {
        node* cursor=dic[i];
        while(cursor!=NULL)
        {
            node* temp=cursor;
            cursor=cursor->next;
            free(temp);
        }
    }
    
    return true;
}
//hash function implementation
int hash_f(char* word)
{
    int hash=0;
    if(isalpha(word[0]))
    {
     hash=word[0]-'a';
    }
    else if(word[0]=='\'')
    {
    hash=26;
    }
    hash=hash%BUCKETS;
    return hash;
}