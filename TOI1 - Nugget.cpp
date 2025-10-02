#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n,dp[101];cin>>n;
    if(n<6){
        cout<<"no";
        return 0;
    }
    int six = 0,nine = 0,twen = 0;
    dp[0] = 0;
    for(int i=1;i<n;++i){
        int isSix = dp[six] + 6;
        int isNine = dp[nine] + 9;
        int isTwen = dp[twen] + 20;
        int minN = min(isSix,min(isNine,isTwen));
        if(minN>n) return 0;
        dp[i] = minN;
        cout<<minN<<endl;
        if(minN == isSix) ++six;
        if(minN == isNine) ++nine;
        if(minN == isTwen) ++twen;
    }
}
