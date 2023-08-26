/*
Given two strings, find the length of longest subsequence present in both of them.
 Both the strings are in uppercase latin alphabets.

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.*/

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
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

int main()
{
    int n,m;
    cin>>n>>m;          // Take size of both the strings as input
    string s1,s2;
    cin>>s1>>s2;        // Take both the string as input
    Solution ob;
    cout << ob.lcs(n, m, s1, s2) << endl;
    return 0;
}

