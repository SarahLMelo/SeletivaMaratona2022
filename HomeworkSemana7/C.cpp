#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, ans = 0;

    cin >> n;
    
    ll arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];

        if(i>1 && arr[i] < arr[i-1] && arr[i-1] < arr[i-2]) ans++;
    }

    cout << ans << "\n";

    return 0;
}