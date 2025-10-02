#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int mx = 8e6+1;
bool isPrime[mx];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n;cin>>n;
    for(int i=2;i<mx;++i){
        for(int j=i*2;j<mx;j+=i) isPrime[j] = true;
    }
    int cnt = 1;
    for(int i=2;i<mx;++i){
        if(!isPrime[i]){
            if(cnt == n){
                cout<<i;
                return 0;
            }
            ++cnt;
        }
    }
}
