#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,q;
    cin >> m >> n >> q;
    vector<int> a[m],b[n],c[m];
    for(int i=0; i< m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<q; j++)
        {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
    }
    int val=0;
    for(int i=0; i< m; i++)
    {
        for(int j=0; j< q; j++)
        {
            val=0;
            for(int I=0; I<n; I++)
            {
                val+=a[i][I]*b[I][j];
            }
            c[i].push_back(val);
        }
    }
    for(int i=0; i< m; i++)
    {
        for(int j=0; j< c[i].size(); j++)
            cout << c[i][j]<<  " ";
        cout << endl;
    }
    return 0;
}
