#include <bits/stdc++.h>

using namespace std;

int check(vector <bool> &v, int k, bool comp){
    int bestAns = 0, l = 0, r = 0, changes = 0;
    while(r<v.size()){
        if(v[r] !=comp){
            if(changes < k) changes++;
            else{
                bestAns = max(bestAns, r-l);
                while(l<r && v[l]==comp) l++;
                l++;

            }
        }
        r++;
    }

    //cout << l << " " << r << "\n";

    bestAns = max(bestAns, r-l);

    return bestAns;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    vector <bool> v;

    cin >> n >> k ;

    for(int i=0; i<n; i++){
        char a;
        cin >> a;

        v.push_back(a=='a');
    }

    int ans = max(check(v, k, 0), check(v, k, 1));

    cout << ans << "\n";
    

    return 0;
}