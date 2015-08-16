/* Coder: Juan Chavez
 * Date:  8/12/2015
 * Objective: Partition a linked list such that all values less than
 * x come before all values greater than x.
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

    lList():head(NULL) {
    }

    void add(T d) {
        if(head == NULL) {
            head = new node<T>;
            head->next = NULL;
            head->prev = NULL;
            head->data = d;
            tail = head;
        }
        else {
            node<T> *pr = tail;
            tail->next = new node<T>;
            tail = tail->next;
            tail->next = NULL;
            tail->prev = pr;
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

    void partx(T x) {
        lList<T> lt, gt;
        node<T> *p1 = head;
        while(p1 != NULL) {
            if(p1->data < x) {
                lt.add(p1->data);
            }
            else {
                gt.add(p1->data);
            }
            p1 = p1->next;
        }
        node<T> *p2 = lt.head;
        p1 = head;
        while(p2 != NULL) {
            p1->data = p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
        p2 = gt.head;
        while(p1 != NULL && p2 != NULL) {
            p1->data = p2->data;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
};

int main(int argc, char *argv[]) {
    lList<int> l;
    l.add(1);
    l.add(10);
    l.add(8);
    l.add(3);
    l.add(5);
    l.add(6);
    l.print();
    l.partx(6);
    l.print();
    return 0;
}
