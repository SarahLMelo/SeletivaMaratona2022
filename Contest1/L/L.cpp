#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector <long long int> sum(n-k+1, 0);

    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<k; i++){
        sum[0] += arr[i];
    }

    for(int i=1; i<n-k+1; i++){
        sum[i] = sum[i-1];
        sum[i] -= arr[i-1];
        sum[i] += arr[i+k-1];
    }

    int min=0xf3f3f3, posMin = 0;
    for(int i=0; i<n-k+1; i++){
        if(sum[i]<min){
            min = sum[i];
            posMin = i;
        }
    }

    cout << posMin+1 << "\n";

    return 0;
}