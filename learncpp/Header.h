#pragma once
using namespace std;
#include <tuple>
#include <cmath>
tuple<double, double, double> polar_to_rectangular(double r, double z_angle, double xy_angle);
tuple<double, double, double> add_vectors(tuple<double, double, double> vect1, tuple<double, double, double> vect2);
tuple<double, double, double> rect_to_polar(tuple<double, double, double> vect1);
void input();
void stopwatch();
void solve_sus_equation();