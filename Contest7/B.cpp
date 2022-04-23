#include <bits/stdc++.h>

using namespace std;

class sudoku{
    vector <vector <int>> tab;
    bool alreadyPrinted;

    bool validColuna(int j){
        vector <int> v(10, 0);
        for(int i=0; i<9; i++){
            v[tab[i][j]]++;
            if(v[tab[i][j]]>2) return false;
        }

        for(int i=1; i<=9; i++) if(v[i] != 2) return false;

        return true;
    }

    bool validLinha(int i){
        vector <int> v(10, 0);
        for(int j=0; j<9; j++){
            v[tab[i][j]]++;
            if(v[tab[i][j]]>2) return false;
        }

        for(int j=1; j<=9; j++) if(v[j] != 2) return false;

        return true;
    }

    bool validQuadrante(int n){
        vector <int> v(10, 0);
        n++;

        switch (n){
        case 1:
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 2:
            for(int i=0; i<3; i++){
                for(int j=3; j<6; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 3:
            for(int i=0; i<3; i++){
                for(int j=6; j<9; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 4:
            for(int i=3; i<6; i++){
                for(int j=0; j<3; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 5:
            for(int i=3; i<6; i++){
                for(int j=3; j<6; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 6:
            for(int i=3; i<6; i++){
                for(int j=6; j<9; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 7:
            for(int i=6; i<9; i++){
                for(int j=0; j<3; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 8:
            for(int i=6; i<9; i++){
                for(int j=3; j<6; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        case 9:
            for(int i=6; i<9; i++){
                for(int j=6; j<9; j++){
                    v[tab[i][j]]++;
                    if(v[tab[i][j]]>2) return false;
                }
            }

            break;

        }

        for(int j=1; j<=9; j++) if(v[j] != 2) return false;

        return true;
    }

    public:
    sudoku(){
        tab.assign(9, vector<int>(9, 0));
        alreadyPrinted = false;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++) cin >> tab[i][j];
        }
    }

    ~sudoku(){

    }

    bool isValid(){
        bool check = true;
        for(int i=0; i<9 && check; i++){
            check &= validColuna(i);
            check &= validLinha(i);
            check &= validQuadrante(i);
        }

        return check;
    }

    void print(){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++) cout << tab[i][j];
            cout << "\n";
        }
    }

    bool changing(int changesRemaining){
        if(changesRemaining < 0) return false;
        
        bool ans = false;

        for(int i=0; i<9  && !ans; i++){
            for(int j=0; j<9  && !ans; j++){
                int original = tab[i][j];

                for(int k = 1; k<10  && !ans; k++){
                    tab[i][j] = k;
                    ans |= isValid();
                    if(k != original && !ans){
                        ans |= changing(changesRemaining-1);
                        if(!ans) tab[i][j] = original;
                    }
                }
            }
        }

        if(ans && !alreadyPrinted) print();

        return ans;
    }

    void solve(){
        isValid();
        changing(8);
    }

};

int main(){
    int t;
    cin >> t;

    while(t--){
        sudoku s;
    }

    return 0;
}