#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, n;
    cin >> c >> n;

    while(c != 0){
        vector <vector <int>> sobras(n);
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;

            sobras[x%c].push_back(i);
        }

        bool nFound = true;

        for(int i=2; i<=n; i++){

        }

        cin >> c >> n;
    }

    return 0;
}