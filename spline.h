#include <tchar.h>
#include <math.h>
//#include <limits>

#ifndef SPLINE_H
#define SPLINE_H

#include <vector>

struct spline_poly
{
  double a, b, c, d, x;
};

class spline
{
public:
    spline() = default;
    void create_spline(unsigned int sz, std::vector<double> x, std::vector<double> y);
    double get(double x);
    ~spline();
private:
    unsigned int size;
    spline_poly* polys;
};
#endif // SPLINE_H
