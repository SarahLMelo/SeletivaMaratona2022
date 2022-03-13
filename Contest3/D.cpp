#include <bits/stdc++.h>

using namespace std;

#define ii pair <int, int>

int main(){
    int t;
    cin >> t;

    vector <int> arr(t);

    for(int i=0; i<t; i++) cin >> arr[i];

    int ans = 1;
    int dontkill = t-1 - arr[t-1];
    

    for(int i = t-2; i>=0; i--){
        if(dontkill > i) ans++;
        dontkill = min(dontkill, i - arr[i]);
    }

    cout << ans << endl;
}