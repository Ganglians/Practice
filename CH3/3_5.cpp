/* Coder: Juan Chavez
 * Date:  9.3.2015
 * Objective: Implement a queue using two stacks
 */

#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MyQueue {
    //Newest val at 'front' or oldest
    stack<T> newest, oldest;

    public:

    //Constructor
    MyQueue() {
        //newest = new stack<T>;
        //oldest = new stack<T>;
    }

    //Move leements from one stack to another
    void reverse() {
        //Case1: Newest at top stack is empty
        if(newest.empty()) {
            //Move items to newest-first stack
            T tmp;
            while(!oldest.empty()) {
                tmp = oldest.top();
                oldest.pop();
                newest.push(tmp);
            }
        }
        //Case2: Oldest at top stack is empty
        else if (oldest.empty()) {
            //Move items to oldest-first stack
            T tmp;
            while(!newest.empty()) {
                tmp = newest.top();
                newest.pop();
                oldest.push(tmp);
            }
        }
    }

    //Add item to the end of the queue
    void enq(T val) {
        //Make sure adding after most recently added
        if(newest.empty()) {
            reverse();
        }
        //Add to newest-first
        newest.push(val);
    }

    //Remove oldest item from line front
    T deque() {
        //Make sure removing oldest item added
        if(oldest.empty()) {
            reverse();
        }
        T tmp = oldest.top();
        oldest.pop();
        return tmp;
    }

    //Look at oldest item in front of line
    T peek() {
        //Make sure looking at oldest item added
        if(oldest.empty()) {
            reverse();
        }
        T tmp = oldest.top();
        return tmp;
    }
};

int main(int argc, char *argv[]) {
    MyQueue<int> q;
    cout << "Adding '9' to queue\n";
    q.enq(9);
    cout << "Peeking at oldest item\n";
    cout << q.peek() << endl;
    cout << "Adding '100' to queue\n";
    q.enq(100);
    cout << "Peeking at oldest element\n";
    cout << q.peek() << endl;
    cout << "Dequeing oldest element\n";
    cout << q.deque() << endl;
    cout << "Peeking at oldest element\n";
    cout << q.peek() << endl;
    cout << "Removing oldest element\n";
    cout << q.deque() << endl;
    return 0;
}
