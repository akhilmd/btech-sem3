// Datatype of the elements of data array
typedef int AL_ELEM_TYPE;

// Structure to hold all attributes of a given list
typedef struct ArrayList
{
	// Number of elemnts in the data array
    int length;

    // Maximum number of elements in the data array
    int max_length;

    // pointer to elements
    AL_ELEM_TYPE* data;
} ArrayList;

/*
* Allocate memory for the list variable and initialize
* the attributes of the list. The max_length is also set here.
*/
ArrayList* al_init(int);

// Insert a given element to the end of the data array
void al_insert_end(ArrayList*, AL_ELEM_TYPE);

// Insert a given element to the front of the data array
void al_insert_front(ArrayList*, AL_ELEM_TYPE);

// Insert a given element at a specific position in the data array
void al_insert_at(ArrayList*, AL_ELEM_TYPE, int);

// Delete element from the front of the data array
void al_delete_front(ArrayList*);

// Delete element from the end of the data array
void al_delete_end(ArrayList*);

// Delete element at a specific position
void al_delete_at(ArrayList*, int);

// Delete element based on the value it has
void al_delete_with_val(ArrayList*, AL_ELEM_TYPE);

// Reverse the elements of the data array
void al_reverse(ArrayList*);

// Display all elements in the array with a prefix message
void al_display(ArrayList*, char*);
