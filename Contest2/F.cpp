#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long

#define err 1e-8

int p, q, r, s, t, u;

double eq(double x){
    double ans;
    ans = p*(exp(-x)) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;

    return ans;
}   


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    while(cin >> p){ 
        cin >> q >> r >> s >> t >> u;

        if(p == 0 && q == 0 && r == 0 && s ==0 && t == 0 && u == 0) cout << "0.0000\n";
        else if(eq(1)>0.0 || eq(0) < 0.0) cout << "No solution\n";

        else{
            double l = 0, r = 1.0;
            while(l<(r-err)){
                double m = (l+r)/2;
                if(eq(m)>err) l = m;
                else r = m;

                //cout << l << " " << r << endl;
            }

            printf("%.4lf", l);
            cout << endl;

        }
}

    return 0;
}