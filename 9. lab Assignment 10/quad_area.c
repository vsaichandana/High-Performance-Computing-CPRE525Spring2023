#include <stdio.h>
#include <math.h>

#include "quad.h"

void cross_prod(double u[], double v[], double w[])
{
    w[0] = u[1] * v[2] - u[2] * v[1];
    w[1] = u[2] * v[0] - u[0] * v[2];
    w[2] = u[0] * v[1] - u[1] * v[0];
}

void compute_area_quad(quadrilateral *quad)
{
    double u[3], v[3], w[3];
    u[0] = quad->node2.x - quad->node1.x;
    u[1] = quad->node2.y - quad->node1.y;
    u[2] = 0.0;

    v[0] = quad->node4.x - quad->node1.x;
    v[1] = quad->node4.y - quad->node1.y;
    v[2] = 0.0;

    void cross_prod_quad(double u[], double v[], double w[]);
    cross_prod(u, v, w);
    double area1 = 0.5 * fabs(w[2]);

    u[0] = quad->node2.x - quad->node3.x;
    u[1] = quad->node2.y - quad->node3.y;
    u[2] = 0.0;

    v[0] = quad->node4.x - quad->node3.x;
    v[1] = quad->node4.y - quad->node3.y;
    v[2] = 0.0;

    cross_prod(u, v, w);
    double area2 = 0.5 * fabs(w[2]);

    quad->area = area1 + area2;
}

void compute_area_traingle(triangle *tri)
{
    double u[3], v[3], w[3];
    u[0] = tri->node3.x - tri->node1.x;
    u[1] = tri->node3.y - tri->node1.y;
    u[2] = 0.0;

    v[0] = tri->node2.x - tri->node1.x;
    v[1] = tri->node2.y - tri->node1.y;
    v[2] = 0.0;

    void cross_prod(double u[], double v[], double w[]);
    cross_prod(u, v, w);

    tri->area = 0.5 * fabs(w[2]);
  
}
