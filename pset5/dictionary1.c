#include "dictionary.h" // Defines LENGTH, prototypes and libs.
 
// Defines a node (hash table)
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;
 
/*
 // Description: Hash function. Author: delipity. (2014).
 Trie vs Hashtable. 2016.
 From: reddit web: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
 */
 
int hash_it(const char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(needs_hashing); i < n; i++)
    {
        hash = (hash << 2) ^ needs_hashing[i];
    }
    return hash % HASHTABLE_SIZE;
}
 
// hashtable (array de nodos). Just memory addreses of structs of type "node"
node* hashtable[HASHTABLE_SIZE];
 
// Global var. Init. number of words in dictionary.
unsigned int number_words = 0;
 
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // Word buffer
    char wordBuffer[strlen(word) + 1];
 
    int i;
    for (i = 0; word[i] != '\0'; i++)
    {
        wordBuffer[i] = tolower(word[i]);
    }
   
    // terminate current word
    wordBuffer[i] = '\0';
 
    // create a ptr to iterate through the linked list
    node* ptr = hashtable[hash_it(wordBuffer)];
 
    // transverse through the linked list
    while (ptr != NULL)
    {
 
        // String comparison. If returns 0, word is in dictionary.
        if (strcmp(ptr->word, wordBuffer) == 0)
        {
            // word found
            return true;
        }
        // try next word
        ptr = ptr->next;
 
    }
    // The linked list ptr has reach NULL, word not found
    return false;
 
}
 
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Avoid garbage values.
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
 
    /* Iterate over each WORD! in the dictionary. File I/O functions */
 
    // Opens the dictionary file in read mode.
    FILE* file = fopen(dictionary, "r");
 
    // Checks for NULL
    if (file == NULL)
    {
 
        fclose(file);
        return false;
    }
 
    // Iterate over each word in dictionary.
    while (!feof(file))
    {
   
 
        // Creates a new node by malloc'n memory for each new word
        node* new_node = malloc(sizeof(node));
 
        // Checks if it's a valid mem block
        if (new_node == NULL)
        {
 
            fclose(file);
            printf("Out of heap memory.\n");
            return false;
 
        }
 
        // scans "file" for a str and places into the last argument
        fscanf(file, "%s", new_node->word);
 
        // Initialize the new_node next ptr
        new_node->next = NULL;
 
        // calling our #function on new_node->word will give us the index
        // of a bucket in the hashtable
        int hash_code = hash_it(new_node->word);
       
        /* Pseudocode from: User Kareem.
        http://cs50.stackexchange.com/questions/1989#1989 */
       
 
        /* Keeping the list sorted the first insertion into each linked-list
        should be treated a little bit differently and separately.*/
 
        if (hashtable[hash_code] == NULL) // Si hashtable con ese hash code, #table vacia.
        {  
            // Vincula #hashtable con el nuevo nodo recien creado.
            hashtable[hash_code] = new_node;
 
            // Increment counter for num. of words in the dictionary
            number_words++;
 
        }
       
        // como hashtable[hash_code] esta "llena", debemos crear una linked list
        // y anexarla con el nodo previo de la hashtable.
        else  
        {  
            // create a pointer, named it prev. And set it to NULL.
            node* prev = NULL;
 
            // create a pointer, named it cur. And set it to hashtable[hashvalue]
            node* cur = hashtable[hash_code];
 
            // traverse through the list. "cur" nos indica la posición actual del nodo
            // de la #table, la que tratamos de insertar. Assorting the list with strcmp.
            while(cur != NULL && strcmp(cur->word, new_node->word) > 0)
            {
                //set previous to current
                prev = cur;
               
                //set current to current -> next
                cur = cur->next; // avanza el ptr.
 
            }
 
            /* As we exit this loop, the position of our node
             is between previous and current the three scenarios */
 
            new_node->next = cur;
 
            // insert at the beginning
            if (prev == NULL)
            {
                hashtable[hash_code] = new_node;
 
            }
            // insert in the middle or at the end
            else
            {
                prev->next = new_node;
            }
           
            // sums number of words in the dictionary
            number_words++;
 
        }
 
    }
 
    // close file
    fclose(file);
 
    // return success
    return true;
 
}
 
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // Global var.
    return number_words;
}
 
/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
   
    // Iterate the entire linked list and free each node
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // loop for each linked list in hash table
        node* cursor = hashtable[i];
   
        while (cursor != NULL)
        {
            // create a temp var. that stores the ptr to next elem. in linked list
            node* temp = cursor;
           
            // update current element to point to next element
            cursor = cursor->next;
 
            // free current element
            free(temp);
 
        }
 
    }
 
    return true;
 
}