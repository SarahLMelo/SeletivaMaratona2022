#include <bits/stdc++.h>

using namespace std;

bool isEquivalent(string &a, string &b, int abegin, int aend, int bbegin, int bend){
    bool ans = true;
    for(int i = abegin; i<aend; i++)
        if(a[i]!=b[bbegin+i-abegin]) ans = false;
    if(ans == true) return true;

    if(((aend-abegin)%2 == 1) || (bend-bbegin)%2 == 1) return false;

    bool ans1 = false, ans2 = false;

    ans1 = isEquivalent(a, b, abegin, (abegin+aend)/2, bbegin, (bbegin+bend)/2);
    if(ans1 == true) ans1 = isEquivalent(a, b, (abegin+aend)/2, aend, (bbegin+bend)/2, bend);
    if(ans1 == false) ans2 = isEquivalent(a, b, abegin, (abegin+aend)/2,(bbegin+bend)/2, bend);
    if(ans2 == true) ans2 = isEquivalent(a, b, (abegin+aend)/2, aend, bbegin, (bbegin+bend)/2);

    return ans2 | ans1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    if(isEquivalent(a, b, 0, a.size(), 0, b.size()) == true) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
