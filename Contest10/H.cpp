#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector <int> line(n);
    bool nFound = true;

    for(int i=0; i<n; i++) cin >> line[i];

    sort(line.begin(), line.end());

    for(int i=1; i<n-1 && nFound; i++){
        //TESTANDO A DESIGUALDADE TRIANGULAR
        if(line[i-1] + line[i] > line[i+1]) nFound = false;
    }

    if(nFound) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}