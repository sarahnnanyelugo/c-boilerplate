#include "include/input_utils.h"
#include <stdio.h>

int main() {
    // Set constant for the number of subjects
    const int TOTAL_SUBJECTS = 5;

    // Declare subject variables
    float math, eng, sci, art, comp;
    float total, average;

    // Input marks from user
    printf("Enter marks for Mathematics: ");
    scanf("%f", &math);

    printf("Enter marks for English: ");
    scanf("%f", &eng);

    printf("Enter marks for Science: ");
    scanf("%f", &sci);

    printf("Enter marks for Art: ");
    scanf("%f", &art);

    printf("Enter marks for Computer: ");
    scanf("%f", &comp);

    // Calculate total and average
    total = math + eng + sci + art + comp;
    average = total / TOTAL_SUBJECTS;

    // Determine grade using conditionals
    char grade;

    if (average >= 70) {
        grade = 'A';
    } else if (average >= 60) {
        grade = 'B';
    } else if (average >= 50) {
        grade = 'C';
    } else if (average >= 40) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    // Print results
    printf("\nTotal marks: %.2f\n", total);
    printf("Average marks: %.2f\n", average);
    printf("Grade: %c\n", grade);

    return 0;
}
