#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp(int pos){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector <int> a(N);
    vector <int> h(N);
    ll ans = 0;

    for(int i=0; i<N; i++) cin >> h[i];
    for(int i=0; i<N; i++) cin >> a[i];

    ll temp = ans;
    for(int i=1; i<N; i++){
        if(h[i]<=h[i-1]){
            ans = max(ans, temp);
            temp = 0;
        }

        temp += a[i];
    }

    ans = max(ans, temp);

    cout << ans << "\n";


    return 0;
}