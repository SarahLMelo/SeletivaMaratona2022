#include <bits/stdc++.h>

using namespace std;

bool ans = false;

bool bt(vector <int> &v, int pos, int t1, int t2, int size1, int size2){
    if(size1 > 3 || size2 > 3) return false;
    if(pos==6) return t1==t2;

    bool pos1, pos2;
    pos1 = bt(v, pos+1, t1+v[pos], t2, size1+1, size2);
    pos2 = pos1 = bt(v, pos+1, t1, t2+v[pos], size1, size2+1);

    if(pos1 == true || pos2 == true) ans = true;
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <int> v(6);

    for(int i=0; i<6; i++) cin >> v[i];

    bt(v, 0, 0, 0, 0, 0);

    if(ans == true) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}