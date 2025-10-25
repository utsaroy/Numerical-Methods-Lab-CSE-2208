#include<bits/stdc++.h>
using namespace std;

double err = 1e-4;

double xmax(double an, double an1, double an2){
    return sqrt(abs((an1/an)*(an1/an) - 2*(an2/an)));
}

double fun(double x){
    return x*x*x*x - 5*x*x + 4;
}

//will not work when f(x0) == f(x1)
double secant(double x0, double x1){
    double f0 = fun(x0);
    double f1 = fun(x1);
    for(int iter = 0; iter < 1000; iter++){
        if(abs(x1 - x0) <= err && abs(f1) <= err){
            break;
        }
        double denom = f1 - f0;
        if(abs(denom) < 1e-12){
            break;
        }
        double x = (x1*f0 - x0*f1)/denom;
        x0 = x1;
        f0 = f1;
        x1 = x;
        f1 = fun(x1);
    }
    return x1;
}


void srch(double lim, double steps){
    for(double i = -lim; i < lim; i += steps){
        double f_start = fun(i);
        double f_end = fun(i+steps);
        if(abs(f_start) <= err){
            cout << "Found root = " << i << " in interval " << i << " - " << i+steps << endl;
            continue;
        }
        if(abs(f_end) <= err){
            cout << "Found root = " << i+steps << " in interval " << i << " - " << i+steps << endl;
            continue;
        }
        if(f_start*f_end < 0){
            double root = secant(i, i+steps);
            double f_root = fun(root);
            if(abs(f_root) <= err){
                cout << "Found root = " << root << " in interval " << i << " - " << i+steps << endl;
            }
        }
    }
}

int main(){
    cout << xmax(1, 0, -5) << endl;
    double lim = xmax(1, 0, -5);
    srch(lim, 0.5);
}