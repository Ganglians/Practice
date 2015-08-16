/* Coder: Juan Chavez
 * Date:  8.4.2015
 * Objective: Exploring linked lists and ways to remove duplicate
 * entries from unsorted instances.
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

//Node structure that will be used in doubley linked list.
template <typename t>
struct node {
    t data;
    node *prev, *next;
};

//Linked list class
template <typename T>
class linkedList {
    //Function to add entry to a list.
    void addE(node<T> **head, node<T> **tail, T d) {
        //Case1: adding to an empty list.
        if((*head) == NULL) {
            (*head) = new node<T>;
            (*head)->prev = NULL;
            (*head)->next = NULL;
            (*tail) = (*head);
            (*head)->data = d;
        }
        //Case2: adding to a non-empty list.
        else {
            (*tail)->next = new node<T>;
            node<T> *tp = (*tail);
            (*tail) = (*tail)->next;
            (*tail)->prev = tp;
            (*tail)->next = NULL;
            (*tail)->data = d;
        }
    }
    
    //Function to find an entry in a list (returns NULL if false).
    node<T> *find(node<T> *head, node<T> *tail, T d) {
		for(node<T> *i = head; i != NULL; i = i->next) {
			if (i != NULL && i->data == d) {//Short-circuiting
				return i;
			}
		}
			return NULL;
	}
    
    //Function to remove an entry from the list.
    node<T> *remE(node<T> **head, node<T> **tail, T d) {
        node <T> *f = find((*head), (*tail), d);
        //Case1: not found
        if(f == NULL) {
            return NULL;
        }
        //Case2: removing from the head.
        if(f == (*head)) {
            (*head) = (*head)->next;
            if((*head) != NULL) {
				(*head)->prev = NULL;
            }
        }
        //Case3: removing from the list "body."
        else if(f->prev != NULL && f->next != NULL) {
            node<T> *p = f->prev, *n = f->next;
            p->next = n;
            n->prev = p;
        }
        //Case4: removing from the tail.
        else {
            (*tail) = (*tail)->prev;
            if((*tail) != NULL) {
                (*tail)->next = NULL;
            }
        }
        //Make sure node isn't connected before returning
        f->prev = NULL;
        f->next = NULL;
        return f;
    }
    
    //Function that returns ptr to middle of list.
    node<T> *half(node<T> **head, node<T> **tail) {
        //Does this using the "runner" technique.
        node<T> *s = (*head), *f = (*head);
        while(f != NULL) {
            s = s->next;
            f = f->next;
            if(f != NULL) {
                f = f->next;
            }
        }
        return s;
    }
    
    //Merge portion of the mergesort function.
    void merge(node<T> **low, node<T> **mid, node<T> **high) {
        //Step1: Separate sublist from main list.
        node<T> *sl_prev = (*low)->prev, *sl_next = (*high)->next;
        if(sl_prev != NULL) {
            sl_prev->next = NULL;
        }
        (*low)->prev = NULL;
        if(sl_next != NULL) {
            sl_next->prev = NULL;
        }
        (*high)->next = NULL;
        //Step2: Split sublist across the midpoint.
        node<T> *low_bound = (*mid)->prev;
        if(low_bound != NULL) {
            low_bound->next = NULL;
        }
        (*mid)->prev = NULL;
        //Step3: Iterate thru both halves and set in order.
        node<T> *i = (*low), *j = (*mid);
        node<T> *chead = NULL, *ctail;
        node<T> *q;
        while(i != NULL && j != NULL) {
            if(i->data < j->data) {
                q = remE(&i, &low_bound, i->data);
            }
            else {
                q = remE(&j, high, j->data);
            }
            addE(&chead, &ctail, q->data);
            free(q);
        }
        while(i != NULL) {
            q = remE(&i, &low_bound, i->data);
            addE(&chead, &ctail, q->data);
            free(q);
        }
        while(j != NULL) {
            q = remE(&j, high, j->data);
            addE(&chead, &ctail, q->data);
            free(q);
        }
    }
    
    //Sort portion of the mergesort function.
    void sort(node<T> **low, node<T> **high) {
        node<T> *mid = half(&(*low), &(*high));
        cout << "low: " << (*low)->data << " " << "high: " << (*high)->data << endl << endl;
        if((*low) < (*high)) {
            sort(&(*low), &(mid->prev));
            sort(&mid, &(*high));
            merge(&(*low), &mid, &(*high));
        }
    }
    
    node<T> *lhead, *ltail;
public:
	//Constructor
    linkedList() {
        lhead = NULL;
    }

    //Printing function
    void printList() {
        if (lhead == NULL) {
            return;
        }
        for(node<T> *p = lhead; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
    }

    //Function to add to linked list.
    void addL(T d) {
        addE(&lhead, &ltail, d);
    }

    //Function to remove from linked list.
    void remL(T d) {
        node<T> *r = remE(&lhead, &ltail, d);
        free(r);
    }

    //Function that sorts linked list.
    void mergesort() {
        sort(&lhead, &ltail);
    }
};

int main(int artc, char *argv[]) {
    linkedList <int>l;
   /* l.addL(1);
    l.remL(1);
    l.addL(1);
    l.addL(2);
    l.remL(2);
    l.addL(2);
    l.remL(1);
    l.addL(3);
    l.addL(4);
    l.remL(3);*/
    l.addL(10);
    l.addL(1);
    l.addL(0);
    l.addL(8);
    l.addL(6);
    l.addL(2);
    l.mergesort();
    l.printList();
    return 0;
}

