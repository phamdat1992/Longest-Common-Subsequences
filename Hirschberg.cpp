/**
 * @author: Nhat Nam Ha
 * @organization: 
 * @email: 
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int matrix[2][100005];
int Hirschberg(string a, string b){
    int i,j; memset(matrix,0,sizeof(matrix));
    int last, now, ans = 0, m ,n;
    last = 1; now = 0;
    m = a.size();  n = b.size();
    for(i = 1; i <= m; i++){
        swap(last,now);
        for(j = 1; j <= n; j++)
        if (a[i-1] == b[j-1]){
            matrix[now][j] = matrix[last][j - 1] + 1;
        }
        else{
            if (matrix[now][j - 1] > matrix[last][j])
               matrix[now][j] = matrix[now][j - 1];
            else
               matrix[now][j] = matrix[last][j];
        }
    }
    for (i = 1; i <= max(m,n); i++){
        ans = max(ans,matrix[0][i]);
        ans = max(ans,matrix[1][i]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a,b; cin >> a >> b; cout << Hirschberg(a,b);
    return 0;
}
