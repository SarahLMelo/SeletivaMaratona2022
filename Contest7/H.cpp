#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        string s = "", n0 = "0", n1 = "1";
        cin >> a >> b >> c;

        if(b==0){
            if(c>0) for(int i=0; i<=c; i++) s += n1;
            if(a>0) for(int i=0; i<=a; i++) s += n0;
        }

        else{
            for(int i=0; i<=a; i++) s += n0;
            for(int i=0; i<c; i++) s += n1;
            for(int i=1; i<b+1; i++){
                if(i%2) s += n1;
                else s += n0;
            }
        }

        cout << s << "\n";

    }

    return 0;
}