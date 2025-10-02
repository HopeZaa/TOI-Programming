#pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    const int mx = 271;
    int n;cin>>n;
    vector<vector<pair<char,int>>> g(mx);
    for(int i=0;i<n;i++){
        char a,b;int c;cin>>a>>b>>c;
        g[a].emplace_back(make_pair(b,c));
        g[b].emplace_back(make_pair(a,c));
    }
    vector<pair<char,pair<char,float>>> ans;
    queue<char> q;
    q.push('X');
    bool vi[mx] = {false},isDone = false;
    float sum = 0,med;
    while(!q.empty()){
        char s = q.front();
        q.pop();
        if(s == 'Y') {isDone = true;break;}
        if(!vi[s]){
            vi[s] = true;
            char adjNode;
            vector<int> dist;
            for(auto e : g[s]){
                if(!vi[e.first]){
                    dist.emplace_back(e.second);
                    adjNode = e.first;
                    q.push(adjNode);
                }
            }
            if(!dist.empty()){
                sort(dist.begin(),dist.end());
                if(dist.size()%2==0) med = (dist[(dist.size()/2)-1]+dist[dist.size()/2])/2.0;
                else med = dist[dist.size()/2];
                sum+=med;
                ans.emplace_back(make_pair(s,make_pair(adjNode,med)));
            }
        }
    }
    if(!isDone){
        cout<<"broken";
        return 0;
    }
    for(auto e : ans){
        cout<<e.first<<" "<<e.second.first<<" ";
        cout<<fixed<<setprecision(1)<<e.second.second<<endl;
    }
    cout<<fixed<<setprecision(1)<<sum;
}
