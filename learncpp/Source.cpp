#include <chrono>
#include <iostream>
#include <cmath>
#include <tuple>
#include <thread>
#include <Windows.h>
#include <vector>
#include <numeric>
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



void solve_sus_equation() {
    double x = 0;
    double combined = 100;
    
    
    while (true) {
        double increment = 0.000001;

        vector<double> last_five_diff;

        double comb1 = 0;
        
        

        while (abs(combined) > 0.001) {

            x += increment;
            //fix this please
            combined = exp(x) / (x * (x - 1) * sin(x)) - 5;
            
            cout << x << "          " << combined << "\n";
            double diff = abs(comb1 - combined);

            double real_difference = 0;

            if (last_five_diff.size() < 5) {
                last_five_diff.insert(last_five_diff.begin(), diff);
            }
            else {
                last_five_diff.pop_back();

                last_five_diff.insert(last_five_diff.begin(), diff);

                real_difference = last_five_diff[0] - last_five_diff[4];

                


            }
            if (real_difference > 0) {
                increment -= 0.0001;
            }
            else {
                increment += 0.00001;
            }

            

            double comb1 = combined;


        }

        cout << x << " - " << combined;

        //work on this more
    }
    


    
    
    

}
