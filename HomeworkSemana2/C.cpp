#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>

int binarySearch(int x, vector <ii> v){
    int l = 0, r = v.size() - 1;

    while(r-l>1){
        int m = (l+r)/2;

        //cout << "l: " << l << " r: " << r << " m: " << m << "\n";
        
        if(v[m].first <= x){
            if(v[m].second >= x){
                return m;
            }
            else l = m;
        }

        else r = m-1;
    }

    if(l==r) return l;
    if(v[l].first <= x && v[l].second >= x) return l;
    return r;
}

int main(){
    int n, t;
    cin >> n;
    vector <ii> v (n);

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(i!=0) v[i].first = v[i-1].second + 1;
        else v[i].first = 1;

        v[i].second = v[i].first - 1 + a;
    }

    cin >> t;
    while(t--){
        int x;
        cin >> x;

        cout << binarySearch(x, v)+1 << "\n";
    }

    return 0;
}