#include<bits/stdc++.h>
using namespace std;

double err = 1e-4;

double xmax(double an, double an1, double an2){
    return sqrt(abs((an1/an)*(an1/an) - 2*(an2/an)));
}

double fun(double x){
    return x*x*x*x - 5*x*x + 4;
}

double dfun(double x){
    //differentiation of fun(x)
    return 4*x*x*x - 10*x;
}

double newton_raphson(double x){
    double x0 = x;
    while(1){
        x0 = x - fun(x)/dfun(x);
        if(abs(x-x0) < err) break;
        else x = x0;
    }
    return x0;
}


void srch(double lim, double steps){
    for(double i = -lim; i < lim; i += steps){
        //fun(i) == or fun(i+steps) == 0 not handled
        if(fun(i)*fun(i+steps) < 0){
            // cout << i << " - " << i+steps << endl;
            double root = newton_raphson(i);
            //i=i+steps+0.001
            cout << "Found root = " << root << " in interval " << i << " - " << i+steps << endl;
        }
    }
}

int main(){
    cout << xmax(1, 0, -5) << endl;
    double lim = xmax(1, 0, -5);
    srch(lim, 0.5);
}