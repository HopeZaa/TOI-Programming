#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, m, cnt, pond[65][65];
string grid[65], tempg[65];
vector<pair<int, int>> v;
int cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
void dfs(int i, int j, int count){
    if(i < 0 or i >= n or j < 0 or j >= m){
        return ;
    }
    if(grid[i][j] != 'P'){
        return;
    }
    if(grid[i][j] == 'P' and pond[i][j] != -1){
        return;
    }
    pond[i][j] = count;
    dfs(i+1, j, count);
    dfs(i-1, j, count);
    dfs(i, j+1, count);
    dfs(i, j-1, count);
}
pair<int, int> imp(int ii, int jj, int limi, int limj){
    unordered_set<int> us;
    for(int i=ii;i<=limi;++i){
        for(int j=jj;j<=limj;++j){
            if(pond[i][j] != -1){
                us.insert(pond[i][j]);
            }
        }
    }
    return {(limi - ii + 1) * (limj - jj + 1), us.size()};
}
bool chk(int ii, int jj, int limi, int limj){
    for(int i=ii;i<=limi;++i){
        for(int j=jj;j<=limj;++j){
            if(grid[i][j] == 'T'){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin >> m >> n;
    for(int i=0;i<n;++i){
        cin >> grid[i];
    }
    v.emplace_back(0, 0);
    memset(pond, -1, sizeof(pond));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j] == 'P' and pond[i][j] == -1){
                dfs(i, j, cnt);
                ++cnt;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<min(n - i, m - j);++k){
                if(chk(i, j, i + k, j + k)){
                    v.emplace_back(imp(i, j, i + k, j + k));
                }
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first << ' ' << v[0].second;
}
