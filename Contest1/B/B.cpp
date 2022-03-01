#include <bits/stdc++.h>

using namespace std;

vector<set <vector <int>>> dictionary (25);

vector <int> generateFreqVec(string s){
    vector <int> ans (26, 0);
    for(auto i:s){
        ans[i-'a']++;
    }

    return ans;
}

int main(){
    int l, c;
    int ans = 0;
    cin >> l >> c;
    char matriz[l][c];
    vector <vector <int>> coloring (l, vector <int> (c, 0));

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            cin >> matriz[i][j];
        }
    }

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        dictionary[i].emplace(generateFreqVec(s));
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            for(int k=0; j+k<c || i+k<l; k++){
                string ssl, ssc, ssd1, ssd2;
                vector <int> sl, sc, sd1, sd2;
                for(int a = 0; a<=k; a++){
                    if(j+a<c) ssl += matriz[i][j+a];
                    if(i+a<l) ssc += matriz[i+a][j];
                    if(i+a<l && j+a<c)ssd1 += matriz[i+a][j+a];
                    if(i+a<l && j-a>=0)ssd2 += matriz[i+a][j-a];
                }

                if(j+k<c) sl = generateFreqVec(ssl);
                if(i+k<l) sc = generateFreqVec(ssc);
                if(i+k<l && j+k<c) sd1 = generateFreqVec(ssd1);
                if(i+k<l && j-k>=0) sd2 = generateFreqVec(ssd2);

                for(int b=0; b<n; b++){
                    if(!sl.empty() && dictionary[i].find(sl) != dictionary[i].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i][j+a] != 0 && coloring[i][j+a] != b+1 && coloring[i][j+a] != 21){
                                coloring[i][j+a] = 21;
                                ans++;
                            }
                            else if(coloring[i][j+a] != 21) coloring[i][j+a]=b+1;
                        }
                    }
                    
                    if(!sc.empty() && dictionary[i].find(sc) != dictionary[i].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i+a][j] != 0 && coloring[i+a][j] != b+1 && coloring[i+a][j] != 21){
                                coloring[i+a][j] = 21;
                                ans++;
                            }
                            else if(coloring[i+a][j] != 21) coloring[i+a][j]=b+1;
                        }
                    }

                    if(!sd1.empty() &&  dictionary[i].find(sd1) != dictionary[i].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i+a][j+a] != 0 && coloring[i+a][j+a] != b+1 && coloring[i+a][j+a] != 21){
                                coloring[i+a][j+a] = 21;
                                ans++;
                            }
                            else if(coloring[i+a][j+a] != 21) coloring[i+a][j+a]=b+1;
                        }
                    }

                    if(!sd2.empty() && dictionary[i].find(sd2) != dictionary[i].end()){
                        for(int a = 0; a<=k; a++){
                            if(coloring[i+a][j-a] != 0 && coloring[i+a][j-a] != b+1 && coloring[i+a][j-a] != 21){
                                coloring[i+a][j-a] = 21;
                                ans++;
                            }
                            else if(coloring[i+a][j+a] != 21) coloring[i+a][j-a]=b+1;
                        }
                    }  
                }
            }
        }
    }
    /*for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            //cout << coloring[i][j];
            if(coloring[i][j]==21) ans++;
        }
        //cout << endl;
    }
    //cout << endl;*/

    cout << ans << "\n";

    return 0;
}