#include <stdio.h>
#include <math.h>
#include "quad.h"

double compute_distance(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void compute_perimeter_quad(quadrilateral *quad)
{

    // Calculate the perimeter
    quad->perimeter = compute_distance(quad->node1, quad->node2) + compute_distance(quad->node2, quad->node3) +
                      compute_distance(quad->node3, quad->node4) + compute_distance(quad->node4, quad->node1);
}

void compute_perimeter_traingle(triangle* tri)
{

    // Calculate the perimeter
    tri->perimeter = compute_distance(tri->node1, tri->node2) + compute_distance(tri->node2, tri->node3) +
                      compute_distance(tri->node3, tri->node1);
}