#include <bits/stdc++.h>

using namespace std;

bool isColinear(pair <int, int> a, pair <int, int> b, pair <int, int> origin){
    long long x1 = origin.first - a.first, y1 = origin.second - a.second, x2 = a.first - b.first, y2 = a.second - b.second;

    return (x1*y2 == x2*y1);
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;

    vector <pair <int, int>> v(n);
    vector <pair <int, int>> ans;

    for(int i=0; i<n; i++)
        cin >> v[i].first >> v[i].second;
    
    for(int i=0; i<n; i++){
        if(ans.empty()){
            ans.push_back({v[i].first, v[i].second});
            continue;
        }

        bool notFound = true;
        for(int j=0; j<ans.size() && notFound; j++)
            if(isColinear(v[i], ans[j], {x, y})){
                notFound = false;
                continue;
            }
        
        if(notFound) ans.push_back(v[i]);
    }

    cout << ans.size() << "\n";

    return 0;
}