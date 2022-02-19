#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int tdMundocTdMundo = arr[0];

        for(int i=1; i<n; i++){
            tdMundocTdMundo &= arr[i];
        }

        cout << tdMundocTdMundo << "\n";
    }

    return 0;
}