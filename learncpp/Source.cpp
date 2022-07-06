#include <chrono>
#include <iostream>
#include <cmath>
#include <tuple>
#include <thread>
#include <Windows.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using namespace std;


tuple<double, double, double> polar_to_rectangular(double r, double z_angle, double xy_angle) {

    double x;
    double y;
    double z;
    double rsquared = pow(r, 2);
    double tanxy = tan(xy_angle);
    double tanz = tan(z_angle);

    y = rsquared / ((pow(tanxy, 2) + 1) * (pow(tanz, 2) + 1));
    x = y * tanxy;
    z = sqrt(rsquared - pow(x, 2) - pow(y, 2));

    



    return make_tuple(x, y, z);
}
tuple<double, double, double> add_vectors(tuple<double, double, double> vect1, tuple<double, double, double> vect2) {
    double x1 = get<0>(vect1);
    double y1 = get<1>(vect1);
    double z1 = get<2>(vect1);
    double x2 = get<0>(vect2);
    double y2 = get<1>(vect2);
    double z2 = get<2>(vect2);

    double xf = x1 + x2;
    double yf = y1 + y2;
    double zf = z1 + z2;


    

    return make_tuple(xf, yf, zf);
}
tuple<double, double, double> rect_to_polar(tuple<double, double, double> vect1) {
    double x1 = get<0>(vect1);
    double y1 = get<1>(vect1);
    double z1 = get<2>(vect1);


    double z_angle = atan(z1 / (sqrt(pow(x1, 2) + pow(y1, 2))));
    double xy_angle = atan(y1 / x1);
    double r = sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2));
    return make_tuple(r, z_angle, xy_angle);
}

void input() {
    double r1;
    double r2;
    double xy1;
    double xy2;
    double z1;
    double z2;
    cout << "Enter the magnitude of the first arm ";
    cin >>  r1;
    cout << "\nEnter the xy_angle of the first arm ";
    cin >> xy1;
    cout << "\nEnter the z_angle of the first arm";
    cin >> z1;

    cout << "\n\n";
    cout << "Enter the magnitude of the second arm ";
    cin >> r2;
    cout << "\nEnter the xy_angle of the second arm ";
    cin >> xy2;
    cout << "\nEnter the z_angle of the second arm";
    cin >> z2;

    

    tuple<double, double, double> rect1 = polar_to_rectangular(r1, xy1, r1);
    tuple<double, double, double> rect2 = polar_to_rectangular(r2, xy2, r2);

    tuple<double, double, double> vf = add_vectors(rect1, rect2);

    tuple<double, double, double> pf = rect_to_polar(vf);

    cout << "\n\n\n\n\nFinal position in rectangular form: " << get<0>(pf) << ", " << get<1>(pf) << ", " << get<2>(pf) << "\n";
    cout << "Final position in polar form: " << get<0>(pf) << ", " << get<1>(pf) << " degrees, " << get<2>(pf) << " degrees.\n";
   

}


double f(double arg) {
    return exp(arg) / (arg * (arg - 1) * sin(arg)) - 5;
}
bool test_root(double begin, double end) {
    double eval_begin = f(begin);
    double eval_end = f(end);
    
    if (eval_end * eval_begin < 0) {
        return true;
    }
    else if (eval_end * eval_begin > 0) {
        return false;
    }
    else {
        
        return true;
    }
}
//{{1,2}, {4,5}}
vector<vector<double>> find_intervals(double inilow, double inihigh) {
    double i = inilow;
    vector<vector<double>> result;
    while (i < inihigh) {
        double eval = f(i);
        double eval2 = f(i + 3);

        if (test_root(eval, eval2)) {
            
            result.push_back({i, i+3});


        }

        i++;
    }
    return result;
}
double bisection(double lb, double ub, double precision) {
    if (test_root(lb, ub)) {
        while ((ub - lb) / 2 > precision) {
            bool lower_interval = test_root(lb, (lb + ub) / 2);
            bool upper_interval = test_root((lb + ub) / 2, ub);

            if (lower_interval) {
                lb = lb;
                ub = (lb + ub) / 2;

            } 
            else if (upper_interval) {
                lb = (lb + ub) / 2;
                ub = ub;
            }
            else {
                lb = lb;
                ub = ub;
            }


        }
        cout << "The root is between " << lb << " and " << ub << ", += " << precision/2 << " AR" << "\n";

        return (lb + ub) / 2;
    }
    
}
int solve_sus_equation(double precision, double lower, double upper) {
    int numroots = 0;
   
    vector<double> roots;
    double lb = lower;
    double ub = upper;
    vector<vector<double>> total_intervals = find_intervals(lb, ub);
    
    if (total_intervals.size() == 0) {
        cout << "No solution exists!";
        
    }
    else {
        for (int x = 0; x < total_intervals.size(); x++) {
            double root = bisection(total_intervals[x][0], total_intervals[x][1], precision);
            roots.push_back(root);
            numroots++;
        }
    }

    cout << numroots << " is the number of roots found \n";
    auto last = unique(roots.begin(), roots.end());
    roots.erase(last, roots.end());
    for (const auto& i : roots)
        cout << fixed << setprecision(6) << i << "\n";

    return numroots;
    
}