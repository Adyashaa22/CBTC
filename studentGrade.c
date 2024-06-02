#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_STUDENTS 100

typedef struct {
    char subject[50];
    float score;
} Subject;

typedef struct {
    char name[50];
    Subject subjects[MAX_SUBJECTS];
    int subject_count;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int student_count;
} GradeManager;

void input_student_information(Student *student) {
    printf("Enter student name: ");
    scanf(" %[^\n]", student->name);

    student->subject_count = 0;
    while (student->subject_count < MAX_SUBJECTS) {
        printf("Enter subject name (or 'done' to finish): ");
        char subject[50];
        scanf(" %[^\n]", subject);

        if (strcmp(subject, "done") == 0) {
            break;
        }

        printf("Enter score for %s: ", subject);
        float score;
        scanf("%f", &score);

        strcpy(student->subjects[student->subject_count].subject, subject);
        student->subjects[student->subject_count].score = score;
        student->subject_count++;
    }
}

float calculate_average_score(Student *student) {
    float total = 0;
    for (int i = 0; i < student->subject_count; i++) {
        total += student->subjects[i].score;
    }
    return total / student->subject_count;
}

float calculate_highest_score(Student *student) {
    float highest = 0;
    for (int i = 0; i < student->subject_count; i++) {
        if (student->subjects[i].score > highest) {
            highest = student->subjects[i].score;
        }
    }
    return highest;
}

float calculate_lowest_score(Student *student) {
    float lowest = 100;
    for (int i = 0; i < student->subject_count; i++) {
        if (student->subjects[i].score < lowest) {
            lowest = student->subjects[i].score;
        }
    }
    return lowest;
}

void display_summary(GradeManager *manager) {
    for (int i = 0; i < manager->student_count; i++) {
        Student *student = &manager->students[i];
        printf("Name: %s\n", student->name);
        printf("Average Score: %.2f\n", calculate_average_score(student));
        printf("Highest Score: %.2f\n", calculate_highest_score(student));
        printf("Lowest Score: %.2f\n", calculate_lowest_score(student));
        printf("-----------------------------\n");
    }
}

void add_student(GradeManager *manager, Student student) {
    if (manager->student_count < MAX_STUDENTS) {
        manager->students[manager->student_count] = student;
        manager->student_count++;
    } else {
        printf("Maximum number of students reached.\n");
    }
}

int main() {
    GradeManager manager;
    manager.student_count = 0;

    while (1) {
        Student student;
        input_student_information(&student);
        add_student(&manager, student);

        printf("Do you want to add another student? (yes/y or no/n): ");
        char choice[10];
        scanf(" %s", choice);

        if (strcmp(choice, "yes") == 0 || strcmp(choice, "y") == 0) {
            continue;
        } else if (strcmp(choice, "no") == 0 || strcmp(choice, "n") == 0) {
            break;
        } else {
            printf("Invalid input\n");
            break;
        }
    }

    display_summary(&manager);
    return 0;
}
