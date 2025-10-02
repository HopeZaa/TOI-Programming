#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int c, r, q, grid[51][51];
ll dp[51][51];

ll dfs(int i, int j){
    if(i < 0 || j >= c || grid[i][j] == 1) return 0;
    if(i == 0 && j == c-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = dfs(i-1, j) + dfs(i, j+1);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> r >> q;
    memset(dp, -1, sizeof(dp));
    while(q--){
        int a, b;
        cin >> a >> b;
        grid[r-b][a-1] = 1;
    }
    cout << dfs(r-1, 0);
}
