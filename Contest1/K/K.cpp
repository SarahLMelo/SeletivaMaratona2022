#include <bits/stdc++.h>

using namespace std;

bool find(int n, int x, int y){
    if(n == 3*x + 7*y) return true;
    if(n < 3*x + 7*y) return false;

    if(find(n, x+1, y) == true) return true;
    if(find(n, x, y+1) == true) return true;

    else return false;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(find(n, 0, 0) == true) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}