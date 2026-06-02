#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, m, vi[101][101];
vector<pair<int, int>> grid[101][101];
void bfs(int initi, int initj){
    queue<pair<int, int>> q;
    q.emplace(initi, initj);
    vi[initi][initj] = 1;
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(auto [ni, nj] : grid[i][j]){
            if(vi[ni][nj]){
                if(vi[ni][nj] == vi[i][j] + 1){
                    cout << vi[ni][nj] << endl << ni << ' ' << nj;
                    exit(0);
                }
                continue;
            }
            vi[ni][nj] = vi[i][j] + 1;
            q.emplace(ni, nj);
        }
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            char text;
            cin >> text;
            if(text == 'R'){
                grid[i][j].emplace_back(i, j + 1);
                grid[i][j + 1].emplace_back(i, j);
            }
            if(text == 'D'){
                grid[i][j].emplace_back(i + 1, j);
                grid[i + 1][j].emplace_back(i, j);
            }
            if(text == 'B'){
                grid[i][j].emplace_back(i, j + 1);
                grid[i][j + 1].emplace_back(i, j);
                grid[i][j].emplace_back(i + 1, j);
                grid[i + 1][j].emplace_back(i, j);
            }
        }
    }
    bfs(1, 1);
}
