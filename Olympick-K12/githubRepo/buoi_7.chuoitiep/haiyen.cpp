#include <bits/stdc++.h>
//ktra xem xau nhap vao co tao dk thanh xau "hackerrank" hay khong

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s1="hackerrank";
    for (int i=1; i<=n; i++){
        string s;
        cin>>s;
        int vt1,vt=0,dem=0;
        for (int j=0; j<s1.length(); j++){
            if (s.find(s1[j],vt)==-1){
                dem=0;
                break;
            } else {
            dem++;
            vt1=s.find(s1[j],vt);
            vt=vt1+1;
            }
        }
        if (dem==10){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
         }
    }
    return 0;
}
