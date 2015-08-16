/* Coder: Juan Chavez
 * Date:  8.2.2015
 * Objective: Make it so linked list from 2_P1 doesn't use a length var.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class lList {
    struct node {
        T dat;
        node *prev, *next;
    };
    node *head, *tail;

    public:
    lList() {
        head = NULL;
    }

    void add(T d) {
        if(head == NULL) {
            head = new node;
            head->dat = d;
            head->prev = NULL;
            head->next = NULL;
            tail = head;
        }
        else {
            tail->next = new node;
            node *p = tail;
            tail = tail->next;
            tail->next = NULL;
            tail->prev = p;
            tail->dat = d;
        }
    }

    node *find(T f) {
        node *ptr = head;
        while(ptr != NULL) {
            if(ptr->dat == f) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }

    void rem(T d) {
        node *found = find(d);
        if(found != NULL) {
            //Different removal cases.
            //Case1: Removing the head.
            if(found->prev == NULL) {
                head = head->next;
                free(found);
                return;
            }
            //Case2: Removing out of 2 or more.
            else {
                //cout << found->dat << endl;
                //cout << head->dat << endl;
                //CaseA: Removing head.
                if(found->dat == head->dat) {
                    node *tmp = head;
                    head = head->next;
                    head->prev = NULL;
                    free(tmp);
                    return;
                }
                //CaseB: Removing the tail.
                if(found->next == NULL) {
                    node *tmp = tail;
                    tail = tail->prev;
                    tail->next = NULL;
                    free(tmp);
                    return;
                }
                //CaseC: Removing from in between
                else {
                    node *p = found->prev;
                    node *n = found->next;
                    p->next = n;
                    p->prev = p;
                    free(found);
                    return;
                }
            }
        }
    }

    void printList() {
        node *ptr = head;
        while(ptr != NULL) {
            cout << ptr->dat << " ";
            ptr = ptr->next;
        }
    }
};

int main(int argc, char *argv[]) {
    lList <int>t;
    t.add(1);
    t.rem(1);
    t.add(1);
    t.add(2);
    t.rem(2);
    t.add(2);
    t.rem(1);
    t.add(3);
    t.add(4);
    t.rem(3);
    t.printList();
    return 0;
}
