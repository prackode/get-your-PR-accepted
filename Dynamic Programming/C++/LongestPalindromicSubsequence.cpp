/***********************Hacktober Fest 2021******************/

/*****Solution by "manishmotwani2002" ***********/
/*****Topic:- Dynamic Programming **********/

/******Question:- Longest Palindromic Subsequence(We are given a string as input, we have to return the maximum length of the palindromic sequence in the string) ******/

/****Sample Inputs

String :- bbbab
Output:- 4

Explaination:- the maximum possible subsequence can be "bbbb" which is of length 4

*****/


#include<bits/stdc++.h>
using namespace std;


int lcs(string s1, string s2,int x, int y){		//function for finding longest common subsequence in the string
    //recursive approach
    int i,j;
    int arr[x+1][y+1];
    for(i=0;i<x+1;i++)
    arr[i][0]=0;
    for(j=0;j<y+1;j++)
    arr[0][j]=0;
    
    for(i=1;i<x+1;i++)
    {
        for(j=1;j<y+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                arr[i][j]=1+arr[i-1][j-1];
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[x][y];
}

int longestPalindromeSubseq(string s) {			//function to evaluate the longest palindromic subsequence
        string srev=s;
        reverse(srev.begin(),srev.end());
        int x=s.size();
        int y=x;
        
        return lcs(s,srev,x,y);			//returns the maximum length
}
    
int main()
{
	string str;			
	cin>>str;			//fetched user input
	
	int ans=longestPalindromeSubseq(str);
	
	cout<<ans;			//gives the final integer output
}
