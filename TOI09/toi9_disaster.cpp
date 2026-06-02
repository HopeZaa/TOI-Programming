
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, start;
vector<pair<int, int>> g[27];
bool vi[301];
void dfs(int u){
    for(auto [v, idx] : g[u]){
        if(vi[idx]){
            continue;
        }
        vi[idx] = true;
        dfs(v);
    }
    cout << char('A' + u) << ' ';
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;++i){
        string text;
        cin >> text;
        g[text[0] - 'A'].emplace_back(text[1] - 'A', i);
        g[text[1] - 'A'].emplace_back(text[0] - 'A', i);
        start = text[0] - 'A';
    }
    for(int i=0;i<26;++i){
        if(g[i].size() % 2){
            start = i;
            break;
        }
    }
    dfs(start);
}
