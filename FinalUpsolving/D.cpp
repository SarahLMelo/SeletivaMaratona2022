#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;

    ll arr[n], smaller = 0;;
    for(int i=0; i<n; i++){
        cin >> arr[n];
        smaller = min(smaller, arr[n]);
    }

    x -= smaller;
    ll preffixSum[n];
    for(int i=0; i<n; i++){
        arr[n] -= smaller;
        if(i) preffixSum[i] = preffixSum[i-1] + arr[i];
        else preffixSum[i] = arr[i];
    }
        
    
    

    return 0;
}