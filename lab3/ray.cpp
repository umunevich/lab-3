#include "ray.h"
#include "geometry.h"
#include<iostream>

namespace geometry
{
	namespace ray
	{
		bool read(double& x1, double& y1, double& x2, double& y2)
		{
			std::cout << "Enter the ray:\nStart point: ";
			readPoint(x1, y1);
			std::cout << "End point: ";
			readPoint(x2, y2);
			if (x1 == x2 && y1 == y2)
			{
				throw std::invalid_argument("Points are equal. Try again.");
				return false;
			}
			return true;
		}

		// Multople times read ray.
		void readRay(double& x1, double& y1, double& x2, double& y2)
		{
			bool action = false;
			while (!action)
			{
				try
				{
					action = read(x1, y1, x2, y2);
				}
				catch (std::invalid_argument& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}
	} // namespace ray
} // namespace geometry