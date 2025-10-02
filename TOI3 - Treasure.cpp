#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    double x=0,y=0;
    while(1){
        string text,sig;cin>>text;
        if(text=="*") break;
        double n = stof(text);
        double m = n/sqrt(2);
        for(int i=0;i<text.length();i++){
            if(isupper(text[i])) sig+=text[i];
        }
        if(sig=="N") y+=n;
        if(sig=="S") y-=n;
        if(sig=="E") x+=n;
        if(sig=="W") x-=n;
        if(sig=="NE") {x+=m;y+=m;}
        if(sig=="NW") {x-=m;y+=m;}
        if(sig=="SE") {x+=m;y-=m;}
        if(sig=="SW") {x-=m;y-=m;}
    }
    double dist = sqrt(pow((double)x,2)+pow((double)y,2));
    cout<<fixed<<setprecision(3)<<(double)x<<" "<<(double)y<<endl;
    cout<<fixed<<setprecision(3)<<dist;
}
