#include <bits/stdc++.h>

using namespace std;

int f(vector <int> &v, int n){
    int ans = 0;

    for(int i=v.size()-1; i>=0; i++){
        while(n>v[i]){
            n /= v[i];
            ans++;
        }
    }

    return ans;
}





int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector <int> v;

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;

            if(temp) v.push_back(temp);
        }


    }

    return 0;
}