#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n,sum = 0;cin>>n;
    while(n>0){
        if(n == 1){
            --n;
            sum+=500;
        }
        else if(n>=2 and n<4){
            n-=2;
            sum+=800;
        }
        else if(n>=4 and n<9){
            n-=5;
            sum+=1500;
        }
        else{
            n-=15;
            sum+=3000;
        }
    }
    cout<<sum;
}
