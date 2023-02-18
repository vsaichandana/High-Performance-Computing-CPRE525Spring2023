#include <stdio.h>
#include <string.h>
#include "quad.h"

#include <stdio.h>

int main()
{
    printf("=======================================\n");
    printf("Welcome to Quadrilateral Computation\n");
    printf("=======================================\n");
    quadrilateral q;
    q.node1.x = 0.0;
    q.node1.y = 0.0;
    q.node2.x = -0.5;
    q.node2.y = 0.5;
    q.node3.x = -1.0;
    q.node3.y = 2.5;
    q.node4.x = -0.5;
    q.node4.y = 2.0;

    printf("\n Quadrilateral node #1: (%.2f, %.2f)", q.node1.x, q.node1.y);
    printf("\n Quadrilateral node #2: (%.2f, %.2f)", q.node2.x, q.node2.y);
    printf("\n Quadrilateral node #3: (%.2f, %.2f)", q.node3.x, q.node3.y);
    printf("\n Quadrilateral node #4: (%.2f, %.2f)", q.node4.x, q.node4.y);

    compute_area_quad(&q);
    printf("\n\n Computed Quadilatera Area = %.2f", q.area);

    compute_perimeter_quad(&q);
    printf("\n Computed Quadilatera Perimeter = %.2f\n", q.perimeter);
    printf("=======================================\n");

    // This was discussed in the lecture 10
    void compute_traingle();
    compute_traingle();

    return 0;
}

void compute_traingle()
{
    printf("\n=======================================\n");
    printf("Welcome to Traingle Computation\n");
    printf("=======================================\n");
 
    triangle t;
    t.node1.x = 0.0;
    t.node1.y = 0.0;
    t.node2.x = -0.5;
    t.node2.y = 0.5;
    t.node3.x = -1.0;
    t.node3.y = 2.5;

    printf("\n Triangle node #1: (%.2f, %.2f)", t.node1.x, t.node1.y);
    printf("\n Triangle node #2: (%.2f, %.2f)", t.node2.x, t.node2.y);
    printf("\n Triangle node #3: (%.2f, %.2f)", t.node3.x, t.node3.y);

    compute_area_traingle(&t);
    printf("\n\n Computed Traingle Area = %.2f", t.area);

    compute_perimeter_traingle(&t);
    printf("\n Computed Traingle Perimeter = %.2f\n", t.perimeter);
    printf("=======================================\n");

}