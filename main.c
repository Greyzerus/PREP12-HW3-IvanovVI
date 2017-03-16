#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "WordList.h"
#include "mylist.h"


int main(int argc, char* argv[])
{
	if (argc != 3)
    {
        fprintf (stderr, "Not enough or too much args\n");
        return -1;
    }
    FILE* srcfile = fopen ((char*)argv[1], "r");
    if (srcfile == NULL)
    {
        fprintf (stderr, "Error at opening file from 1st argue\n");
        return -1;
    }
    List* list_ptr;
    list_ptr = set_WordList_from_file (srcfile);
    if (list_ptr == NULL)   return -2;
    if (fclose (srcfile) != 0)
        fprintf (stderr, "Error at closing file from 1st  arg\n");
    srcfile = NULL;
    FILE* dstfile = fopen ((char*)argv[2], "w");
    if (dstfile == NULL)
    {
        fprintf (stderr, "Error at opening file from 2nd  arg\n");
        return -3;
    }
    save_WordList_into_file (dstfile, &list_ptr);
    if (fclose (dstfile) != 0)
        fprintf (stderr, "Error at closing file from 2nd  arg\n");
    dstfile = NULL;
    return 0;
}

