#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> idx;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            idx.push_back({i, j});
        }
    }
    vector<vector<double>> ori(n,vector<double>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> ori[i][j];
        }
    }
    double minN = numeric_limits<double>::max();
    do{
        double sum = 0;
        vector<vector<double>> a = ori;
        for(auto [i, j] : idx){
            sum += a[i][j];
            int ii[] = {-1,-1,-1,0,0,1,1,1}, jj[] = {-1,0,1,-1,1,-1,0,1};
            for(int k=0;k<8;++k){
                int ni = i + ii[k], nj = j + jj[k];
                if(ni >= 0 and ni < n and nj >= 0 and nj < m){
                    a[ni][nj] += a[i][j] * 0.1;
                }
            }
        }
        minN = min(minN, sum);
    }while(next_permutation(idx.begin(), idx.end()));
    cout << fixed << setprecision(2) << minN;
}
