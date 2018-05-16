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
  FILE* sightings_file = fopen(filename, "w");
  if (sightings_file == NULL) {
    printf("error: Unable to open file %s\n", filename);
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
    printf("error: stream field or date field is NULL in `write_date'\n");
    return;
  }
  fprintf(f, "%02d/%02d/%02d", d->day, d->month, d->year);
}

// writes the contents of the pod `p' to the file `f'
void write_sighting(FILE *f, struct pod *p) {
  if (f == NULL || p == NULL) {
    printf("error: stream field or pod field is NULL in `write_sighting'\n");
  }
  write_date(f, p->when);
  fprintf(f, " %2d %s\n", p->how_many, p->species);
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
    printf("error: cannot open file %s for reading\n", filename);
    return NULL;
  }
  struct pod *pod_list_head = read_sighting(sightings_file);
  if (pod_list_head == NULL) {
    return NULL;
  }
  struct pod *current_pod = read_sighting(sightings_file);
  pod_list_head->next = current_pod;
  struct pod *previous_pod = current_pod;
  while (current_pod != NULL) {
    current_pod = read_sighting(sightings_file);
    previous_pod->next = current_pod;
    previous_pod = current_pod;
  }
  // TODO: Remove below
  return NULL;
}

// struct->field == (*struct).field

// mallocs a date struct and assigns values 
// to its fields, from values read from stream `f'
struct date *read_date(FILE *f) {

}

// mallocs a pod struct and assigns values 
// to its fields read from stream `f'
struct pod *read_sighting(FILE *f) {
  
}
