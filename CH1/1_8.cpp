/* Coder: Juan Chavez
 * Date:  7.27.2015
 * Objective: Tell if one string is a rotation of another using only one 
 * call to strstr()
 */

#include <stdio.h>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
    const char *str1 = "waterbottle";
    const char *str2 = "erbottlewat";
    char cat1[strlen(str1) * 2 + 1];
    strcat(cat1, str1);
    strcat(cat1, str1);
    const int exists = strstr(cat1, str2) != NULL;
    if(exists) {
        printf("String is a rotation.\n");
    }
    return 0;
}
