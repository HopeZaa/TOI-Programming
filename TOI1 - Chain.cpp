#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int a,b;cin>>a>>b;
    string now;cin>>now;
    while(--b){
        string text;cin>>text;
        int cnt = 0;
        for(int i=0;i<a;++i){
            if(now[i] != text[i]){
                cnt++;
                if(cnt>2){
                    cout<<now;
                    return 0;
                }
            }
        }
        now = text;
    }
    cout<<now;
}
