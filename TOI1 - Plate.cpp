#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n,m,idx = 0;cin>>n>>m;
    vector<pair<int,int>> v(m),q;
    for(auto &[a,b] : v) cin>>a>>b;
    while(1){
        char text;cin>>text;
        if(text == 'X') {cout<<0;return 0;}
        if(text == 'E'){
            int cl,id;cin>>id;
            for(auto [a,b] : v) if(b == id) cl = a;
            if(!q.empty()){
                bool isInsert = false;
                for(int i=0;i<q.size();++i){
                    if(q[i].first == cl and q[i+1].first != cl){
                        q.insert(q.begin()+i+1,{cl,id});
                        isInsert = true;
                        break;
                    }
                }
                if(!isInsert) q.push_back({cl,id});
            }else q.push_back({cl,id});
        }
        if(text == 'D'){
            if(!q.empty()){
                cout<<q[0].second<<endl;
                q.erase(q.begin());
            }
            else cout<<"empty"<<endl;
        }

    }
}
