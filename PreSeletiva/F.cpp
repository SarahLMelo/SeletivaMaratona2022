#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    double ans = 0;

    cin >> n;
    for(int i=0; i<n; i++){
        double a, b;
        cin >> a >> b;
        ans += log2(b/a)*12.0;
    }

    cout << abs(round(ans)) << "\n";

    return 0;
}