#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
//#define int long long

ii grid[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, c;
    cin >> n >> q >> c;

    for(int i=0; i<n; i++){
        int x, y, s;
        cin >> x >> y >> s;

        grid[x][y].first += s;
        grid[x][y].second++;;
    }

    while(q--){
        int ans = 0, x1, x2, y1, y2, t;

        cin >> t >> x1 >> y1 >> x2 >> y2;

        for(int i=x1; i<=x2; i++){
            for(int j = y1; j<=y2; j++){
                if(!grid[i][j].second) continue;

                ans += (grid[i][j].first)%(c+1) * grid[i][j].second*t;
            }
        }

        cout << ans << "\n";
    }

  return 0;
}


//x + t + y + t + z + t -> x + y + z + 3*t

/* 1 + 2 + 3 mod 6 == 1 mod 2 + 2 mod 2 + 3 mod 2
   6 mod 6 == 1 + 0 + 1
   0 == 2
*/