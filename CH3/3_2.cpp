/* Coder: Juan Chavez
 * Date:  8.25.2015
 * Objective: Create an O(1) function for stack
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

//Simple array struct that behaves like a stack
template <typename T>
struct mystack {
    T *buff, *mbuff; //Keeps a stack of mins
    int p, size, mp;
    //Min buff management functions
    //Look at top of min stack
    T mpeek() {
        return mbuff[mp];
    }
    void mpush(T val) {
        //Case1: Empty minimum stack
        if(mp == -1) {
            mp = 0;
            mbuff[mp] = val;
        }
        //Case2: Non-empty minimum stack
        else if(mp < size - 1) {
            //Check if less than or equal to val at stack top
            if(val <= mpeek()) {
                mbuff[ (++ mp) ] = val;
            }
        }
        else {
            //Do nothing
        }
    }
    void mrem(T val) {
        //Case1: Stack is empty
        if(mp == -1) {
            //Do nothing
        }
        //Case2: Non-empty and matches
        else if(val == mpeek()) {
            mp --;
        }
    }
public:
    //Default constructor
    mystack(int s = 10) {
        size = s;
        p = -1;
        mp = -1;
        buff = new T[size];
        mbuff = new T[size];
    }
    //Add element to top of stack
    void push(T val) {
        //Case1: If stack is empty
        if(p == -1) {
            p = 0;
            buff[p] = val;
            mpush(val);
        }
        //Case2: If stack is non-empty
        else if(p < size - 1) {
            buff[ (++ p) ] = val;
            mpush(val);
        }
        //Case3: Stack is full
        else {
            //Do nothing
        }
    }
    //Remove and return element from stack
    T pop() {
        T val;
        //Case1: Stack is empty
        if(p == -1) {
            //Do nothing
        }
        //Case2: Non-empty stack
        else {
            val = buff[ (p --) ];
            mrem(val);
        }
        return val;
    }
    //Look at top element on the stack
    T peek() {
        T val;
        //Case1: Empty stack
        if(p == -1) {
            //Do nothing
        }
        //Case2: Non-empty stack
        else {
            val = buff[p];
        }
        return val;
    }
    //Return min in O(1) time
    T min() {
        return mpeek();
    }
};

int main(int argc, char *argv[]) {
    mystack <int>s;
    s.push(4);
    s.push(5);
    cout << s.min() << endl;
    s.push(1);
    cout << s.min() << endl;
    cout << "Popping\n";
    cout << s.pop() << endl;
    cout << s.min() << endl;
    return 0;
}
