#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long ll;
 
int main(){
    int n;
    cin >> n;
 
    vector <ll> x, y;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
 
    ll xBest = x[n/2], yBest = y[n/2];
 
    ll distSum = 0;
    for(int i=0; i<n; i++)
        distSum += abs(xBest - x[i]) + abs(yBest - y[i]);
    
    if(!(n%2)){
        ll tempSum = 0;
        for(int i=0; i<n; i++)
            tempSum += abs(x[n/2-1] - x[i]) + abs(y[n/2-1] - y[i]);

        distSum = min(tempSum, distSum);
    }
    
    cout << distSum << "\n";
}