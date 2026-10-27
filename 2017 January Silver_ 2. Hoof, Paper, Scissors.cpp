#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    vector<char> a(n);
    vector<int> h(n, 0),p(n, 0),s(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(a[0] == 'H'){
        h[0] = 1;
        p[0] = 0;
        s[0] = 0;
    }
    else if(a[0] == 'P'){
        h[0] = 0;
        p[0] = 1;
        s[0] = 0;
    }
    else{
        h[0] = 0;
        p[0] = 0;
        s[0] = 1;
    }
    for(int i = 1; i < n; i++){
        if(a[i] == 'H'){
            h[i] = h[i-1]+1;
            p[i] = p[i-1];
            s[i] = s[i-1];
        }
        else if(a[i] == 'P'){
            h[i] = h[i-1];
            p[i] = p[i-1]+1;
            s[i] = s[i-1];
        }
        else{
            h[i] = h[i-1];
            p[i] = p[i-1];
            s[i] = s[i-1]+1;
        }
    }
    int ans = max({h[n-1],p[n-1],s[n-1]});
    for(int i = 1; i < n; i++){
        ans = max(ans, max({h[i-1],p[i-1],s[i-1]})+max({(h[n-1]-h[i-1]), (p[n-1]-p[i-1]), (s[n-1]-s[i-1])}));
    }
    cout << ans;
}