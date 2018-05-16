#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define EXPECTED_VALUE_READS 2
#define MAX_POINTS 5

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

  struct point entered_points[MAX_POINTS];
  int points_read = read_points(entered_points);

  if (points_read != MAX_POINTS) {
    printf("Error: less points have been read than expected.\n");
    return 1;
  }

  struct point origin;
  origin.x = 0;
  origin.y = 0;
  struct point closest_point_to_origin = closest_to_origin(points_read, entered_points);
  printf("Closest point is (%lf, %lf) with euclidean distance %lf\n", closest_point_to_origin.x, closest_point_to_origin.y, distance(closest_point_to_origin, origin));

  return 0;
}

// read points into an array, return number of points read
int read_points(struct point p[MAX_POINTS]) {
  unsigned int points_read = 0;
  while (points_read < MAX_POINTS) {
    int successful_scanfs = 0;
    successful_scanfs += scanf("%lf", &p[points_read].x);
    successful_scanfs += scanf("%lf", &p[points_read].y);
    if (successful_scanfs == EXPECTED_VALUE_READS) {
      points_read += 1;
    }
  }
  return points_read;
}

// return point closest to origin
struct point closest_to_origin(int n_points, struct point p[n_points]) {
  int points_index = 0;
  struct point closest_point_so_far;
  double closest_point_distance = 99999999;
  struct point origin;
  origin.x = 0;
  origin.y = 0;
  while (points_index < n_points) {
    double point_distance = distance(p[points_index], origin);
    if (point_distance < closest_point_distance) {
      closest_point_so_far = p[points_index];
      closest_point_distance = point_distance;
    }
    points_index += 1;
  }
  return closest_point_so_far;
}

// return euclidean distance between two points
double distance(struct point p, struct point q) {
  double delta_x = p.x - q.x;
  double delta_y = p.y - q.y;
  double delta_x_squared = delta_x * delta_x;
  double delta_y_squared = delta_y * delta_y;
  double distance_squared = delta_x_squared + delta_y_squared;
  double distance = sqrt(distance_squared);
  return distance;
}

