/*
Given two strings str1 and str2. 
The task is to remove or insert the minimum number of characters
 from/in str1 so as to transform it into str2. It could be possible 
 that the same character needs to be removed/deleted from one point 
 of str1 and inserted to some another point.

Example 1:
Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap.
Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
		

	public:
// 	 int shortestCommonSupersequence(string X, string Y, int n, int m)
//     {
//         int dp[n+1][m+1];
//         for(int i = 0 ; i< n+1 ; i++){
//             dp[i][0] = 0;
//         }
//         for(int i = 0 ; i< m+1 ; i++){
//             dp[0][i] = 0;
//         }
        
//         for(int i = 1 ; i < n+1 ; i++){
//             for(int j = 1 ; j< m+1 ; j++){
//                 if(X[i-1] == Y[j-1]){
//                     dp[i][j] = 1+ dp[i-1][j-1];
//                 }else{
//                     dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
//                 }
//             }
//         }
        
//         int lcs = dp[n][m];
        
//         return n+m-lcs;
//     }
	
	int minOperations(string s1, string s2) 
	{ 
	    int n = s1.length();
	    int m = s2.length();
	    int dp[n+1][m+1];
        for(int i = 0 ; i< n+1 ; i++){
            dp[i][0] = 0;
        }
        for(int i = 0 ; i< m+1 ; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j< m+1 ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        //int k = shortestCommonSupersequence(s1,s2,n,m);
	    
	    //return (k-dp[n][m]);
	    return m+n-2*dp[n][m];
	} 
};

int main() 
{
    string s1, s2;
    cin >> s1 >> s2;

    Solution ob;
    cout << ob.minOperations(s1, s2) << "\n";
    return 0;
}