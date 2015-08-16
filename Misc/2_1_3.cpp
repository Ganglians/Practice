/* Coder: Juan Chavez
 * Date:  8.6.2015
 * Objective: Explore ways to remove duplicates from linked-lists
 * efficiently.
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
class lList {
    //Add node to given list
    void addN(node<T> *&h, node<T> *&t, T d);

    //Search for node on given list
    node<T> *findN(node<T> *h, T d);

    //Remove node from front of list [8.8.2015]
    node<T> *deqN(node<T> *&h);

    //Remove node on given list
    node<T> *remN(node<T> *&h, node<T> *&t, T d);

    //Return pointer to middle of list
    node<T> *middle(node<T> *h);

    //Merge function
	//void merge(node<T> *&h, node<T> *&t1, node<T> *&m, node<T> *&t);

    //Sort function
	//void sort(node<T> *&h, node<T> *&t);

public:
    node<T> *head, *tail;

    //Constructor function
    lList():head(NULL){
    }

    //Prints the linked list
    void print(node<T> *h);

    //Adds node to linked list
    void addL(T d);

    //Deletes node from linked list
    void delL(T d);

    //Initiates mergesort on linked list
    //void mergesort();
    
    //Removes duplicates from linked list (without buff)
    void remDup();
};

//Linked list function defenitions
template <typename T>
void lList<T>::addN(node<T> *&h, node<T> *&t, T d) {
    //Case1: Adding to empty list
    if(h == NULL) {
        h = new node<T>;
        t = h;
        h->prev = NULL;
        h->next = NULL;
        h->data = d;
    }
    //Case2: Adding to non-empty list
    else {
        node<T> *p = t;
        t->next = new node<T>;
        t = t->next;
        t->prev = p;
        t->next = NULL;
        t->data = d;
    }
}

template <typename T>
node<T> *lList<T>::findN(node<T> *h, T d) {
    node<T> *p = h;
    while(p != NULL) {
        if(p->data == d) {
            return p;
        }
        p = p->next;
    }
    //Returns NULL if entry not found
    return NULL;
}

template <typename T>
node<T> *lList<T>::deqN(node<T> *&h) {
    node<T> *t = h;
    h = h->next;
    if(h != NULL) {
        h->prev = NULL;
    }
    if(t != NULL) {
        t->next = NULL;
    }
    return t;
}

template <typename T>
node<T> *lList<T>::remN(node<T> *&h, node<T> *&t, T d) {
    node<T> *f = findN(h, d);
    //Case0: Node not found
    if(f == NULL) {
    }
    //Case1: Removing the head
    else if(f == h) {
        h = h->next;
        if(h != NULL) {
            h->prev = NULL;
        }
    }
    //Case2: Removing from body
    else if(f->prev != NULL && f->next != NULL) {
        node<T> *pr = f->prev, *nx = f->next;
        pr->next = nx;
        nx->prev = pr;
    }
    //Case3: Removing from the tail
    else {
        t = t->prev;
        if(t != NULL) {
            t->next = NULL;
        }
    }
    f->prev = NULL;
    f->next = NULL;
    return f;
}

template <typename T>
node<T> *lList<T>::middle(node<T> *h) {
    node<T> *f = h, *s = h, *m;
    while(f && f->next) {
        m = s;
        s = s->next;
        f = f->next->next;
    }
    return m;
}

/*template <typename T>
void lList<T>::sort(node<T> *&h, node<T> *&t) {
    if (h != t) {
        node<T> *m = middle(h);
        node<T> *t1 = m;
        m = m->next;
        //Separate the two sublists
        if(t1->next != NULL) {
            t1->next = NULL;
        }
        if(m->prev != NULL) {
            m->prev = NULL;
        }
        cout << "h: ";
        print(h);
        cout << "m: ";
        print(m);
        sort(h, t1);
        cout << "h(2): ";
        print(h);
        sort(m, t);
        cout << "m(2): ";
        print(m);
        merge(h, t1, m, t);
        cout << "merge stops \n";
    }
    else {
        cout << "sort stops \n";
    }
}*/
/*template <typename T>
void lList<T>::merge(node<T> *&h, node<T> *&t1, node<T> *&m, node<T> *&t) {
    node<T> *n1, *n2, *tn;
    while(h != NULL && m != NULL) {
        if(h->data < m->data) {
            n1 = deqN(h);
            addN(n2, tn, n1->data);
        }
        else {
            n1 = deqN(m);
            addN(n2, tn, n1->data);
        }
    }
    cout << "n2: ";
    print(n2);   
    while (h != NULL) {
        cout << h->data << " ";
        n1 = deqN(h);
        addN(n2, tn, n1->data);
    }
    while(m != NULL) {
        cout << "while(m)";
        n1 = deqN(m);
        addN(n2, tn, n1->data);
    }
    h = n2;
    t = tn;
    if (t != NULL) {
        t->next = NULL;
    }
    cout << "n2: ";
    print(n2);
}*/

template <typename T>
void lList<T>::print(node<T> *h) {
    node<T> *p = h;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <typename T>
void lList<T>::addL(T d) {
    addN(head, tail, d);
}

template <typename T>
void lList<T>::delL(T d) {
    node<T> *p = remN(head, tail, d);
    if(p != NULL) {
        free(p);
    }
}

/*template <typename T>
void lList<T>::mergesort() {
    sort(head, tail);
}*/

template <typename T>
void lList<T>::remDup() {
	node<T> *p1 = head, *p2 = head->next;
	while(p1 != NULL) {
		while(p2 != NULL) {
			if(p2->data == p1->data) {
				node<T> *tpa = p2->prev, *tpb = p2->next, 
				*del;
				del = p2;
				p2 = p2->next;
				tpa->next = tpb;
				tpb->prev = tpa;
				free(del);
			}
			else {
				p2 = p2->next;
			}
		}
		p1 = p1->next;
		p2 = p1->next;
	}
}
int main(int argc, char *argv[]) {
    lList<int> ll;
    //Test Cases for adding and removing from list
    /*ll.addL(1);
    ll.print(ll.head);
    ll.delL(1);
    ll.print(ll.head);
    ll.addL(1);
    ll.addL(10);
    ll.addL(3);
    ll.print(ll.head);
    ll.delL(10);
    ll.print(ll.head);
    ll.addL(4);
    ll.print(ll.head);
    ll.delL(1);
    ll.print(ll.head);
    ll.delL(4);
    ll.print(ll.head);*/

    //Test case for mergesort
    ll.addL(10);
    ll.addL(10);
    ll.addL(1);
    ll.addL(4);
    ll.addL(3);
    ll.addL(2);
    ll.addL(2);
    ll.addL(5);
    ll.addL(6);
    ll.addL(8);
    ll.addL(5);
    ll.addL(7);
    ll.addL(9);
    ll.addL(10);
    ll.remDup();
    ll.print(ll.head);
    //ll.mergesort();
    //ll.print(ll.head);
    return 0;
}
