/*                                      SOLUTION 1

    If the linked list size is known, we can just iterate through the linked lis to find
    the (length - k) element. (Time => O(n) and Space => O(1)).
    
*/

// Assuming that we don't know the linked list size.
using namespace std;

typedef struct node {
    int element;
    struct node *next;
    struct node *prev;
} node;

typedef struct linkedList {
    int length;
    node *tail;
    node *head;
} linkedList;

node *createNode2() {
    node *n = new node;
    n->next = n->prev = NULL;
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
    n->next = n->prev = NULL;
    return n;
}

void append(linkedList *list, int val) {
    node *n = createNode(val);

    if(!list->length) list->tail = list->head = n;
    else {
        n->prev = list->tail;
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

/*                                      SOLUTION 2
                              If we use a double linked list.

    Time Complexity => O(n) due to the recursive calls => Where "n" is the linked list size. 

    Space Complexity => O(1) => No additional space used.

    Resolution => Start in the last element and goes back until we passed through k
    elements.
    
*/

void findElement(node *curr, int k, int count) {
    if(curr == NULL) {
        cout << "Out of bounds";
        return; // out of bounds
    }
    if(count < k) return findElement(curr->prev, k, count + 1);

    cout << curr->element;
}

int main() {
    linkedList *list = createLinkedList();
    int a, k;
    cin >> a;

    // Ex: 1 2 3 5 8 9 15 20 7 0
    while(a) {
        append(list, a);
        cin >> a;
    }

    cin >> k;
    // find the (length - k) element without using list->length
    findElement(list->tail, k, 0);

    while(list->length > 0) {
        removeLastElement(list);
    }

    delete(list);
    return 0;
}


/*                                      SOLUTION 3
                              If we use a singly linked list.

    Time Complexity => O(n) due to the recursive calls => Where "n" is the linked list size. 

    Space Complexity => O(1) => No additional space used.

    Resolution => This algotihm recurses through the linked list. When it hits the end,
    the function passes back the node value and also updates the counter by passing a
    pointer to it (pass values by reference). When the counter equals k, we know we
    have reached the kth to last element of the linked list.
    
*/

typedef struct node {
    int element;
    struct node *next;
} node;

node *createNode(int val) {
    node *n = new node;
    n->element = val;
    n->next = NULL;
    return n;
}

node *createNode2() {
    node *n = new node;
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

node *findElement(node *curr, int k, int &count) {
    if(curr == NULL){
        return NULL; // out of bounds
    }
    node *n = findElement(curr->next, k, count);
    count++;
    if(count == k) return curr;

    return n;
}

node *findElement(node *curr, int k) {
    int count = 0;
    return findElement(curr, k, count);
}

int main() {
    linkedList *list = createLinkedList();
    int a, k;
    cin >> a;

    // Ex: 1 2 3 5 8 9 15 20 7 0
    while(a) {
        append(list, a);
        cin >> a;
    }

    cin >> k;
    // find the (length - k) element without using list->length
    node *n = findElement(list->head, k);
    if(n != NULL) cout << n->element;

    while(list->length > 0) {
        removeLastElement(list);
    }

    delete(list);
    return 0;
}

/*                                      SOLUTION 4
                                    Iterative solution

    Time Complexity => O(n)=> Where "n" is the linked list size. The for loop just
    iterates through the list.

    Space Complexity => O(1)=> No additional space used.

    Resolution => Using two pointers, when the first one passes through "k" elements,
    we start to move the second one through the list, until the first gets to the end. 
    
*/

node *findElement(node *curr, int k) {
    node *p1 = curr, *p2 = curr;
    
    // Move p1 k nodes into the list.
    for(int i = 0; i < k; i++) {
        if(p1 == NULL) return NULL;
        p1 = p1->next;
    }

    /* Move them at the same pace. When p1 hits the end, p2 will be at the
    right element */

    while(p1 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main() {
    linkedList *list = createLinkedList();
    int a, k;
    cin >> a;

    // Ex: 1 2 3 5 8 9 15 20 7 0
    while(a) {
        append(list, a);
        cin >> a;
    }

    cin >> k;
    // find the (length - k) element without using list->length
    node *n = findElement(list->head, k);
    if(n != NULL) cout << n->element;

    while(list->length > 0) {
        removeLastElement(list);
    }

    delete(list);
    return 0;
}

