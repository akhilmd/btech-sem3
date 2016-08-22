// Datatype of the elements of data array
typedef int TYPE;

typedef struct ArrayList
{
    int length;
    int max_length;
    TYPE* data;
} ArrayList;

ArrayList* al_init(int);
ArrayList* al_insert_end(ArrayList*, TYPE);
ArrayList* al_insert_front(ArrayList*, TYPE);
ArrayList* al_insert_at(ArrayList*, TYPE, int);
ArrayList* al_delete_front(ArrayList*);
ArrayList* al_delete_end(ArrayList*);
ArrayList* al_delete_at(ArrayList*, int);
ArrayList* al_delete_with_val(ArrayList*, TYPE);
ArrayList* al_reverse(ArrayList*);
void al_display(ArrayList*, char*);
