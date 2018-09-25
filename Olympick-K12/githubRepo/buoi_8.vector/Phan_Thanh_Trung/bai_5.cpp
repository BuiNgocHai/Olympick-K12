#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<char> v;
    for(int i=0; i< n;i++)
    {
        char s;
        cin >> s;
        v.push_back(s);
    }
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]>v[i+1])
        {
            v.erase(v.begin()+i+1,v.begin()+i+2);
            i--;
        }
    }
    for(int i=0; i<v.size(); i++)
        cout << v[i] <<" ";
    return 0;
}
