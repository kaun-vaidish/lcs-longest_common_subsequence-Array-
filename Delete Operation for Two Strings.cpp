/*
Given two strings word1 and word2, 
return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.
Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minDistance(string X, string Y) {
        int n = X.size();
        int m = Y.size();
        int dp[n+1][m+1];
        for(int i = 0 ; i< n+1 ; i++){
            dp[i][0] = 0;
        }
        for(int i = 0 ; i< m+1 ; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j< m+1 ; j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return m+n-2*dp[n][m];
    }

};

int main() 
{
    string s1, s2;
    cin >> s1 >> s2;

    Solution ob;
    cout << ob.minDistance(s1, s2) << "\n";
    return 0;
}