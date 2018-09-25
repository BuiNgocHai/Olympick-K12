#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >>n;
    vector<int> a[n],b[n];
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<n;j++)
        {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<n;j++)
        {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
    }
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<a[i].size();j++)
        {
            a[i][j]=a[i][j]+b[i][j];
        }
    }
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
