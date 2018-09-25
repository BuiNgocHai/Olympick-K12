#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    map <string,int> a;
    cin>>n;
    for (int i=0; i<n; i++){
        string s;
        cin>>s;
        a[s]++;
        if (a[s]==1){
            cout<<s;
        } 
		else
		 {
            cout<<s<<a[s]-1;
        }
        
    }
    return 0;
}
