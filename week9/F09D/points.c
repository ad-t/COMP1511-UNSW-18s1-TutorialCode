#include <stdio.h>
#include <math.h>

#define MAX_POINTS 5
#define SCANF_COUNT_REQUIRED 2

struct point {
  double x;
  double y;
};

// read points into an array, return number of points read
int read_points(struct point p[MAX_POINTS]);
// return point closest to origin
struct point closest_to_origin(int n_points, struct point p[n_points]);
// return euclidean distance between two points
double distance(struct point p, struct point q);

int main (void) {
  struct point collected_points[MAX_POINTS];
  int read_result = read_points(collected_points);
  struct point origin;
  origin.x = 0;
  origin.y = 0;
  if (read_result != MAX_POINTS) {
    printf("Error: couldn't read enough input points.\n");
    return 1;
  }

  struct point closest_point = closest_to_origin(read_result, collected_points);

  printf("Closest point -> x=%lf, y=%lf with distance %lf\n", closest_point.x, closest_point.y, distance(closest_point, origin));

  return 0;
}

// read points into an array, return number of points read
int read_points(struct point p[MAX_POINTS]) {
  unsigned int points_read = 0;
  while (points_read < MAX_POINTS) {
    unsigned int scanf_count = 0;
    scanf_count += scanf("%lf", &p[points_read].x);
    scanf_count += scanf("%lf", &p[points_read].y);
    if (scanf_count == SCANF_COUNT_REQUIRED) {
      points_read += 1;
    }
  }
  return points_read;
}

// return point closest to origin
struct point closest_to_origin(int n_points, struct point p[n_points]) {
  unsigned int current_point = 0;
  struct point closest_point_so_far;
  double closest_distance_so_far = 9999999;
  struct point origin;
  origin.x = 0;
  origin.y = 0;
  while (current_point < n_points) {
    double current_distance = distance(p[current_point], origin);
    if (current_distance < closest_distance_so_far) {
      closest_point_so_far = p[current_point];
      closest_distance_so_far = current_distance;
    }
    current_point += 1;
  }
  return closest_point_so_far;
}

// return euclidean distance between two points
double distance(struct point p, struct point q) {
  double delta_x = p.x - q.x;
  double delta_y = p.y - q.y;
  double delta_x_squared = delta_x * delta_x;
  double delta_y_squared = delta_y * delta_y;
  double sum_of_values = delta_x_squared + delta_y_squared;
  return sqrt(sum_of_values);
}
