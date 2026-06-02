#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n;cin>>n;
    int odd = n,even = n,cnt = 0;
    bool isOdd = false,isEven =false;
    for(int i=0;i<2*n;++i){
        int a;cin>>a;
        // cout<<odd<<' '<<even<<' '<<cnt<<endl;
        if(i == 0){
            if(a%2==0){
                isEven = true;
                --odd;
                cnt = 1;
            }else{
                isOdd = true;
                --even;
                cnt = 1;
            }
            continue;
        }
        if(a%2==0){
            if(isEven){
                ++cnt;
                if(cnt>=3) odd-=3;
                else --odd;
            }else{
                cnt = 1;
                isEven = true;isOdd = false;
                --odd;
            }
        }else{ //odd
            if(isOdd){
                ++cnt;
                if(cnt>=3) even-=3;
                else --even;
            }else{
                cnt = 1;
                isOdd = true;isEven = false;
                --even;
            }
        }
        if(even<=0){
            cout<<1<<endl;
            cout<<a;
            return 0;
        }
        if(odd<=0){
            cout<<0<<endl;
            cout<<a;
            return 0;
        }
    }
}
