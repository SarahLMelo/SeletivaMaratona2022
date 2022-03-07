#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t, k;
    cin >> n >> t >> k;

    t = 19;
    bool findAns = false;

    int l = 1, r = n+1;

    while(t-- && l<r){
        int m = (l+r)/2;
        int sum, amount0;
        cout << "?" << l << " " << m << endl;
        cin >> sum;
        
        amount0 = m - l - sum + 1;
        if(k>amount0){
            l = m+1;
            k -= amount0;
        }
        else r = m;
    }

    cout << "! " << l << endl;

    return 0;
}