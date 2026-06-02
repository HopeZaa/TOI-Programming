#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int r, c, n, a[1001][1001], maxN = INT_MIN;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    cin >> r >> c >> n;
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            if(i > n and j > n){
                maxN = max(maxN, a[i][j] - a[i - n][j] - a[i][j - n] + a[i - n][j - n]);
            }
        }
    }
    cout << maxN;
}
