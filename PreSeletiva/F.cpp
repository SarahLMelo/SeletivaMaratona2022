#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    double ans = 0;

    cin >> n;
    for(int i=0; i<n; i++){
        double x, y;
        double a, b;
        cin >> x >> y;

        a = 12.0*(log2(x)-log2(440.0));
        b = 12.0*(log2(y)-log2(440.0));

        if(a-b < 0) ans+=(b-a);
        else ans += (a-b);
    }

    cout << round(ans) << "\n";

    return 0;
}