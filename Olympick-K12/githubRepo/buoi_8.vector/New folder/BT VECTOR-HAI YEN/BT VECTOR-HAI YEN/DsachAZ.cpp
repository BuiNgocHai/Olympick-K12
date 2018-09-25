#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    vector <char> a;
    char x;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>x;
        a.push_back(x);
    }
    for (int i=1; i<a.size(); i++){
        if (a[i]<a[i-1]){
            a.erase(a.begin()+i,a.begin()+i+1);
        }
    }
    for (int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
