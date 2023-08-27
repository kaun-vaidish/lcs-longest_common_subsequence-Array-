/*
Given string str, find the length of the longest repeating subsequence
 such that it can be found twice in the given string.
The two identified subsequences A and B can use the same ith character
from string str if and only if that ith character has different indices in A and B.
For example, A = "xax" and B = "xax" then the index of 
first "x" must be different in the original string for A and B.

Example 1:

Input:
str = "axxzxy"
Output: 2
*/


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n  = str.length();
		    int m = str.length();
            int dp[n+1][m+1];
            for(int i = 0 ; i< n+1 ; i++){
                dp[i][0] = 0;
            }
            for(int i = 0 ; i< m+1 ; i++){
                dp[0][i] = 0;
            }
            
            for(int i = 1 ; i < n+1 ; i++){
                for(int j = 1 ; j< m+1 ; j++){
                    if(str[i-1] == str[j-1] && i!=j){
                        dp[i][j] = 1+ dp[i-1][j-1];
                    }else{
                        dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
                    }
                }
            }
            return dp[n][m];
        
		}

};

int main(){
    string str;
    cin >> str;
    Solution obj;
    int ans = obj.LongestRepeatingSubsequence(str);
    cout << ans << "\n";

}
