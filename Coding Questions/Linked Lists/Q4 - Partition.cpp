/*                                      SOLUTION 1

    
*/

using namespace std;

typedef struct node {
    int element;
    struct node *next;
} node;

typedef struct linkedList {
    int length;
    node *tail;
    node *head;
} linkedList;

node *createNode2() {
    node *n = new node;
    n->next = NULL;
    return n;
}

linkedList *createLinkedList() {
    linkedList *l = new linkedList;
    l->tail = l->head = createNode2();
    l->length = 0;
    return l;
}

node *createNode(int val) {
    node *n = new node;
    n->element = val;
    n->next = NULL;
    return n;
}

void append(linkedList *list, int val) {
    node *n = createNode(val);

    if(!list->length) list->tail = list->head = n;
    else {

        // The current tail node points to the new last node.
        list->tail->next = n;
        // Then, the tail becomes the new node.
        list->tail = list->tail->next;
    }

    list->length++;
}

void removeLastElement(linkedList *list) {

    // The beginning of the linked list.
    node *aux = list->head;

    if(aux == NULL) return;

    while(aux->next != NULL && aux->next != list->tail)  {
        aux = aux->next;
    }

    list->tail = aux;
    list->tail->next = NULL;
    delete(aux->next);

    list->length--;
}

void partition(linkedList *list, int val) { // val == partition.
    ...
}

int main() {
    linkedList *list = createLinkedList();
    int a;
    cin >> a;

    while(a) {
        append(list, a);
        cin >> a;
    }

    int val;
    cin >> val; // partition
    partition(list, val);

    while(list->length > 0) {
        cout << list->tail->element << endl;
        removeLastElement(list);
    }

    delete(list);
    return 0;
}