/* This code is from the book "Data Structures, Algorithms and Software Principles in C" */
/* by Thomas A. Standish */

/* This is the file HashTableImplementation.c */

#include <stdio.h>
#include <stdlib.h>
#include "HashTableInterface.h"

/*
int h(KeyType K)
{
  return K % TABLESIZE;
}

int p(KeyType K)
{
   return 1 > (K / 7) ? 1 : K / 7;
  // return 1;  // You have to implement this function. Currently it returns 1 so it implements open addressing with linear probing 
}
*/


int h(KeyType K) {
   int sum = 0;
   
   for(int i = 0; K[i] != '\0'; i++){

      sum += (int)K[i];
   }

   return sum;
}

int p(KeyType K) {
   int sum = 0;
   
   for(int i = 0; K[i] != '\0'; i++){

      sum += (int)K[i];
   }


   return sum % TABLESIZE;
}

void Initialize(Table T) {
   int i;

   for (i=0; i<TABLESIZE; i++)
      T[i].Key=EmptyKey;
}

int HashInsert(Table T, KeyType K, InfoType I) {
   int i;
   int ProbeDecrement;

   i=h(K);
   ProbeDecrement=p(K);

   while (T[i].Key != EmptyKey){
      i-=ProbeDecrement;
      if (i<0)
        i+=TABLESIZE;
    }
    T[i].Key = (char*)malloc(100 * sizeof(char));
    if(T[i].Key == NULL) {
       printf("ERROR allocating memory");
    }
    for(int j = 0; K[j] != '\0'; j++){
       T[i].Key[j] = K[j];
    }
    T[i].Info=I;
    return i;
}


int HashSearch(Table T, KeyType K) {
   int i;
   int ProbeDecrement;
   KeyType ProbeKey;

   /*Initializations */
   i=h(K);
   ProbeDecrement=p(K);
   ProbeKey=T[i].Key;

   /* Search loop */
   while ((K!=ProbeKey) && (ProbeKey!=EmptyKey)){
      i-=ProbeDecrement;
      if (i<0)
         i+=TABLESIZE;
      ProbeKey=T[i].Key;
   }

   /* Determine success or failure */
   if (ProbeKey==EmptyKey)
      return -1;
   else
      return i;

}

void Print(Table T){
  int i;
  for(i=0;i<TABLESIZE;++i){
      if(T[i].Key == EmptyKey){
        printf("Empty element in position %d\n", i);
      }else{
        printf("Element in position %d with key \"%s\"\n",i,T[i].Key);
      }
    }
}
