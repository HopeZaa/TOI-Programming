#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int mx = 1e6+1;
bool vi[mx];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n,m;cin>>n>>m;
    int num = 0,i = 1,cnt = 1;
    while(num<n){
        if(i>n) i%=n;
        if(vi[i]){
            ++i;
            continue;
        }
        if(cnt == m){
            cout<<i<<' ';
            cnt = 0;
            vi[i] = true;
            ++num;
        }
        ++i;++cnt;
    }
}
