#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
string grid[2001];
bool vi[2001][2001];
int n, m, ans;
void dfs(int initi, int initj){
    int ii[] = {-1, -1, -1, 0, 0, 1, 1, 1}, jj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    stack<pair<int, int>> st;
    st.emplace(initi, initj);
    while(!st.empty()){
        auto [i, j] = st.top();
        st.pop();
        for(int k=0;k<8;++k){
            int ni = i + ii[k], nj = j + jj[k];
            if(ni < 0 or ni >= n or nj < 0 or nj >= m or grid[ni][nj] == '0' or vi[ni][nj]){
                continue;
            }
            vi[ni][nj] = true;
            st.emplace(ni, nj);
        }
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> grid[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j] == '1' and !vi[i][j]){
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}
