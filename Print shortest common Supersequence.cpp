/*
Given two strings X and Y of lengths m and n respectively, 
find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1
Input:
X = abcd, Y = xycd
Output: abxycd
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subset
*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    vector<int> lcs(int n, int m, string s1, string s2)
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
        vector<int> res;

        int i = n+1;
        int j = m+1;
        while(i>0||j>0){
            if(s1[i-1] == s2[j-1]){
                res.push_back(s1[i-1]);
                i--;
                j--;
            }else{
                res.push_back(s1[i-1]);
                res.push_back(s2[j-1]);
                i--;
                j--;
            }
        }
        return res;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;          // Take size of both the strings as input
    string s1,s2;
    cin>>s1>>s2;        // Take both the string as input
    Solution ob;
    vector <int> temp = ob.lcs(n, m, s1, s2);
    for(int i = temp.size() ; i>=0 ; i--){
        cout<<temp[i];
    }
    return 0;
}

