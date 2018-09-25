#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n,m,m1;
    cin>>n>>m;
    vector <int> a;
    for (int i=1; i<=n; i++){
        a.push_back(i);
    }

    while (a.size()!=1){
        n=a.size();
        m1=m%n;
        if (m1==0){
            m1=n;
        }
        cout<<a[m1-1]<<" ";
        a.erase(a.begin()+m1-1,a.begin()+m1);
        for (int i=1; i<m1; i++){
            a.push_back(a[0]);
            a.erase(a.begin(),a.begin()+1);
        }
    }
    cout<<a[0];
    return 0;
}
