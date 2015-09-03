/* Coder: Juan Chavez
 * Date:  8.24.2015
 * Objective: Manage three stacks in an array
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T>
class stacks {
    //Determines stack and buffer sizes
    int ss, bs;
    //Pointer to array
    T *buff;
    //Keep track of tops of stacks (stack 'pointers')
    int *sp;
    public:
    //Default constructor
    //Takes in a stack size (if none given, default is 10)
    stacks(int size = 2) {
        ss = size;
        //Buff's size is three times the stack size
        bs = ss * 3;
        //Allocate space for array
        buff = new T[bs];
        //Allocate space for array pointers (three of them)
        sp = new int[3];
        //Set pointers to default empty value (-1)
        for(int i = 0; i < 3; i ++) {
            sp[i] = -1;
        }
    }
    //Adds value to specific stack
    void push(int s, T val) {
        //cout << "stack: " << s << " value: " << val << endl;
        //cout << "sp[0]: " << sp[0] << endl;
        //Determine what stack to add to
        switch(s) {
            case 1:
                //Case 1.1: Stack is empty
                if(sp[0] == -1) {
                    sp[0] = 0;
                    buff[ (sp[0]) ] = val;
                }
                //Case 1.2: Stack is not empty and there's room
                else if(sp[0] < bs / 3 - 1) {
                    buff[ (++ sp[0]) ] = val;
                }
                else {
                    //Do nothing
                }
                break;
            case 2:
                if(sp[1] == -1) {
                    sp[1] = bs / 3;
                    buff[ (sp[1]) ] = val;
                }
                else if(sp[1] < (2 * bs) / 3 - 1) {
                    buff[ (++ sp[1]) ] = val;
                }
                else {
                    //Do nothing
                }
                break;
            case 3:
                if(sp[2] == -1) {
                    sp[2] = (2 * bs) / 3;
                    buff[ (sp[2]) ] = val;
                }
                else if(sp[2] < bs - 1) {
                    buff[ (++ sp[2]) ] = val;
                }
                else {
                    //Do nothing
                }
                break;
            default:
                //Do nothing
                break;
        }
    }
    //Removes and returns value from specified stack
    T pop(int s) {
        T val;
        //Determine from which stack to remove
        switch(s) {
            case 1:
                //Do nothing if empty
                if(sp[0] == -1) {
                    //Do nothing
                }
                else {
                    val = buff[ (sp[0] --) ];
                }
                break;
            case 2:
                if(sp[1] == -1) {
                    //Do nothing
                }
                else {
                    val = buff[ (sp[1] --) ];
                }
                //Check to see if stack is 'empty'
                if(sp[1] < bs / 3) {
                    sp[1] = -1;
                }
                break;
            case 3:
                if(sp[2] == -1) {
                    //Do nothing
                }
                else {
                    val = buff[ (sp[2] --) ];
                }
                if(sp[2] < (2 * bs) / 3) {
                    sp[2] = -1;
                }
                break;
            default:
                //Do nothing
            break;
        }
    }
    //Look at the top value in a stack
    T peek(int s) {
        T val;
        switch(s) {
            case 1:
                val = buff[ (sp[0]) ];
                break;
            case 2:
                val = buff[ (sp[1]) ];
                break;
            case 3:
                val = buff[ (sp[2]) ];
                break;
            default:
                //Do nothing
                break;
        }
    }
};
int main(int argc, char *argv[]) {
    stacks <int>s;
    cout << "stack(1), pushing 69\n";
    s.push(1, 69);
    cout << "stack(1), pushing 70\n";
    s.push(1, 70);
    //Test pushing on a full stack
    cout << "stack(1), pushing 71\n";
    s.push(1, 71);
    //Testing top (should still be 70)
    cout << "stack(1), peeking\n";
    cout << s.peek(1) << endl;
    cout << "stack(2), pushing 101\n";
    s.push(2, 101);
    cout << "stack(2), peeking\n";
    cout << s.peek(2) << endl;
    cout << "stack(3), pushing 201\n";
    s.push(3, 201);
    cout << "stack(3), pushing 59\n";
    s.push(3, 59);
    cout << "stack(3), peeking\n";
    cout << s.peek(3) << endl;
    return 0;
}

