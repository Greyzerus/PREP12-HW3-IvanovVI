#ifndef _MY_LIST_
#define _MY_LIST_

#include <stdlib.h>
#include <stdio.h>


typedef struct MyList {} List;


void push (void* ptr_to_value, List** list_ptr);

void pop (List** list_ptr, void** buf);

#endif //_MY_LIST_
