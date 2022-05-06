#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

bool cond1(ii a, ii b){
    if(a.first > b.first) return false;
    else if(a.first == b.first) return a.second > b.second;
    
    return true;
}

bool cond2(ii a, ii b){
    if(a.second < b.second) return false;
    else if(a.second == b.second) return a.first < b.first;
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <ii> vm(n), vM(n);

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;

        vm[i] = {x, y};
        vM[i] = {x, y};
    }

    sort(vm.begin(), vm.end(), cond1);
    sort(vM.begin(), vM.end(), cond2);

    vm.pop_back();
    vM.pop_back();

    int x1 = vm[n-2].first, y1, x2, y2 = vM[n-2].second;
    sort(vM.begin(), vM.end(), cond1);
    sort(vm.begin(), vm.end(), cond2);
    y1 = vm[n-2].second;
    x2 = vM[n-2].first;

    cout << max(max(y1-x1, y2-x2), 0) << "\n";

    return 0;
}