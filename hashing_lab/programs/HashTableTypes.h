#ifndef __HASHTABLETYPES__
#define __HASHTABLETYPES__
/* This is the file HashTableTypes.h */

//#define TABLESIZE 997   /* 997 is prime */
#define TABLESIZE 41893   /* 41893 is prime */

// #define EmptyKey 0
#define EmptyKey ""

// typedef int KeyType;
typedef char* KeyType;
typedef struct {
           int first;
           int second;   /* two dummy information fields */
        } InfoType;
typedef struct {
           KeyType Key;
           InfoType Info;
         } TableEntry;
typedef TableEntry Table[TABLESIZE];

#endif
