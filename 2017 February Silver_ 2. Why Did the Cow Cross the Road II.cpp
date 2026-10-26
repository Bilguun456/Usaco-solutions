#include <bits/stdc++.h>
using namespace std;
int main (){
    int n,k,b;
    cin >> n >> k >> b;
    vector<int> a(b, 0);
    vector<int> c(n+1, 0);
    for(int i = 0; i < b; i++){
        cin >> a[i];
        c[a[i]] = 1;
    }
    long long cnt = 0;
    long long ans = INT_MAX;
    for(int r = 1; r <= n; r++){
        cnt += c[r];
        if(r > k) cnt-= c[r-k];
        if(r >= k)ans = min(ans,cnt);
    }
    cout << ans;
    return 0;
}