#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,a[2501],maxN=0,sum=0,st,temp,end;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(sum>maxN){
            maxN=sum;
            st=temp;
            end=i;
        }
        if(sum<0){
            sum=0;
            temp=i+1;
        }
    }
    if(maxN==0) {
        cout<<"Empty sequence";
        return 0;
    }
    for(int i=st;i<=end;i++) cout<<a[i]<<" ";
    cout<<endl<<maxN;
}
