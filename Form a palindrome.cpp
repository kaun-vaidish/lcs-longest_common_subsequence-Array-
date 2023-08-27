/*
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Example 1:

Input:
abcd
Output:
3
Explanation:
Here we can append 3 characters in the 
beginning,and the resultant string will 
be a palindrome ("dcbabcd").
*/


#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int findMinInsertions(string A){
        string s1 = A;
        reverse(A.begin() , A.end());
        string s2 = A;
        int n = s1.length();
        int m = s2.length();
        int dp[n+1][m+1];

        for(int i = 0 ; i< n+1 ;i++){
            dp[i][0] = 0;
        }
        for(int i = 0 ; i< m+1; i++){
            dp[0][i] = 0;
        }

        for(int i = 1 ; i< n+1 ;i++){
            for(int j = 1 ; j<m+1 ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] =  1+dp[i-1][j-1] ;
                }else{
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        return n-dp[n][m];
    }
};

int main(){
    string S;
    cin>>S;
    Solution ob;
    cout<<ob.findMinInsertions(S)<<endl;

    return 0;
}
