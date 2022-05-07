#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);
    string b;

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cin >> b;

    int l = -1e9, r = 1e9;

    for(int i=3; i<n; i++){
        if(b[i] == b[i-1]) continue;
        if(b[i] == '1'){
            l = max(l, *max_element(a.begin()+i-3, a.begin()+i+1)+1);
        }
        if(b[i] == '0') r = min(r, *min_element(a.begin()+i-4, a.begin()+i+1)-1);
    }

    //r = max(l, r);

    cout << l << " " << r << "\n";

    return 0;
}