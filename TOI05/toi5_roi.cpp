#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);cout.tie(0);
    double n, maxN = INT_MAX;
    cin >> n;
    int a, b;
    for(int i=1000;i<=15000;i += 500){
        for(int j=74;j<=144;++j){
            double fund = n + (i * (100 - ((i - 1000) / 500)));
            double num = ((100 - (0.8569 * exp(0.09 * (j-100)))) * i) / 100;
            double sell = num * j;
            if(sell > fund and maxN > sell - fund){
                maxN = sell - fund;
                a = i, b = j;
            }
        }
    }
    printf("%d\n%d\n%.2lf",a ,b ,maxN);
}
