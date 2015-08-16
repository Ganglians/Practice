/* Coder: Juan Chavez
 * Date:  7.31.2015
 * Objective: Exploring linked lists and ways to remove duplicate entries
 * from unsorted instances.
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

template <typename t>
struct node {
    t data;
    node *prev, *next;
};

template <typename T>
class linkedList {
    node<T> *head, *tail;
    public:
    //Constructor function
    linkedList() {
        head = NULL;
    }
    //Printing function
    void printList() {
        node<T> *ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    //Search function. Returns pointer to node location.
    node<T> *search (T Data) {
        node<T> *ptr = head;
        while (ptr != NULL) {
            if(ptr->data == Data) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }
    /* Funciton to add entry to linked list (where entries are kept as
     * nodes) to end of list.
     */
    void addE(T d) {
        //Case1: Adding to empty list.
        if(head == NULL) {
            head = new node<T>;
            head->prev = NULL;
            head->data = d;
            head->next = NULL;
            tail = head;
        }
        //Case2: Adding to non-empty list.
        else {
            node<T> *tp = tail;
            tail->next = new node<T>;
            tail = tail->next;
            tail->data = d;
            tail->next = NULL;
            tail->prev = tp;
            //cout << tail->prev << endl;
        }
    }
    //Function to remove entry from linked list.
    void remE(T d) {
        //Find node entry.
        node<T> *e = search(d);
        //Case1: Entry not found. Do nothing.
        if(e == NULL) {
            return;
        }
        //Case2: Entry found.
        //Case2-1: Entry is the head.
        if(e->prev == NULL) {
            head = head->next;
            //If Head isn't null after this, set it's previous to NULL.
            if(head != NULL) {
				head->prev = NULL;
			}
            free(e);
        }
        //Case2-2: Entry is in the middle of list.
        else if(e->prev != NULL && e->next != NULL) {
            node<T> *tp = e->prev, *tn = e->next;
            free(e);
            tp->next = tn;
            tn->prev = tp;
        }
        //Case 2-3: Entry is at the tail (i.e. e->next == NULL).
        else {
            tail = tail->prev;
            free(e);
            tail->next = NULL;
        }
    }
};

int main(int argc, char *argv[]) {
    linkedList <int>t;
    t.addE(1);
    t.remE(1);
    t.addE(1);
    t.addE(2);
    t.remE(2);
    t.addE(2);
    t.remE(1);
    t.addE(3);
    t.addE(4);
    t.remE(3);
    t.printList();
    return 0;
}
