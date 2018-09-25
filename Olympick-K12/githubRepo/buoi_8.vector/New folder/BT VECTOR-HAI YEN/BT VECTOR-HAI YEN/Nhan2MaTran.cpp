#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int m,n,q,x;
    cin>>m>>n>>q;
    vector <int> a[1000],b[1000],c[1000];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin>>x;
            a[i].push_back(x);
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<q; j++){
            cin>>x;
            b[i].push_back(x);
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<q; j++){
            int x=0;
            for (int k=0; k<n; k++){
                x=x+a[i][k]*b[k][j];
            }
            c[i].push_back(x);
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
