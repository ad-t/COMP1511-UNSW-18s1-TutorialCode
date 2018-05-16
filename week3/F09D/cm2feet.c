#include <stdio.h>

int main (int argc, char **argv) {
  
  printf("Enter your height in centimetres: ");
  int height_in_cm = 0;
  scanf("%d", &height_in_cm);
  double height_in_feet = (height_in_cm / 2.54) / 12;

  printf("Your height in feet is %lf\n", height_in_feet);
  double result = 2/3.0;
  printf("2/3 = %lf\n", result);

  return 0;
}
