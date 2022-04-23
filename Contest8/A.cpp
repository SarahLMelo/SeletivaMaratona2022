#include <bits/stdc++.h>

using namespace std;

bool solve(){
    string s;
    cin >> s;

    vector <int> freq(2, 0);

    if(s[0] == '0') return false;
    if(s.back() == '1') return false;

    for(auto i:s){
        if(i == '1') freq[1]++;
        else freq[0]++;
    }

    //cout << freq[0] << " " << freq[1] << "\n";

    if(2*freq[1] == freq[0]) return true;
    return false;
}

int main(){
    int t;
    cin >> t;

    for(int i=1; i<=t; i++){
        if(solve()) cout << "Case " << i << ": yes\n";
        else cout << "Case " << i << ": no\n";
    }

    return 0;
}