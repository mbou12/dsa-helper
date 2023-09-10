typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    int size; 
    node* head;
    node* tail;
} SLL;

SLL init();
void push(SLL* ll, int value);
void prepend(SLL* ll, int value);
void insert_at(SLL* ll, int value, int index);
int get_at(SLL* ll, int index);
int dequeue(SLL* ll);                   // removes head
int pop(SLL* ll);                       // removes tail
int remove(SLL* ll, int value);
int remove_at(SLL* ll, int index);
