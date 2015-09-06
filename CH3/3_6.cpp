/* Coder: Juan Chavez
 * Date:  9.3.2015
 * Objective: Sort stack in ascending order using at most one other stack
 */

#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

//Print a stack
void printStack(stack<int> s) {
    //Make a copy of the stack and print it
    for(stack<int> tmp = s; !tmp.empty(); tmp.pop()) {
        cout << tmp.top() << endl;
    }
}

//Sort stack in ascending order
stack<int> sortStack(stack<int> s) {
    stack<int> r;
    while(!s.empty()) {
        int tmp = s.top();
        s.pop();
        while(!r.empty() && r.top() > tmp) {
            int tmp2 = r.top();
            r.pop();
            s.push(tmp2);
        }
        r.push(tmp);
    }
    return r;
}

int main(int argc, char *argv[]) {
    cout << "Pushing to stack\n";
    stack<int> m, n;
    m.push(10);
    m.push(7);
    m.push(8);
    m.push(9);
    cout << "Unsorted stack\n";
    printStack(m);
    cout << "Sorting stack\n";
    n = sortStack(m);
    cout << "Sorted stack:\n";
    printStack(n);
    return 0;
}
