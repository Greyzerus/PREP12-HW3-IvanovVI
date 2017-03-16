#include <stdlib.h>
#include <stdio.h>

typedef struct MyList {
    void* element;
    struct MyList* list_ptr;
} List;

void push (void* val_ptr, List** list_ptr)
{
	if (val_ptr == NULL)
		return;
	List* new_entry = malloc (sizeof (List));
	if (new_entry == NULL)
	{
		fprintf (stderr, "Can't allocate %u bytes of memory", sizeof (List));
		*list_ptr = NULL;
		return;
	}
	new_entry -> list_ptr = *list_ptr;
	new_entry -> element = val_ptr;
	*list_ptr = new_entry;
}

void pop (List** list_ptr, void** buf)
{
	if (list_ptr == NULL || *list_ptr == NULL)
	{
		*buf = NULL;
		return;
	}
	List* cur = *list_ptr;
	*buf = (*list_ptr) -> element;
	*list_ptr = (*list_ptr) -> list_ptr;
	free (cur);
}
