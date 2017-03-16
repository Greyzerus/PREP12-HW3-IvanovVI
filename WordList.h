#ifndef _WORD_LIST_
#define _WORD_LIST

#include "mylist.h"

List* set_WordList_from_file (FILE*);
/*Sets list of words by getting them from file
gets FILE* src returns List* (ptr to List) */

void save_WordList_into_file (FILE*, List**);
/*Save words to list by pushing them into file*/

#endif //_WORD_LIST_
