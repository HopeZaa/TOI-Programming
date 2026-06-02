#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int findnum(string text){
    if(text=="     |  |") return 1;
    if(text==" _  _||_ ") return 2;
    if(text==" _  _| _|") return 3;
    if(text=="   |_|  |") return 4;
    if(text==" _ |_  _|") return 5;
    if(text==" _ |_ |_|") return 6;
    if(text==" _   |  |") return 7;
    if(text==" _ |_||_|") return 8;
    if(text==" _ |_| _|") return 9;
    if(text==" _ | ||_|") return 0;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    string text1[3],text2[3];
    int n,m,step=0;cin>>n>>m;
    cin.ignore();
    for(int i=0;i<3;i++) getline(cin,text1[i]);
    for(int i=0;i<3;i++) getline(cin,text2[i]);
    long long sumA=0,sumB=0;
    int a[1001]={0},b[1001]={0},cnt=0,tempN=n,tempM=m;
    while(tempN--){
        string temp="";
        for(int i=0;i<3;i++){
            for(int j=step;j<step+3;j++){
                temp+=text1[i][j];
            }
        }
        a[cnt]=findnum(temp);
        cnt++;
        step+=4;
    }
    step=0;cnt=0;
    while(tempM--){
        string temp="";
        for(int i=0;i<3;i++){
            for(int j=step;j<step+3;j++){
                temp+=text2[i][j];
            }
        }
    b[cnt]=findnum(temp);
        cnt++;
        step+=4;
    }
    for(int i=0;i<n;i++) sumA+=a[i]*pow(10,n-i-1);
    for(int i=0;i<m;i++) sumB+=b[i]*pow(10,m-i-1);
    cout<<fixed<<setprecision(0)<<sumA+sumB;
}
