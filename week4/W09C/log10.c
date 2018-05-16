#include <stdio.h>

int main (int argc, char **argv) {
  int input_value = 1;
  scanf("%d", &input_value);

  int log_result = 0;
  int current_calculated_result = input_value;
  while (current_calculated_result > 1) {
    current_calculated_result = current_calculated_result / 10;
    log_result = log_result + 1;
  }

  printf("log10(%d) = %d\n", input_value, log_result);

  return 0;
}
