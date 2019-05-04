#include <math.h>

/* Compute area of circle.
 */
double area_circle(double radius) {
    return M_PI * pow(radius, 2.0);
}

/* Compute area of square.
 */
double area_square(double side) {
    return pow(side, 2.0);
}

/* Compute area of rectangle.
 */
double area_rectangle(double length, double width) {
    return length * width;
}
