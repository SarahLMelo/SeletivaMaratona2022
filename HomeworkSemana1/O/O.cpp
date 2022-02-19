#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    while(q--){
        int d;
        cin >> d;
        
        vector <int> maximos;
        for(int i=0; i+d-1 < n; i++){
            maximos.push_back(*max_element(arr.begin()+i, arr.begin()+i+d));
        }

        cout << *min_element(maximos.begin(), maximos.end()) << "\n";
    }
    
    return 0;
}