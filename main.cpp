#include<iostream>
#include "output.h"
#include "geometry.h"
#include "ray.h"
#include "triangle.h"

int main()
{
	output::aboutMe();
	output::taskOfProgram();

	double x1_ray, y1_ray, x2_ray, y2_ray;
	double x1_trgl, y1_trgl, x2_trgl, y2_trgl, x3_trgl, y3_trgl;

	geometry::ray::readRay(x1_ray, y1_ray, x2_ray, y2_ray);
	geometry::triangle::readTriangle(x1_trgl, y1_trgl, x2_trgl, y2_trgl, x3_trgl, y3_trgl);

	geometry::IsIntersect(x1_ray, y1_ray, x2_ray, y2_ray, x1_trgl, y1_trgl, x2_trgl, y2_trgl, x3_trgl, y3_trgl);

	output::bye();
}
