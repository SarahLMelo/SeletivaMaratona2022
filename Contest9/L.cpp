#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

__int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> v(n+3, 0);

    for(int i=4; i <= (n+2); i+=2){
        v[i] = 1;
    }

    for(int i=3; i*i <= (n+2); i += 2){
        for(int j = i+i; j <= n+2; j+=i) v[j] = 1;
    }

    if(n > 2) cout << "2\n";
    else cout << "1\n";

    for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << v[i+2]+1;
    }

    cout << "\n";

    return 0;
}