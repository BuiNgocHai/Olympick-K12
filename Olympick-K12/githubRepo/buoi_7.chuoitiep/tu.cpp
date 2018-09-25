#include<bits\stdc++.h> 
using namespace std; 
 int main() 
   {   
      int i=0,j=0,k=0;
      string s;
      getline(cin,s); 
      string b="hackerrank"; 
       for(i=0;i<s.length();i++){
       	if(s[i]==b[k++])
       	j++;
       	if(k==b.length())
       	break;
	   }
      if(j==10) 
       cout<<"yes";
       else 
       cout<<"no";
       return 0;
   }
