#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int last = s.back() - '0';
    if(s.size() > 1) last += (10*(s[s.size()-2] - '0'));
    last %=4;

    int ans = (1 + (int)round(pow(2, last)) + (int)round(pow(3, last)) + (int)round(pow(4, last)))%5;

    cout << ans << "\n";

    return 0;
}