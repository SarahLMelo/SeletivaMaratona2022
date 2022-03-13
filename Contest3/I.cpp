#include <bits/stdc++.h>

using namespace std;

#define ii pair <int, int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string alphabet;
        string sentence;
        cin >> alphabet >> sentence;

        int ans = 0;
        int cur = alphabet.find(sentence[0]);

        for(int i=1; i<sentence.size(); i++){
            int newCur = alphabet.find(sentence[i]);
            ans += abs(newCur-cur);
            cur = newCur;
        }

        cout << ans << "\n";
    }


    return 0;
}