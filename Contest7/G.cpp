#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long sum(ll x) {
    return x * (x + 1) / 2;
}

bool check(ll n, ll k, ll x){
    if (n >= k) return (sum(k)+sum(k - 1)-sum((2 * k) - 1 - n) >= x); //Soma total - Soma da Parte que não Printou
    else return (sum(n) >= x);
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        ll k;
        ll x;
        cin >> k >> x;
        ll l = 1, r = 2*k - 1;
        while (l <= r) {
            int mid = (l + r)/2;
            if (check(mid, k, x)) r = mid - 1;
            else l = mid + 1;
        }
        cout << min(l, 2*k-1) << endl;
    }
    
    return 0;
}