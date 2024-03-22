#pragma once
namespace geometry
{
	namespace triangle
	{
		bool read(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3);
		void readTriangle(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3);
		bool isTriangle(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3);
	} // namespace triangle
} // namespace geometry