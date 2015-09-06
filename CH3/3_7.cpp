/* Coder: Juan Chavez
 * Date:  9.5.2015
 * Objective: Animal shelter bookeeping (as specified on question 3.7)
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
using namespace std;

//Animal base class
class animal {
    //Keeps track of time in shelter relative to others
    int order;

    public:
    //A way of knowing derived class for animal
    typedef enum {DOG, CAT} tp;
    tp type;

    //Stores animal's name
    string name;

    //constructor, set animal's name
    animal(string n) : name(n) {
    }

    //Sets order integer
    void setOrder(int i) {
        order = i;
    }

    //Order accessor
    int getOrder() {
        return order;
    }

    //Compares two animal's orderings (smaller order = 'older')
    bool olderThan(animal a) {
        return this->order > a.getOrder();
    }
};

//Derived animal class, dog
class dog : public animal {
    public:
    //Constructor, invokes parent's constructor with a value
    dog(string n) : animal(n) {
        type = DOG;
    }
};

//Derived animal class, cat
class cat : public animal {
    public:
    //Constructor
    cat(string n) : animal(n) {
        type = CAT;
    }
};

//Animal shelter class
class shelter {
    //List of dogs and cats
    list<dog*> dogs;
    list<cat*> cats;

    //Keeps track of current order number
    int order;

    public:
    
    //Constructor
    shelter() : order(0) {
    }

    //Adds animal to specific list
    void enque(animal *a) {
        if(a->type == animal::DOG) {
            a->setOrder(order);
            order ++;
            dogs.push_back((dog*) a);
        }
        else if(a->type == animal::CAT) {
            a->setOrder(order);
            order ++;
            cats.push_back((cat*) a);
        }
    }

    //Deque a dog
    dog *dequeDog() {
        if(dogs.empty()) {
            cout << "No dogs in shelter\n";
            return NULL;
        }
        else {
            dog *dp = dogs.front();
            dogs.pop_front();
            return dp;
        }
    }

    //Deque a cat
    cat *dequeCat() {
        if(cats.empty()) {
            cout << "No cats in shelter\n";
            return NULL;
        }
        else {
            cat *cp = cats.front();
            cats.pop_front();
            return cp;
        }
    }

    //Deque 'oldest' animal
    animal *dequeAny() {
        //Case1: Both empty
        if(dogs.empty() && cats.empty()) {
            cout << "No animals in shelter\n";
            return NULL;
        }
        //Case2: No dogs, send oldest cat
        if(dogs.empty()) {
            cat *c = cats.front();
            cats.pop_front();
            return c;
        }
        //Case3: No cats, send oldest dog
        if(cats.empty()) {
            dog *d = dogs.front();
            dogs.pop_front();
            return d;
        }
        //Case4: Both lists available, send oldest animal
        dog *d = dogs.front();
        cat *c = cats.front();
        if(d->getOrder() < c->getOrder()) {
            return d;
        }
        else {
            return c;
        }
    }
};

int main(int argc, char *argv[]) {
    cout << "Shelter test\n";
    shelter s;
    dog d1("Fido"), d2("Old Yeller");
    cat c1("Mittens"), c2("calico");
    cout << "Adding animals\n";
    cout << "Cat: Mittens\n";
    s.enque(&c1);
    cout << "Dog: Fido\n";
    s.enque(&d1);
    cout << "Dog: Old Yeller\n";
    s.enque(&d2);
    cout << "Cat: Calico\n";
    s.enque(&c2);
    cout << "Adopting oldest dog\n";
    dog *dp1 = s.dequeDog();
    cout << dp1->name << endl;
    cout << "Adopting oldest cat\n";
    cat *cp1 = s.dequeCat();
    cout << cp1->name << endl;
    cout << "Adopting oldest animal\n";
    animal *ap1 = s.dequeAny();
    cout << ap1->name << endl;
    return 0;
    return 0;
}
