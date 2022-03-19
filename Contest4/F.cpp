#include <bits/stdc++.h>

using namespace std;

void round(string &s){
    for(int i=1; i<s.size(); i++){
        if(s[i] == 'G' && s[i-1] == 'B'){
            s[i] = 'B';
            s[i-1] = 'G';
            i++;
        }
    }
}

int main(){
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    while(t--) round(s);

    cout << s << "\n";

    return 0;
}