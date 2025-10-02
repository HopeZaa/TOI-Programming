#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n;cin>>n;
    int i = 0,v = 0,x = 0,l = 0,c = 0;
    //  1     5     10    50    100
    for(int j=1;j<=n;++j){
        int a = j;
        if(a>=100){
            c+=(a/100);
            a%=100;
        }if(a>=90){
            x+=1;
            c+=1;
            a%=90;
        }if(a>=50){
            l+=1;
            a%=50;
        }if(a>=40){
            x+=1;
            l+=1;
            a%=40;
        }if(a>=10){
            x+=(a/10);
            a%=10;
        }if(a==9){
            x+=1;
            i+=1;
            a%=9;
        }if(a>=5){
            v+=1;
            a%=5;
        }if(a==4){
            i+=1;
            v+=1;
            a%=4;
        }if(a>=1){
            i+=a;
            a=0;
        }
    }
    cout<<i<<' '<<v<<' '<<x<<' '<<l<<' '<<c<<endl;
}
