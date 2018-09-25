#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,t=0;
    cin>>n>>m;
    map <int,int> a,b;
    for (int i=1; i<=n; i++){
        int x;
        cin>>x;
        if (a[x]==0){
            a[x]++;
        }
    }
    for (int i=1; i<=m; i++){
        int x;
        cin>>x;
        if (b[x]==0){
            b[x]++;
        }
    }
    map <int,int> ::iterator i=a.begin();
    for (;i!=a.end();i++){
        t=t+(*i).second*b[(*i).first];
    }
    cout<<t;
    return 0;
}

