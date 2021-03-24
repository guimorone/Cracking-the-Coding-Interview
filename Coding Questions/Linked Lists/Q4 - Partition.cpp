/*                                      SOLUTION

    Time Complexity => O(n) => Where "n" is the number of elements in the given linked list. We just iterate
    through the given linked list.

    Space Complexity => O(n) => We create 2 additional linked lists that save the smallest and the biggest 
    numbers. Both have, in total, length "n".

    Resolution => Append the smallest numbers in the "before" list and the biggest in the "after" list. Then,
    merge both linked lists.
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

void clear(linkedList *list) {
    while(list->length > 0) {
        removeLastElement(list);
    }
}

void partition(linkedList *list, int val) { // val == partition.
    linkedList *before = createLinkedList(), *after = createLinkedList();
    node *curr = list->head;
    while(curr != NULL) {
        if(curr->element < val) append(before, curr->element);
        else append(after, curr->element);
        curr = curr->next;
    }
    delete curr;
    clear(list);

    /* node *n = before->head;
    while(n != NULL) {
        append(list, n->element);
        n = n->next;
    }
    n = after->head;
    while(n != NULL) {
        append(list, n->element);
        n = n->next;
    }
    delete n; */

    list->head = list->tail = createNode2();
    list->head = before->head;
    list->tail = before->tail;
    list->tail->next = after->head;
    list->tail = after->tail;
    
    clear(before);
    delete before;
    clear(after);
    delete after;

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

    delete list;
    return 0;
}