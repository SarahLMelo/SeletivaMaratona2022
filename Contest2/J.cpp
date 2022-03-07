#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long

bool check(int a, int b){
    return a>-b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector <ll> a(n), b(n), sum(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    for(int i=0; i<n; i++){
        sum[i] = a[i]-b[i];
    }

    sort(sum.begin(), sum.end());
    ll int ans = 0;

    int noNegative = upper_bound(sum.begin(), sum.end(), 0) - sum.begin();

    //for(auto i: sum) cout << i << " ";
    //cout << endl;
    for(int i=noNegative; i<n; i++){
        int j = lower_bound(sum.begin(), sum.end(), -sum[i]+1) - sum.begin();

        //cout << i << " " << j << endl;

        ans+= i-j;
    }

    cout << ans << "\n";

    return 0;
}