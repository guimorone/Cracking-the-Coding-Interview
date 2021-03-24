/*                                      SOLUTION

    Time and Space Complexity => O(1) => Constant amount of work and memory usage.

    Resolution => Since we only have access to the given node, we must simply have to
    copy the data from the next node over to the current node and then delete the
    next node.
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

void deleteMiddleNode(node *curr) {
    if(curr == NULL) return; // Failure
    if(curr->next == NULL) {
        delete curr;
        return;
    }

    node *aux = curr->next;
    /* curr->element = curr->next->element;
       curr->next = curr->next->next; */
    curr = curr->next;
    delete aux; // Free memory
}

int main() {
    linkedList *list = createLinkedList();
    int a;
    cin >> a;

    while(a) {
        append(list, a);
        cin >> a;
    }

    // Only access to that node (no list->tail or list->head).
    deleteMiddleNode(n);

    while(list->length > 0) {
        cout << list->tail->element << endl;
        removeLastElement(list);
    }

    delete(list);
    return 0;
}