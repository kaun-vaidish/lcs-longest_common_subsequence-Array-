/*
Given a String, find the longest palindromic subsequence.
NOTE: Subsequence of a given sequence is a sequence that can be 
derived from the given sequence by deleting some or no elements 
without changing the order of the remaining elements

Example 1:
Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestPalinSubseq(string A) {
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
        return dp[n][m];
        
    }
};
int32_t main()
{
    string s; cin >> s;
    Solution ob;
    cout << ob.longestPalinSubseq(s) << endl;

}