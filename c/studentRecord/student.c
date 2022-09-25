#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.txt"

struct Student {
  unsigned int id;
  char name[50];
  char surname[100];
};

typedef struct Student *student;
FILE *file;

// private functions
void _openFile();
void _closeFile();
unsigned int _numberOfStudents();
//------------------

// PUBLIC
student newStudent(char name[50], char surname[100]) {
  student st;
  st = malloc(sizeof(struct Student));
  st->id = _numberOfStudents() + 1;
  strcpy(st->name, name);
  strcpy(st->surname, surname);

  return st;
}

void printStudents() {
  _openFile();

  student temp;
  temp = malloc(sizeof(student));

  char *line;
  size_t len = 0;
  ssize_t read;
  printf("%-5s%-15s%-20s\n", "Id", "Name", "Surname");
  while ((read = getline(&line, &len, file)) != -1) {
    temp->id = atoi(strtok(line, ","));       // get id
    strcpy(temp->name, strtok(NULL, ","));    // get name
    strcpy(temp->surname, strtok(NULL, ",")); // get surname

    /* printf("surname: %s\n", temp->surname); */
    printf("%-5i%-15s%-20s\n", temp->id, temp->name, temp->surname);
  }

  free(temp);

  _closeFile();
}

void addStudent(student st) {
  _openFile();

  fprintf(file, "%i,%s,%s\n", st->id, st->name, st->surname);
  printf("Student added\n");

  _closeFile();
}

// PRIVATE
void _openFile() {
  file = fopen(FILENAME, "a+");
  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
}

void _closeFile() { fclose(file); }

unsigned int _numberOfStudents() {
  _openFile();

  char c;
  unsigned int count = 0;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n')
      count++;
  }

  _closeFile();

  return count;
}
