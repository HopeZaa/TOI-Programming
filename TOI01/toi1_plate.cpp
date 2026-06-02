#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> data(m), q; // class, id
    for(auto &[a,b] : data){
        cin >> a >> b;
    }
    while(true){
        char text;
        cin >> text;
        if(text == 'X'){
            cout << 0;
            return 0;
        }
        if(text == 'E'){
            int cl, id, isHave = -1;
            cin >> id;
            for(auto [a,b] : data){
                if(id == b){
                    cl = a;
                }
            }
            for(int i=0;i<q.size();++i){
                if(cl == q[i].first){
                    isHave = i;
                }
            }
            if(isHave == -1){
                q.emplace_back(cl, id);
            }
            else{
                q.insert(q.begin() + isHave + 1, {cl, id});
            }
        }
        if(text == 'D'){
            if(q.empty()){
                cout << "empty" << endl;
            }
            else{
                cout << q[0].second << endl;
                q.erase(q.begin());
            }
        }
    }
}
