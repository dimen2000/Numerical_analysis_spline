#include "spline.h"

 void spline::create_spline(unsigned int sz, std::vector<double> x,  std::vector<double> y)
{
    size = sz;
    polys = new spline_poly[size];
    for(unsigned int i = 0; i < size; ++i)
    {
        polys[i].x = x[i];
        polys[i].a = y[i];
    }

    double* h = new double[size];
    double* l = new double[size];

    for(unsigned int i = 1; i < size; ++i)
    {
        h[i] = x[i] - x[i-1];
        l[i] = (y[i] - y[i - 1])/h[i];
    }

    double* delta = new double[size];
    double* lambda = new double[size];

    delta[1] = - h[2]/(2*(h[1]+h[2]));
    lambda[1] = 3*(l[2] - l[1])/(2*(h[1]+h[2]));

    for(unsigned int i = 2; i < size - 1; ++i)
    {
        delta[i] = - h[i + 1]/(2*h[i]+2*h[i + 1]+h[i]* delta[i - 1]);
        lambda[i] = (3*l[i + 1] - 3*l[i] - h[i] * lambda[i - 1])/(2*h[i]+2*h[i + 1]+h[i] * delta[i - 1]);
    }

    polys[size - 1].c = 0;
    polys[0].c = 0;

    for(unsigned int i = size - 2; i > 0; --i)
    {
        polys[i].c = delta[i]*polys[i + 1].c + lambda[i];
    }

    for(unsigned int i = 1; i < size; ++i)
    {
        polys[i].b = l[i] + (2*polys[i].c*h[i] + h[i]*polys[i - 1].c)/3;
        polys[i].d = (polys[i].c - polys[i - 1].c)/(3*h[i]);
    }

    for (unsigned i = size - 1; i > 0; --i)
    {
        polys[i].d = (polys[i].c - polys[i - 1].c) / h[i];
        polys[i].b = h[i] * (2. * polys[i].c + polys[i - 1].c) / 6. + (y[i] - y[i - 1]) / h[i];
    }

    delete[] delta;
    delete[] lambda;
    delete[] h;
    delete[] l;
}

double spline::get(double x)
{
    spline_poly *spl;
    if (x <= polys[0].x)
        spl = polys + 1;
    else if (x >= polys[size - 1].x)
        spl = polys + size - 1;
    else
    {
        size_t i = 0, j = size - 1;
        while (i + 1 < j)
        {
            size_t k = i + (j - i) / 2;
            if (x <= polys[k].x)
                j = k;
            else
                i = k;
        }
        spl = polys + j;
    }

    double dx = (x - spl->x);
    return spl->a + (spl->b + (spl->c / 2. + spl->d * dx / 6.) * dx) * dx;
}

spline::~spline()
{
    if(polys)
        delete[] polys;
}
