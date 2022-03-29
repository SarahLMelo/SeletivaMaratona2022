#include <bits/stdc++.h>

using namespace std;

bool check(vector <int> &v, int n){
    bool ans = true;

    for(auto i:v) if(i != n) ans = false;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);

        for(int i=0; i<n; i++) cin >> v[i];

        int p = n-1, cnt = 0;

        while(p>=0){
            if(v[p] == v[n-1]) p--; // 0 1 2 3 4 5
            else{
                int x = n - p;
                p = n - 2*x; 
                p = max(-1, p);
                cnt++;
            }
        }

        cout << cnt << "\n";

    }

    return 0;
}