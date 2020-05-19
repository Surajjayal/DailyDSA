/*recursive + memorization = top down approach O(n^2) approax*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//unordered_map<string,int>m;
//not working with map showing time limit exceed
int dp[202][202][2];
int parenthesization(string &s,int i,int j,bool istrue){
    if(i>j)
        return 0;
    if(i==j){
          if(istrue==true){
            return s[i]=='T';
        }  
        else
            return s[i]=='F';
    }
    // string temp=to_string(i);
    // //temp+= ' ';
    // temp=temp.append(to_string(j));
    // //temp+= ' ';
    // temp=temp.append(to_string(istrue));
    // if(m.find(temp)!=m.end())
    //   return m[temp];
      
    if(dp[i][j][istrue]!=-1)
     return dp[i][j][istrue];
    int ans=0;
   // cout<<"temp="<<temp<<" ";
    for(int k=i+1;k<j;k+=2){
        int lt=parenthesization(s,i,k-1,true);
        int lf=parenthesization(s,i,k-1,false);
        int rt=parenthesization(s,k+1,j,true);
        int rf=parenthesization(s,k+1,j,false);
        if(s[k]=='|'){
            if(istrue==true)
              ans=ans + lt*rt + lt*rf +lf*rt;  
            else
                ans=ans + lf*rf;
        }
        else if(s[k]=='&'){
              if(istrue==true)
              ans=ans + lt*rt ;  
            else
                ans=ans + lt*rf +lf*rt + lf*rf;
        }
        else if(s[k]=='^'){
            if(istrue==true)
              ans=ans + lf*rt + lt*rf ;  
            else
                ans=ans+ lt*rt + lf*rf;
        }
    }
    ans=ans % 1003;
   // m[temp]=ans;
    dp[i][j][istrue]=ans;
    return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	   //m.clear();
	   memset(dp,-1,sizeof(dp));
	    int ans= parenthesization(s,0,n-1,true);
	    cout<<ans<<endl;
	}
	return 0;
}
