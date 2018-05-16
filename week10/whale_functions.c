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
  // TODO: Implement
}

// writes the details of date `d' to file `f'
void write_date(FILE *f, struct date *d) {
  // TODO: Implement
}

// writes the contents of the pod `p' to the file `f'
void write_sighting(FILE *f, struct pod *p) {
  // TODO: Implement
}

// opens the file it is given as argument 
// and calls read_sighting to create pod 
// structs containing the information in 
// the file.
//
// read_sightings_file should return these 
// pod structs as a linked list. 
struct pod *read_sightings_file(char filename[]) {
  // TODO: Implement
  return NULL;
}

// mallocs a date struct and assigns values 
// to its fields, from values read from stream `f'
struct date *read_date(FILE *f) {

}

// mallocs a pod struct and assigns values 
// to its fields read from stream `f'
struct pod *read_sighting(FILE *f) {
  
}
