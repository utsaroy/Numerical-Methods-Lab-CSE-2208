#include<bits/stdc++.h>
using namespace std;

double err = 1e-4;

double xmax(double an, double an1, double an2){
    return sqrt(abs((an1/an)*(an1/an) - 2*(an2/an)));
}

double fun(double x){
    return x*x*x*x - 5*x*x + 4;
}

double false_position(double s, double e){
    double m=s;
    int count = 0;
    while(e-s > err){
        count++;
        m = (s*fun(e) - e*fun(s))/(fun(e) - fun(s));
        // m = (s+e)/2 for bisection method
        if(abs(fun(m)) <= err) {
            cout << "Needed " << count << " iterations\n";
            return m;
        }
        else if(fun(s)*fun(m) > 0) s = m;
        else e = m;
    }
    return m;
}

void srch(double lim, double steps){
    for(double i = -lim; i < lim; i += steps){
        //fun(i) == or fun(i+steps) == 0 not handled
        if(fun(i)*fun(i+steps) < 0){
            // cout << i << " - " << i+steps << endl;
            double root = false_position(i, i+steps);
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