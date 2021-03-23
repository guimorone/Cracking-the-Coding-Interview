// malloc == free
// new == delete

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

// Node->element == val.
void removeSpecificElement(linkedList *list, int val) {
    node *aux = list->head;

    if(aux == NULL) return;
    
    if(aux->element == val) {
        list->head = list->head->next;
        list->length--;
        delete(aux);
        return;
    }

    while(aux->next != NULL)  {
        if(aux->next->element == val) {
            if(aux->next == list->tail) {
                list->tail = aux;
                list->tail->next = NULL;
                delete(aux->next);
            } else {
                node *n = aux->next;
                aux->next = aux->next->next;
                delete(n);
            }
            list->length--;
            return;
        }
        aux = aux->next;
    }
}

/*                                      SOLUTION 1

    Time Complexity => O(n) => Where "n" is the length of the Linked List. We just
    iterates through the list once and check the duplicates.
    
    Space Complexity => O(n) => Map size.
*/

void removeDups(linkedList *list) {
    node *curr = list->head;
    map < int, bool > check;

    while(curr != NULL) {
        if(check[curr->element]) removeSpecificElement(list, curr->element);
        check[curr->element] = true;
        curr = curr->next;
    }

    free(curr);
}

int main() {
    linkedList *list = createLinkedList();
    int a;
    cin >> a;

    while(a) {
        append(list, a);
        cin >> a;
    }

    removeDups(list);

    while(list->length > 0) {
        cout << list->tail->element << endl;
        removeLastElement(list);
    }
    
    delete(list);
    
    return 0;
}

/*                                      SOLUTION 2

    Time Complexity => O(n²) => Where "n" is the length of the Linked List. We iterates
    through the list with two pointers, "curr" and "runner". "curr" iterates through the
    linked list and runner checks all subsequent nodes for duplicates.

    Space Complexity => O(1) => No additional space used.
    
*/

void removeDups(linkedList *list) {
    node *curr = list->head;

    while(curr != NULL) {
        node *runner = curr;
        while(runner->next != NULL) {
            // Remove all future nodes that have the same value
            if(runner->next->element == curr->element) {
                node *n = runner->next;
                runner->next = runner->next->next;
                list->length--;
                delete n;
            } else runner = runner->next;
        }
        curr = curr->next;
    }

    free(curr);
}

int main() {
    linkedList *list = createLinkedList();
    int a;
    cin >> a;

    while(a) {
        append(list, a);
        cin >> a;
    }

    removeDups(list);

    while(list->length > 0) {
        cout << list->tail->element << endl;
        removeLastElement(list);
    }
    
    delete(list);
    
    return 0;
}