#include <stdio.h>

int main (void) {
  int arr[10] = { 0 };
  printf("address of arr: %p\n", &arr);
  printf("contents of arr: %d\n", arr);
  printf("address of arr[0]: %p\n", &arr[0]);
}
