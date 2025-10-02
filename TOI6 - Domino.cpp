#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void recur(int n,string text){
    if(n == 0){
        cout<<text<<'E'<<endl;
        return;
    }
    recur(n-1,text+"--\n");
    if(n>1) recur(n-2,text+"||\n");
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n;cin>>n;
    recur(n,"");
}
