/*
Given two strings X and Y of lengths m and n respectively, 
find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1
Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
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
        
        int lcs = dp[n][m];
        
        return n+m-lcs;
    }
};

int main()
{   
    string X, Y;
    //taking String X and Y
    cin >> X >> Y;
    //calling function shortestCommonSupersequence()
    Solution obj;
    cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
	return 0;
}

