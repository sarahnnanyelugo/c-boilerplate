// #include "include/input_utils.h"
// #include <stdio.h>

// int main() {
//     int age = get_int("Enter your age: ");
//     string first_name = get_string("Enter your name: ");
//     printf("Hello, %s! You are %d years old.\n", first_name, age);
//     string last_name = get_string("Enter your last name: ");
//     printf("Your full name is: %s %s\n", first_name, last_name);
//     return 0;
// }

#include <stdio.h>

int main() {
    char name[] = "EMEKA NWOSU";
    int count = 0;

    while (name[count] != '\0') {
        count++;
    }

    printf("Number of characters in name \"%s\" is %d\n", name, count);

    return 0;
}

