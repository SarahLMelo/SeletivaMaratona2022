#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long a, b, x;
        cin >> a >> b >> x;

        if(b<a) swap(a,b);
        while(a != x && b!= x && b > x){
            b = b-a;
            if(b<a) swap(a,b);
        }

        if(a == x || b == x) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}