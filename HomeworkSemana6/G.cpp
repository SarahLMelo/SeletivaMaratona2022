#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n){
    vector <int> ans;
    if(!(n%2)){
        ans.push_back(2);
        while(!(n%2)) n /=2;
    }

    for(int i=3; i*i <= n; i+=2){
        if(!(n%i)){
            ans.push_back(i);
            while(!(n%i)) n /= i;
        }
    }

    if(n!=1) ans.push_back(n);

    return ans;
}

int main(){

    int t;
    cin >> t;

    for(int k = 1; k<= t; k++){
        int n;
        cin >> n;

        vector <int> ans = solve(n);

        cout << "Case " << k << ":";

        for(int i=0; i<ans.size(); i++){
            cout << " " << ans[i];
        }

        cout << endl;
    }

    return 0;
}