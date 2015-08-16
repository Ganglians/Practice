/* Coder: Juan Chavez
 * Date:  8.10.2015
 * Objective: Print kth to last element of singly linked list
 */
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename t>
struct node {
   t data;
    node *next;
};

template <typename T>
struct lList {
    node<T> *head, *tail;
    
    lList():head(NULL) {
    }

    void add(T d) {
        //Empty list
        if(head == NULL) {
            head = new node<T>;
            head->next = NULL;
            tail = head;
            head->data = d;
        }
        //Non-empty list
        else {
            tail->next = new node<T>;
            tail = tail->next;
            tail->next = NULL;
            tail->data = d;
        }
    }

    void print() {
        node<T> *p = head;
        while(p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void printkth(int k) {
        node<T> *s = head, *f;
        int i;
        while(s != NULL) {
            f = s->next;
            i = 1;
            while(f != NULL) {
                f = f->next;
                ++i;
            }
            if(i == k) {
                cout << s->data << endl;
                return;
            }
            s = s->next;
        }
    }
};

int main(int argc, char *argv[]) {
    lList<int> l;
    l.add(1);
    l.add(8);
    l.add(7);
    l.add(9);
    l.print();
    l.printkth(2);
    l.printkth(3);
    l.printkth(4);
    return 0;
}
