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
        if(n==0 || m==0){
            return 0;
        }
        
        if(s1[n-1] == s2[m-1]){
            return 1+lcs(n-1,m-1,s1,s2);
        }else{
            return max( lcs(n-1,m,s1,s2) , lcs(n,m-1,s1,s2) );
        }
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

