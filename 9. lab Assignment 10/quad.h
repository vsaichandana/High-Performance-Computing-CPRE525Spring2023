#ifndef QUAD_H
#define QUAD_H

typedef struct point Point;
struct point {
    double x;
    double y;
};

// For Quadrilateral
typedef struct quadrilateral quadrilateral;
struct quadrilateral {
    Point node1;
    Point node2;
    Point node3;
    Point node4;
    double area;
    double perimeter;
};

void compute_area_quad(quadrilateral* quad);
void compute_perimeter_quad(quadrilateral* quad); 


// For Traingle
typedef struct triangle triangle;
struct triangle
{
    Point node1;
    Point node2;
    Point node3;
    double area;
    double perimeter;
};

void compute_area_traingle(triangle* tri);
void compute_perimeter_traingle(triangle* tri); 

#endif