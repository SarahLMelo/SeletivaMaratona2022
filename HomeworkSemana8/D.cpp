#include <bits/stdc++.h>

using namespace std;

int maskMake(string &s){
    vector <int> v(26, 0);
    int ans = 0;

    for(auto i:s) v[i - 'a']++;

    for(int i=0; i<26; i++){
        ans <<= 1;
        ans += (v[i]%2);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map <long long, long long> bitmask;
    long long ans = 0;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        bitmask[maskMake(s)]++;
    }

    for(auto i:bitmask){ //1 0 0 0 1 1 0 -> 0 0 0 0 1 1 0
        for(int j=0; j<26; j++){
            int x = i.first;
            int temp = 1;
            temp <<= j;

            x ^= temp;

            if(bitmask.find(x) != bitmask.end()) ans += (1ll*i.second*bitmask[x]);
        }

        ans += (1ll*i.second*(i.second-1));
    }

    cout << ans/2 << "\n";

    return 0;
}