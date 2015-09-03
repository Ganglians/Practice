/* Coder: Juan Chavez
 * Date: 8.26.2015
 * Objective: Create the SetOfStacks structure
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
struct SetOfStacks {
    //Vector that holds stack set
    vector< stack<T> > set;
    //Determines max capacity of each stack
    int cap;
    public:
    //Constructor, user specifies a stack's capacity
    SetOfStacks(int c) {
        cap = c;
        //Add one stack to the set to start with
        stack<T> tmp;
        set.push_back(tmp);
    }
    //Pushes new value onto stack structure
    void push(T val) {
        //Pointer to most recently pushed set element
        stack<T> *ptr = &set.back();
        //Case1: (Most common) stack has not reached capacity
        if(ptr->size() < cap) {
            //Do nothing
        }
        //Case2: Stack is full
        else {
            //Create another stack and add it to set
            stack<T> tmp;
            set.push_back(tmp);
            //Update the pointer
            ptr = &set.back();
        }
        //Push value to stack
        ptr->push(val);
    }
    //Pops value from set of stacks according to question specs
    T pop() {
        //Where popped value will be stored
        T val;
        //Pointer to most recent stack
        stack<T> *ptr = &set.back();
        //Case1: (Most common) stack not empty
        if(!ptr->empty()) {
            //Do nothing
        }
        //Case2: Stack was empty and needs removal
        else {
            set.pop_back();
            //Update pointer
            ptr = &set.back();
        }
        //Pop value from most recent stack
        val = ptr->top();
        ptr->pop();
        return val;
    }
    //Returns value at top of most recent stack
    T peek() {
        //Where peeked value will be stored
        T val;
        //Pointer to most recent stack
        stack<T> *ptr = &set.back();
        //Case1: (Most common) stack is not empty
        /*Note: Necessary because user could have popped last element
         * on the stack
         */
        if(!ptr->empty()) {
            //Do nothing
        }
        //Case2: Stack is empty and needs removal
        else {
            set.pop_back();
            //Update pointer
            ptr = &set.back();
        }
        //Get val from most recent stack
        val = ptr->top();
        return val;
    }
    //Perform a pop operation on specific sub-stack
    T popAt(int index) {
        //Where the popped value will be stored
        T val;
        //Case1: Out of bounds or empty set
        if(index + 1 > set.size() || set.empty()) {
            //Do nothing
        }
        else {
            //Pointer to stack
            stack<T> *ptr = &set[index];
            //Get and remove item from the stack
            val = ptr->top();
            ptr->pop();
            //Re-adjust function (?)
            //adjust();
        }
        return val;
    }
};
int main(int argc, char *argv[]) {
    SetOfStacks<int> sos(2);
    cout << "Pushing '70'\n";
    sos.push(70);
    cout << "sos.peek()\n";
    cout << sos.peek() << endl;
    cout << "Pushing '80'\n";
    sos.push(80);
    cout << "sos.peek()\n";
    cout << sos.peek() << endl;
    cout << "Pushing '90' (New stack allocated)\n";
    sos.push(90);
    cout << "Popping from previous stack\n";
    cout << sos.popAt(0) << endl;
    cout << "Popping from newest stack (like normal)\n";
    cout << sos.pop() << endl;
    cout << "sos.peek()\n";
    cout << sos.peek() << endl;
    /*cout << "Popping from stack (Newest stack de-allocated)\n";
    cout << sos.pop() << endl;
    cout << "sos.peek()\n";
    cout << sos.peek() << endl;*/
    return 0;
}

