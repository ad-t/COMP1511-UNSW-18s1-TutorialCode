#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

#define AXOLOTL 0
#define CAT     1
#define DOG     2

struct comp1511_student_marks {
  char name[MAX_NAME_LENGTH];
  unsigned int ass1_mark;
  unsigned int cumulative_lab_mark;
};

struct pet {
  char name[MAX_NAME_LENGTH];
  int pet_type;
  unsigned int age;
};

int main (void) {

  struct comp1511_student_marks adam;
  adam.ass1_mark = 75;

  struct comp1511_student_marks andrew;
  andrew.ass1_mark = 90;

  printf("andrew's ass1 mark: %d\n", adam.ass1_mark);
  printf("adam's ass1 mark: %d\n", andrew.ass1_mark);

  struct pet fluffy;
  fluffy.age = 27;
  fluffy.pet_type = AXOLOTL;
  char *fluffy_name = "fluffy";
  strncpy(fluffy.name, fluffy_name, strlen(fluffy_name) + 1);
  printf("pet name: %s\n", fluffy.name);
  printf("pet age: %d\n", fluffy.age);
  printf("pet type: %d\n", fluffy.pet_type);

  return 0;
}
