#include "triangle.h"
#include "geometry.h"
#include<iostream>

namespace geometry
{
	namespace triangle
	{
		bool read(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3)
		{
			std::cout << "Enter the triangle:\n1: ";
			readPoint(x1, y1);
			std::cout << "2: ";
			readPoint(x2, y2);
			std::cout << "3: ";
			readPoint(x3, y3);
			if ((x1 == x2 && y1 == y2)||(x2 == x3 && y2 == y3)||(x1 == x3 && y1 == y3))
			{
				throw std::invalid_argument("Points are equal. Try again.");
				return false;
			}
			isTriangle(x1, y1, x2, y2, x3, y3);
			return true;
		}

		// Multiple times read triangle.
		void readTriangle(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3)
		{
			bool action = false;
			while (!action)
			{
				try
				{
					action = read(x1, y1, x2, y2, x3, y3);
				}
				catch (std::invalid_argument& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}

		// False if point on one line.
		bool isTriangle(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3)
		{
			double k1, k2, k3, b1, b2, b3;
			geometry::equation(x1, y1, x2, y2, k1, b1);
			geometry::equation(x2, y2, x3, y3, k2, b2);
			geometry::equation(x3, y3, x1, y1, k3, b3);

			if (k1 == k2 || k2 == k3 || k3 == k1)
			{
				throw std::invalid_argument("It's not a triangle. Try again.");
				return false;
			}
			return true;
		}
	} // namespace triangle
} // namespace geometry