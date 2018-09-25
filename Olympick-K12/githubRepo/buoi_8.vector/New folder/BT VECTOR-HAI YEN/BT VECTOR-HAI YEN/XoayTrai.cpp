#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    vector <int> a;
    int n,t,x;
    cin>>n>>t;
    t=t%n;
    for (int i=1; i<=n; i++){
        cin>>x;
        a.push_back(x);
    }
    if (t==0){
        for (int i=0; i<a.size(); i++){
            cout<<a[i]<<" ";
        }
    } else {
        for (int i=1; i<=t; i++){
            a.push_back(a[0]);
            a.erase(a.begin(),a.begin()+1);
        }
        for (int i=0; i<a.size(); i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
