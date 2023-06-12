#include <stdio.h>
#include <math.h>

// Define a struct to represent a point
struct Point {
    float x;
    float y;
};

// Define a struct to represent a line
struct Line {
    struct Point end1;
    struct Point end2;
    struct Point midpoint;
    float slope;
    float distance;
    float yIntercept;
};

// Function prototypes
float calculateSlope(struct Line *line);
void calculateMidpoint(struct Line *line);
float calculateDistance(struct Line *line);
void calculateSlopeInterceptForm(struct Line *line);
float calculateXIntercept(struct Line *line);
float calculateYIntercept(struct Line *line);

int main() {
    struct Line line1;

    // Input point1
    printf("Enter x and y for point1: ");
    scanf("%f %f", &line1.end1.x, &line1.end1.y);

    // Input point2
    printf("Enter x and y for point2: ");
    scanf("%f %f", &line1.end2.x, &line1.end2.y);

    // Solve slope
    line1.slope = calculateSlope(&line1);
    printf("Slope: %.6f\n", line1.slope);

    // Solve midpoint
    calculateMidpoint(&line1);
    printf("Midpoint: %.6f %.6f\n", line1.midpoint.x, line1.midpoint.y);

    // Solve distance
    line1.distance = calculateDistance(&line1);
    printf("Distance between 2 points: %.6f\n", line1.distance);

    // Solve slope-intercept form
    calculateSlopeInterceptForm(&line1);

    return 0;
}

// Function to calculate the slope of a line
float calculateSlope(struct Line *line) {
    float numerator = line->end1.y - line->end2.y;
    float denominator = line->end1.x - line->end2.x;

    // Check if denominator is zero to avoid division by zero
    if (denominator == 0) {
        printf("Error: Division by zero\n");
        return INFINITY;
    }

    // Calculate and return the slope
    return numerator / denominator;
}

// Function to calculate the midpoint of a line
void calculateMidpoint(struct Line *line) {
    line->midpoint.x = (line->end1.x + line->end2.x) / 2;
    line->midpoint.y = (line->end1.y + line->end2.y) / 2;
}

// Function to calculate the distance between two points
float calculateDistance(struct Line *line) {
    float dx = line->end2.x - line->end1.x;
    float dy = line->end2.y - line->end1.y;

    return sqrt(dx * dx + dy * dy);
}

// Function to calculate the y-intercept of a line
float calculateYIntercept(struct Line *line) {
    return line->end1.y - line->slope * line->end1.x;
}

// Function to calculate the x-intercept of a line
float calculateXIntercept(struct Line *line) {
    // Check if the line is vertical (slope is infinity)
    if (line->slope == INFINITY) {
        printf("Error: No x-intercept for vertical line\n");
        return NAN;
    }

    return -line->yIntercept / line->slope;
}

// Function to calculate and print the slope-intercept form of a line
void calculateSlopeInterceptForm(struct Line *line) {
    line->yIntercept = calculateYIntercept(line);

    printf("Slope-intercept form (y = mx + b): y = %.2fx + %.2f\n", line->slope, line->yIntercept);
}
