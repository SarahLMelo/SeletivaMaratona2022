#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int sizeInTheEnd = 0;

    while(s.back() == t.back() && s.size() > 0 && t.size() > 0){
        sizeInTheEnd++;
        s.pop_back();
        t.pop_back();
    }

    cout << s.size()+t.size() << "\n";

    return 0;
}