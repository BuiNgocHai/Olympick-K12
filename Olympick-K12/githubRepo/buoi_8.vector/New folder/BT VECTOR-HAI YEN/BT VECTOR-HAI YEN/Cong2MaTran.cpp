#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n,x;
    cin>>n;
    vector <int> a[1000],b[1000],c[1000];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>x;
            a[i].push_back(x);
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>x;
            b[i].push_back(x);
            c[i].push_back(a[i][j]+x);
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<c[i].size(); j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
