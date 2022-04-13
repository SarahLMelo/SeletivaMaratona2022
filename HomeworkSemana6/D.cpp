#include <bits/stdc++.h>

using namespace std;
<<<<<<< Updated upstream

int primesExp(int x){
    int ans = 0;
    while(!(x%2)){
        ans++;
        x /=2;
    }

    for(int i=3; i*i<=x; i+=2){
        while(!(x%i)){
            ans++;
            x /=i;
        }
    }

    if(x>1) ans++;

    return ans;
}

=======
typedef long long ll;

ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a,b);
    }

    return a;
}


>>>>>>> Stashed changes
int main(){
    int t;
    cin >> t;

    while(t--){
<<<<<<< Updated upstream
        int a, b, n;
        cin >> a >> b >> n;

        int max, min, gcd = __gcd(a, b);
        max = primesExp(a) + primesExp(b);
        if(a == b) min = 0;
        else if(gcd == b || gcd == a) min = 1;
        else min = 2;

        if(min <= n && max >= n && n!=1) cout << "YES\n";
        else if(min == 1 && n==1) cout << "YES\n";
        else cout << "NO\n";
=======
        
>>>>>>> Stashed changes
    }

    return 0;
}