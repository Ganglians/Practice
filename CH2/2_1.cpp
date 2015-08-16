/* Coder: Juan Chavez
 * Date:  8.9.2015
 * Objective: Remove duplicates from linked list.
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename t>
struct node {
    t data;
    node *prev, *next;
};

template <typename T>
struct lList {
    node<T> *head, *tail;

    //Constructor
    lList():head(NULL) {
    }

    //Add entry to list
    void add(T d) {
        //Case1: List is empty
        if(head == NULL) {
            head = new node<T>;
            head->prev = NULL;
            head->next = NULL;
            tail = head;
            head->data = d;
        }
        //Case2: Non-empty list
        else {
            tail->next = new node<T>;
            node<T> *pr = tail;
            tail = tail->next;
            tail->prev = pr;
            tail->next = NULL;
            tail->data = d;
        }
    }

    //Removes duplicates
    void remDup() {
        //Create pointers
        node<T> *s = head, *f;
        //First loop iterates s (slow)
        while(s != NULL) {
            //Compare s with all nodes in front of it
            f = s->next;
            while(f != NULL) {
                //Check if s and f have the same value
                if(s->data == f->data) {
                    //If it's the case, then it must be removed
                    //Case1: Removing from the middle of the list
                    if(f->prev != NULL && f->next != NULL) {
                        node<T> *p = f->prev, *n = f->next, *d = f;
                        //Move f forward once
                        f = f->next;
                        //Free duplicate node
                        free(d);
                        //Connect severed nodes
                        n->prev = p;
                        p->next = n;
                    }
                    //Case2: Removing at list end
                    else {
                        node<T> *d;
                        d = f;
                        f = f->prev;
                        f->next = NULL;
                        free(d);
                    }
                }
                else {
                    f = f->next;
                }
            }
            s = s->next;
        }
    }

    void print() {
        node<T> *ptr = head;
        while(ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    lList<int> l;
    l.add(1);
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(2);
    l.add(4);
    l.add(5);
    l.add(5);
    l.add(6);
    l.add(7);
    l.add(6);
    l.print();
    l.remDup();
    l.print();
    return 0;
}










        
