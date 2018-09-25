#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin >> n >> t;
    vector<int> a;
    for(int i=0; i< n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<t;i++)
    {
        int m;
        m=a.front();
        a.erase(a.begin(),a.begin()+1);
        a.push_back(m);
    }
    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
