/* This code was written by Dimis Savva, teaching assistant for the course */
/* Data Structures and Programming Techniques */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "HashTableTypes.h"
#include "HashTableInterface.h"

int menu_get_input_file(char * user_filename)
{
  printf("Q: Enter the filename of the input file:\n");
  scanf("%s", user_filename);
  //Works till here
  return 0;
}

int menu_search(Table table)
{
  KeyType key;
  InfoType info;
  printf("Q: Enter the key:\n");
  scanf("%s",  key);
  int pos = HashSearch(table, key);

  return pos;
}

int menu_insert(Table table)
{
  KeyType key;
  InfoType info;

  printf("Q: Enter the key:\n");
  scanf("%s",  key);
  printf("Q: Enter the first value:\n");
  scanf("%d", & info.first);
  printf("Q: Enter the second value:\n");
  scanf("%d", & info.second);


  int pos = HashInsert(table,key,info);
  return pos;
}

int menu_statistics_total_collisions(Table table)
{
  //You have to implement this function, you should also implement the related functionality for HashTable
  //It should return the total collisions measured in HashTable
  int sum = 0;
  for(int i = 0; i < TABLESIZE; i++){
      sum += table[i].Collisions;
  }
  return sum;
}

int menu_statistics_max_collisions(Table table,int * position)
{
  //You have to implement this function, you should also implement the related functionality for HashTable
  //Parameter pos should return (to the caller function) the position of the bucket with the max collisions
  //The function should return the max collisions
  
  int cols[TABLESIZE];
  for(int i = 0; i < TABLESIZE; i++){
    cols[i] = table[i].Collisions;
  }

  int currentMax = 0;
  int currentMaxIndex = 0;
  
  for(int i = 0; i < TABLESIZE; i++){
    if(cols[i] > currentMax){
      currentMax = cols[i];
      currentMaxIndex = i;
    }
  }

  *position = currentMaxIndex;

  return currentMax;
}

int menu_statistics_min_collisions(Table table,int * position)
{
  
  int cols[TABLESIZE];
  for(int i = 0; i < TABLESIZE; i++){
    cols[i] = table[i].Collisions;
  }

  int currentMin = 1000000000;
  int currentMinIndex = 0;
  
  for(int i = 0; i < TABLESIZE; i++){
    if(cols[i] < currentMin){
      currentMin = cols[i];
      currentMinIndex = i;
    }
  }

  *position = currentMinIndex;

  return currentMin;
}



long menu_insert_from_file(char * user_filename,Table table, float* avg){
  /* assumes no word exceeds length of 1023 */
  time_t start = time(NULL);
  FILE *file=fopen(user_filename, "r");
  if (!file){
    printf("ERROR: Error opening file..\n");
    return;
  }
  char *x = (char*)malloc(100 * sizeof(char));
  if(x == NULL){
    printf("ERROR: can't allocate memory");
    return;
  }
  

  int counter = 0;

  while (fscanf(file, "%s", x) > 0) {
    KeyType key=x;
    InfoType info;
    //info.first=0;
    //info.second=0;

    HashInsert(table,key,info);
    counter++;
  }


  time_t end = time(NULL);
  *avg = 1.0 * (end - start) / counter;
  return end - start;
}

void menu_search_from_file(char * user_filename,Table table){
  /* assumes no word exceeds length of 1023 */
  FILE *file=fopen(user_filename, "r");
  if (!file){
    printf("ERROR: Error opening file..\n");
    return;
  }
  char *x = (char*)malloc(100 * sizeof(char));
  if(x == NULL){
    printf("ERROR: can't allocate memory");
    return;
  }

  while (fscanf(file, " %s", x) > 1) {
    //printf("Just read '%d' from file\n", x );
    KeyType key=x;
    InfoType info;
    //info.first=0;
    //info.second=0;

    int pos=HashSearch(table, key);

  }
  return;
}

void menu_print(Table table){
  Print(table);
}

void menu_quit()
{
    printf("INFO: Quiting...Bye!\n");
    fflush(stdin);
    exit(0);
}

int menu(void)
{
    int option;

    printf("\n--------------\nHashTable Menu\n--------------\n");
    printf("1.\tEnter name of input file\n");
    printf("2.\tInsert an element to HashTable\n");
    printf("3.\tSearch for an element with key\n");
    printf("4.\tPrint total collisions\n");
    printf("5.\tPrint max collisions\n");
    printf("6.\tPrint min collisions\n");
    printf("7.\tSearch using all words from file, print total search time\n\n");
    printf("8.\tPrint hash table contents\n");
    printf("0.\tQuit\n\n");
    printf("Q: Make your selection: ");

    while( (scanf(" %d", &option) != 1) /* non-numeric input */
          || (option < 0)               /* number too small */
          || (option > 8))              /* number too large */
    {
      fflush(stdin);                    /* clear bad data from buffer */
      printf("INFO: That selection isn't valid. Please try again.\n\n");
      printf("Q: Your choice? ");
    }
    printf("--------------\n");
    return option;
}
