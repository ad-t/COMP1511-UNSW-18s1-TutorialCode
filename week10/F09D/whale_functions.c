#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// used as a linked list
struct pod {
  struct pod  *next;
  struct date *when;
  int         how_many;
  char        *species;
};

struct date {
  int year;
  int month;
  int day;
};

// opens the file it is given as argument 
// and calls write_sighting to print the 
// details of all the pod structs in the 
// linked list it is given
void write_sightings_file(char filename[], struct pod *first_pod) {
  FILE *sightings_file = fopen(filename, "w");
  if (sightings_files == NULL) {
    printf("error: unable to open file %s for writing\n", filename);
    return;
  }
  if (first_pod == NULL) {
    return;
  }
  struct pod *current_pod = first_pod;
  while (current_pod != NULL) {
    write_sighting(sightings_file, current_pod);
    current_pod = current_pod->next;
  }
}

// writes the details of date `d' to file `f'
void write_date(FILE *f, struct date *d) {
  if (f == NULL || d == NULL) {
    printf("error: File stream or date struct in `write_date' function is NULL\n");
    return;
  }
  fprintf(f, "%02d/%02d/%02d", date->day, date->month, date->year);
}

// writes the contents of the pod `p' to the file `f'
void write_sighting(FILE *f, struct pod *p) {
  if (f == NULL || p == NULL) {
    printf("error: File stream or pod struct in `write_sighting' function is NULL\n"); 
    return;
  }
  write_date(f, p->when);
  fprintf(f, " %02d %s\n", p->how_many, p->species);
}

// opens the file it is given as argument 
// and calls read_sighting to create pod 
// structs containing the information in 
// the file.
//
// read_sightings_file should return these 
// pod structs as a linked list. 
struct pod *read_sightings_file(char filename[]) {
  FILE *sightings_file = fopen(filename, "r");
  if (sightings_file == NULL) {
    printf("error: Cannot open file %s for reading\n", filename);
    return NULL;
  }
  struct pod *current_pod = read_sighting(sightings_file);
  struct pod *previous_pod = current_pod;
  struct pod *pod_head = current_pod;
  while (current_pod != NULL) {
    current_pod = read_sighting(sightings_file);
    previous_pod->next = current_pod;
    previous_pod = current_pod;
  }
  return pod_head;
}

// mallocs a date struct and assigns values 
// to its fields, from values read from stream `f'
struct date *read_date(FILE *f) {
  if (f == NULL) {
    printf("error: file stream in `read_date' function is NULL\n");
    return NULL;
  }
  struct date *new_date = malloc(sizeof(struct date) * 1);
  if (new_date == NULL) {
    printf("error: Cannot allocate memory to store date\n");
    return NULL;
  }
  fscanf(f, "%02d/%02d/%02d", &new_date->day, &new_date->month, &new_date->year);
  return new_date;
}

// mallocs a pod struct and assigns values 
// to its fields read from stream `f'
struct pod *read_sighting(FILE *f) {
  if (f == NULL) {
    printf("error: file stream in `read_sighting' is NULL\n");
    return NULL;
  }
  struct pod *new_pod = malloc(sizeof(struct pod) * 1);
  if (new_pod == NULL) {
    printf("error: malloc cannot allocate memory for new pod\n");
    return NULL;
  }
  struct date *when = read_date(f);
  fscanf(f, " %02d", &new_pod->how_many);
  char species_buffer[1024] = { 0 };
  if (fgets(species_buffer, 1024, f) == NULL) {
    printf("error: reading species name failed\n");
  }
  new_pod->species = malloc(sizeof(char) * (strlen(species_buffer) + 1));
  if (new_pod->species == NULL) {
    printf("error: malloc cannot allocate memory for species string\n");
  }
  strncpy(new_pod->species, species_buffer, strlen(species_buffer) + 1);
  return new_pod;
}
