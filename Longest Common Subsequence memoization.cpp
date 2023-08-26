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

// function to find longest common subsequence
static int dp[1001][1001];
class Solution
{
    public:
    // int t[1001][1001];
    // Solution(){
    //     memset(t,-1,sizeof(t));
    // }
    //Function to find the length of longest common subsequence in two strings.
    // int lcs(int n, int m, string s1, string s2)
    // {
        
    //     if(n==0 || m==0){
    //         return 0;
    //     }
        
    //     if(t[n][m]!=-1){
    //         return t[n][m];
    //     }
        
        
    //     if(s1[n-1] == s2[m-1]){
    //         return t[n][m] = 1+lcs(n-1,m-1,s1,s2);
    //     }else{
    //         return t[n][m] = max( lcs(n-1,m,s1,s2) , lcs(n,m-1,s1,s2) );
    //     }
    // }
    
    
    
     int test(int x, int y, string &s1, string &s2)
    {
        if(x == 0 || y == 0)
        {
            return 0;
        }
        if(dp[x][y] != -1)
        {
            return dp[x][y];
        }
        if(s1[x-1] == s2[y-1])
        {
            return dp[x][y] = 1+test(x-1,y-1,s1,s2);
        }
        else
        {
            return dp[x][y] = max(test(x-1,y,s1,s2),test(x,y-1,s1,s2));
        }
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        memset(dp,-1,sizeof(dp));
        int p = test(x,y,s1,s2);
        return p;
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