#ifndef STUDENT
#define STUDENT

#include <stdio.h>

typedef struct Student *student;

student newStudent(char name[], char surnamme[]);
void printStudents();
void addStudent(student st);
void removeStudent(student st);
student editStudent(student *student);

#endif // !STUDENT
