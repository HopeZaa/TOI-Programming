#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    string data[] = {"", "ABC" ,"DEF" ,"GHI" ,"JKL" ,"MNO" ,"PQRS" ,"TUV" ,"WXYZ"};
    int q, a, b, c;
    cin >> q >> a >> b;
    vector<char> v;
    if(a != 1){
        v.push_back(data[a - 1][(b - 1) % data[a - 1].length()]);
    }
    pair<int, int> idx = {(a - 1) / 3, (a - 1) % 3};
    while(--q){
        cin >> a >> b >> c;
        idx.first += b;
        idx.second += a;
        int num = (idx.first * 3) + idx.second;
        if(num == 0){
            while(c--){
                if(v.empty()){
                    break;
                }
                v.pop_back();
            }
        }
        else{
            v.push_back(data[num][(c - 1) % data[num].length()]);
        }
    }
    if(v.empty()){
        cout << "null";
        return 0;
    }
    for(auto e : v){
        cout << e;
    }
}
