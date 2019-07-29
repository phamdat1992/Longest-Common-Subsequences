/*
  This is implemented by Nhat Nam Ha
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> Matchlist[256];
int L[1000005] ={0};
bool ch[256] = {0};

int HuntSzymanski(string a, string b){
    int i,j,k, high, low, mid;
    int m,n,idx;
    m = a.size(); n = b.size();
    for(i = 0; i < 1000005; i++) L[i] = -1;
    for (i = 0; i < m; i++){
        idx = int(a[i]);
        if(Matchlist[idx].empty()) {
            for(j = n-1; j >= 0; j--){
                if (a[i] == b[j])
                    Matchlist[idx].push_back(j);
            }
        }
    }
    int si, LCS = 0;
    for (i = 0; i < m; i++){
        idx = int(a[i]); //if(ch[idx]) continue;
        si = Matchlist[idx].size(); ch[idx]=1;
        for (j = 0; j < si; j++){
            if(Matchlist[idx][j] > L[LCS]){
                LCS++;
                L[LCS] = Matchlist[idx][j];
                continue;
            }
            low = 0; high = LCS; k = 0;
            while (true){
                mid = (low+high) >> 1;
                if (L[mid] == Matchlist[idx][j]){
                    k = 1; break;
                }
                if (high - low <= 1){
                    mid = high;  break;
                }
                if (L[mid] > Matchlist[idx][j]) high = mid;
                else if(L[mid] < Matchlist[idx][j]) low = mid;
            }
            if (k == 0) L[mid] = Matchlist[idx][j];
        }
    }
    return LCS;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a,b; cin >> a >> b; cout << HuntSzymanski(a,b);
    return 0;
}
