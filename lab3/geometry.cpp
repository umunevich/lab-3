#include "geometry.h"
#include<iostream>

namespace geometry
{
	bool read(double& x, double& y)
	{
		std::cout << "Enter point as X and Y coords:" << std::endl;
		if (std::cin >> x >> y)
		{
			return true;
		}
		std::cin.clear();
		std::cin.ignore();
		throw std::invalid_argument("Wrond input.");
		return false;
	}

	// Multiple times read point.
	void readPoint(double& x, double& y)
	{
		bool action = false;
		while (!action)
		{
			try
			{
				action = read(x, y);
			}
			catch (std::invalid_argument& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
	}

	bool equation(double &x1, double &y1, double &x2, double &y2, double& k, double& b)
	{
		k = (y1 - y2) / (x1 - x2);
		b = y1 - k * x1;
		return true;
	}

	// True if lines is intersect,
	// False otherwise.
	bool intersection(double& x1r, double& y1r, double& x2r, double& y2r, double& x1t, double& y1t, double& x2t, double& y2t)
	{
		double kr, br, kt, bt;
		geometry::equation(x1r, y1r, x2r, y2r, kr, br);
		geometry::equation(x1t, y1t, x2t, y2t, kt, bt);
		double x = (-1) * (br - bt) / (kr - kt);
		double y = kt * x + bt;
		if (kr != kt && kr*(x - x1r) >=0 && kr*(y - y1r) && (x - x1t) * (x2t - x) >= 0 && (y - y1t) * (y2t - y) >= 0)
		{
			return true;
		}
		return false;
	}

	// True if ray intersect triangle.
	bool IsIntersect(double& x1r, double& y1r, double& x2r, double& y2r, double& x1t, double& y1t, double& x2t, double& y2t, double& x3t, double& y3t)
	{
		if (intersection(x1r, y1r, x2r, y2r, x1t, y1t, x2t, y2t) ||
			intersection(x1r, y1r, x2r, y2r, x2t, y2t, x3t, y3t) ||
			intersection(x1r, y1r, x2r, y2r, x3t, y3t, x1t, y1t))
		{
			std::cout << "Yes, ray intersect triangle" << std::endl;
			return true;
		}
		return false;
	}
} // namespace geometry