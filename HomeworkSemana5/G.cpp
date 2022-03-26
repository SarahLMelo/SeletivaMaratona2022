#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector <int> v;
        int l = -1, r = 0;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            if(a) v.push_back(a);
        }

        for(int i=0; i<v.size(); i++){
            //if(v[i] == 0 && i == r) continue;
            if(i != 0) cout << " ";
            cout << v[i];
        }

        if(v.empty()) cout << "0";
        
        cout << endl;
    }

    return 0;
}