#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;

//Function template
void reverse(char* str);

int main(int argc, char *argv[]) {
    char sTest[] = "Hello world!";
    reverse(sTest);
    cout << sTest << endl;
    return 0;
}

void reverse(char* str) {
    int l = strlen(str);
    int i = 0;
    int j = l-1;
    char temp;
    while(i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
