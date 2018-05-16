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
