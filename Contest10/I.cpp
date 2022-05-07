#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> A, B;

bool check(int m, int n){
    int created[m][n];
    bool ans = true;

    for(int i=0; i<m && ans; i++){
        for(int j=0; j<n && ans; j++){
            created[i][j] = 0;
            for(int x=0; x<m; x++) created[i][j] |= A[x][j];
            for(int y=0; y<n; y++) created[i][j] |= A[i][y];

            if(created[i][j] != B[i][j]) ans = false;
        }
    }

    return ans;
}

int main(){
    int n, m;
    cin >> m >> n;

    A.assign(m, vector<int> (n, 1));
    B.assign(m, vector<int> (n));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            cin >> B[i][j];
            if(!B[i][j]){
                for(int x=0; x<m; x++) A[x][j] = 0;
                for(int y=0; y<n; y++) A[i][y] = 0;
            }
        }
    
    if(!check(m, n)) cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j) cout << " ";
                cout << A[i][j];
            }

            cout << endl;
        }
    }

    return 0;
}