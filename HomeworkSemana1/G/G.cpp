#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tv1 = -1, tv2 = -1;
    bool flag = true;
    vector <pair <int, int>> v;
    cin >> n;

    for(int i=0; i<n; i++){
        int b, e;
        cin >> b >> e;

        v.push_back({b, e});
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n && flag == true; i++){
        if(tv1<v[i].first) tv1 = v[i].second;
        else if(tv2<v[i].first) tv2 = v[i].second;
        else flag = false;
    }

    if(flag == true) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}