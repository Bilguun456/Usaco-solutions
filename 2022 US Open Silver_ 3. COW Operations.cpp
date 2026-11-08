#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.length();
    vector<int> l(q, 0), r(q, 0);
    vector<int> prc(n, 0), pro(n, 0), prw(n, 0);
    if(s[0] == 'C')prc[0] = 1;
    else if(s[0] == 'O')pro[0] = 1;
    else{prw[0] = 1;}
    for(int i = 1; i < n; i++){
        if(s[i] == 'C'){
            prc[i] += prc[i-1]+1;
            pro[i] = pro[i-1];
            prw[i] = prw[i-1];
        }
        else if(s[i] == 'O'){
            pro[i] += pro[i-1]+1;
            prc[i] = prc[i-1];
            prw[i] = prw[i-1];
        }   
        else{
            prw[i] += prw[i-1]+1;
            pro[i] = pro[i-1];
            prc[i] = prc[i-1];
        }
    }
    for(int i = 0; i < q; i++){
        cin >> l[i] >> r[i];
    }
    for(int i = 0; i < q; i++){
        if(l[i] == 1){
            if(prc[r[i]-1] % 2 == 0){
                if(pro[r[i]-1] % 2 == 1 && prw[r[i]-1] % 2 == 1){
                    cout << 'Y';
                }
                else{
                    cout << 'N';
                }
            }
            else{
                if(pro[r[i]-1] % 2 == 0 && prw[r[i]-1] % 2 == 0){
                    cout << 'Y';
                }
                else{
                    cout << 'N';
                }
            }
        }
        else{
            if((prc[r[i]-1]-prc[l[i]-2]) % 2 == 0){
                if((pro[r[i]-1]-pro[l[i]-2]) % 2 == 1 && (prw[r[i]-1]-prw[l[i]-2]) % 2 == 1){
                    cout << 'Y';
                }
                else{
                    cout << 'N';
                }
            }
            else{
                if((pro[r[i]-1]-pro[l[i]-2]) % 2 == 0 && (prw[r[i]-1]-prw[l[i]-2]) % 2 == 0){
                    cout << 'Y';
                }
                else{
                    cout << 'N';
                }
            }
        }
    }
    return 0;
}