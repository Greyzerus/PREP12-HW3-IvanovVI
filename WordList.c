#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mylist.h"

#define BUF_SIZE_DEF 20

int buf_fgetword (FILE* src,char** buf_dest)
{
    char buf_c;
    char* buf = malloc (sizeof (char));
    int buf_size = 1, got_c =0;
    while (!isspace (buf_c = fgetc (src)) && buf_c != EOF)
    {
        if (++got_c == buf_size)
        {
            buf = (char*) realloc (buf, (buf_size+=BUF_SIZE_DEF) * sizeof (char));
            if (buf == NULL)
            {
                fprintf (stderr, "Can't locate %lu bytes of memory\n", buf_size * sizeof (char));
                return (-1);
            }
        }
        buf [got_c - 1] = buf_c;
    }
    if (got_c == 0)
    {
        free (buf);
         if (buf_c != EOF)
        {
             got_c = buf_fgetword (src, buf_dest);
              return got_c;
         }
         else
         {
             buf_dest = NULL;
             return 0;
         }
    }
     buf [got_c] = '\0';
     *buf_dest = buf;
     if (buf_c == EOF)
         return 0;
      return got_c;
}

List* set_WordList_from_file (FILE* src)
{
    List* list_ptr = NULL;
    char *buf = NULL;
    int flag;
    while ( (flag = buf_fgetword (src, &buf)) > 0)
	 {
        if (flag == -1)
            return NULL;
        push (buf, &list_ptr);
        if (list_ptr == NULL)
             return NULL;
    }
    return list_ptr;
}


void save_WordList_into_file (FILE* dst, List** list_ptr)
{
     char* buf=NULL;
     pop(list_ptr, (void**) &buf);
     while (buf != NULL)
      {
             fprintf (dst, "%s ", buf);
             free (buf);
             pop(list_ptr, (void**) &buf);
      }
}
