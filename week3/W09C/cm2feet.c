#include <stdio.h>

int main (void) {

  printf("Enter your height in centimeters: ");
  double height = 0;
  scanf("%lf", &height);

  double height_in_feet = (height / 2.54) / 12;

  printf("Your height in feet is: %lf\n", height_in_feet);
  double x = 2/3;
  printf("result=%lf\n", x);
    
  return 0;
}
