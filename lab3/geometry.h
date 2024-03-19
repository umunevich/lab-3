#pragma once

namespace geometry
{
	bool equation(double& x1, double& y1, double& x2, double& y2, double& k, double& b);
	bool read(double& x, double& y);
	void readPoint(double& x, double& y);
	bool intersection(double& x1r, double& y1r, double& x2r, double& y2r, double& x1t, double& y1t, double& x2t, double& y2t);
	bool IsIntersect(double& x1r, double& y1r, double& x2r, double& y2r, double& x1t, double& y1t, double& x2t, double& y2t, double& x3t, double& y3t);
} // namespace geometry