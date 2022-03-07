#include <bits/stdc++.h>

using namespace std;

bool check(int k, vector <int> &stair){
    bool ans = true;
    int lastPos = 0;
    for(auto i:stair){
        if(i-lastPos>k){
            ans = false;
            break;
        }
        else if(i-lastPos == k) k--;

        lastPos = i;
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    for(int k=1; k<=t; k++){
        int n;
        cin >> n;
        vector <int> stair(n);

        for(int i=0; i<n; i++) cin >> stair[i];

        int l=0, r = stair[n-1];
        while(l!=r){
            int m = (l+r)/2;
            if(check(m, stair) == false) l = m+1;
            else r = m;
        }

        cout << "Case " << k << ": " << l << "\n";
    }
    
    return 0;
}