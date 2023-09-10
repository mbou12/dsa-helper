#include <stdlib.h>

/* TODO: 
       1. error handling instead of returning null
       2. see if you can use macros to alias a function name (push/enqueue)
       3. valgrind / test
*/

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    int size; 
    node* head;
    node* tail;
} SLL;

// external
SLL init();
void push(SLL* ll, int value);
void prepend(SLL* ll, int value);
void insert_at(SLL* ll, int value, int index);
int get_at(SLL* ll, int index);
int dequeue(SLL* ll);                   // removes head
int pop(SLL* ll);                       // removes tail
int remove(SLL* ll, int value);
int remove_at(SLL* ll, int index);

// local
node init_node(int value);
void free_node(node* n);
node* get(SLL* ll, int value);          // useless function atm

node init_node(int value) {
    node n;
    n.value = value;
    n.next = NULL;
    return n;
}

void free_node(node* n) {
    n->next = NULL;
    free(n);
}

SLL init() {
    SLL ll; 
    ll.size = 0;
    ll.head = NULL;
    ll.tail = NULL;
    return ll;
}

void push(SLL* ll, int value) {
    node n = init_node(value);

    if (ll->size == 0) {
        ll->head = &n;
        ll->tail = &n;
    } else {
        ll->tail->next = &n;
        ll->tail = &n;
    }

    ll->size++;
}

void prepend(SLL* ll, int value) {
    node n = init_node(value);

    if (ll->size == 0) {
        ll->head = &n;    
        ll->tail = &n;
    } else {
        n.next = ll->head;
        ll->head = &n;
    }

    ll->size++;
}

void insert_at(SLL* ll, int value, int index) {
    node n = init_node(value);

    if (index >= ll->size) {
        // throw : index out of bounds
        return; 
    } else if (index == ll->size) {
        push(ll, value);
        return;
    } else if (index == 0) {
        prepend(ll, value);
        return;
    }

    node* cur = ll->head;
    for (int i = 0; i < index; i++)
        cur = cur->next;

    node* temp = cur->next;
    cur->next = &n;
    n.next = temp;
    ll->size++;
}

node* get(SLL* ll, int value) {
    if (ll->size == 0) {
        // throw : index out of bounds (empty arr)
        return NULL;
    } 

    node* cur = ll->head;
    for (int i = 0; i < ll->size; i++)
        if (cur->value == value) 
            return cur;

    // throw : element not found
    return NULL;
}

int get_at(SLL* ll, int index) {
    if (ll->size == 0) {
        // throw : index out of bounds (empty arr)
        return NULL;
    } else if (index >= ll->size) {
        // throw : index out of bounds
        return NULL;
    }

    node* cur = ll->head;
    for (int i = 0; i < index; i++)
        cur = cur->next;

    return cur->value;
}

int dequeue(SLL* ll) {
    if (ll->size == 0)
        // throw
        return NULL;

    node* temp = ll->head;
    int val = temp->value;
    ll->head = temp->next;
    free_node(temp);
    ll->size--;
    return val;
}

int pop(SLL* ll) {
    node* temp = ll->tail;

    if (ll->size == 0) {
        // throw : index out of bounds (empty arr)
        return NULL;
    } else if (ll->size == 1) {
        ll->head = NULL;
    } 

    int val = ll->tail->value;
    free_node(temp);
    ll->size--;
    return val;
}

int remove(SLL* ll, int value) {
    if (ll->size == 0) {
        // throw : index out of bounds (empty arr)
        return NULL;
    } 

    node* cur = ll->head;
    node* prev = ll->head;
    for (int i = 0; i < ll->size; i++) {
        if (cur->value == value) 
            break;
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        // throw : element not found
        return NULL;
    }

    int val = cur->value;
    prev->next = cur->next;

    if (cur == ll->head)
        ll->head = cur->next;
    if (cur == ll->tail)
        ll->tail = prev;

    free_node(cur);
    ll->size--;

    return val;
}

int remove_at(SLL* ll, int index) {
    if (ll->size == 0)
        // throw : index out of bounds (empty arr)
        return NULL;
    else if (index >= ll->size)
        // throw : index out of bounds
        return NULL;
    else if (index == 0)
        return dequeue(ll);
    else if (index == ll->size-1)
        return pop(ll);

    node* cur = ll->head;
    node* prev = ll->head;
    for (int i = 0; i < index; i++) {
        prev = cur;
        cur = cur->next;
    }

    int val = cur->value;
    prev->next = cur->next;
    free_node(cur);
    ll->size--;

    return val;
}
