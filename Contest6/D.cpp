#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

vector <ii> primes(int n){
    vector <ii> ans;

    if(!(n%2)){
        int exp = 0;
        while(!(n%2)){
            exp++;
            n /=2;
        }
        ans.push_back({2, exp});
    }

    for(int i=3; i*i<= n; i +=2){
        if(!(n%i)){
            int exp = 0;
            while(!(n%i)){
                exp++;
                n /=i;
            }
            ans.push_back({i, exp});
        }
    }

    if(n>1) ans.push_back({n, 1});

    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        ll x, a, b, c;
        cin >> x >> a >> b >> c;

        if(x==1){ //Não Há Outra Opção
            cout << c+x << "\n";
        }
        else{
            vector <ii> fat = primes(x);
            if(fat.size() == 1 && fat[0].second == 1) //É primo
                cout << c+x << "\n";
            
            int maiorNComposto = x / fat[0].first, maiorNPrimo = fat[fat.size()-1].first;
            if(maiorNComposto == maiorNPrimo){ //Então não tem composto
                cout << min(c+x, a + (x/maiorNPrimo)) << "\n";
            }
            else{
                ll ans = c + x;
                ans = min(ans, b + (x/maiorNComposto));
                ans = min(ans, a + (x/maiorNPrimo));

                cout << ans << "\n";
            }
        }

    }

    return 0;
}

// 2^2 * 3^1