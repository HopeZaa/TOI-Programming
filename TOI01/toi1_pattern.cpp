#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n,maxN = INT_MIN;cin>>n;
    bool isPat[50001][71];
    while(n--){
        int a,b,c;cin>>a>>b>>c;
        for(int i=b-1;i<min(b+c-1,70);++i) isPat[a-1][i] = true;
        maxN = max(maxN,a);
    }
    for(int i=0;i<maxN;++i){
        for(int j=0;j<70;++j){
            cout<<(isPat[i][j] ? 'x' : 'o');
        }
        cout<<endl;
    }
}
