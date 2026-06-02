#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--){
        int dice[]={1,2,3,5,4,6};
        string text;cin>>text;
        for(int i=0;i<text.length();i++){
            if(text[i]=='F'){
                swap(dice[0],dice[1]);
                swap(dice[3],dice[5]);
                swap(dice[0],dice[5]);
            }
            if(text[i]=='B'){
                swap(dice[0],dice[1]);
                swap(dice[1],dice[5]);
                swap(dice[3],dice[5]);
            }
            if(text[i]=='L'){
                swap(dice[0],dice[2]);
                swap(dice[0],dice[5]);
                swap(dice[0],dice[4]);
            }
            if(text[i]=='R'){
                swap(dice[0],dice[2]);
                swap(dice[2],dice[4]);
                swap(dice[2],dice[5]);
            }
            if(text[i]=='C'){
                swap(dice[1],dice[2]);
                swap(dice[3],dice[1]);
                swap(dice[1],dice[4]);
            }
            if(text[i]=='D'){
                swap(dice[2],dice[1]);
                swap(dice[2],dice[3]);
                swap(dice[3],dice[4]);
            }
        }
        cout<<dice[1]<<" ";
    }
}
