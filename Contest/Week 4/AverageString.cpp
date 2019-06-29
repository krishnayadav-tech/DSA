/*
You are given a string S. You need to find the floor of average of the string.
Average of string is given by AVG=(sum of ASCII values of all characters)/(length of string)

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing S.

Output:
For each testcase, in a new line, print the floor of average of S.

*/

#include<bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    freopen("input.txt","r",stdin);
	int test;
	cin >> test; 
	while(test--)
    {
        string str;
        cin >> str;
        long length = 0;
        for(int i=0;i<str.size();i++)
            length = length + str[i];
        
        cout << floor(length/str.size()) << '\n';

    }
	return 0;
}

/*

Input:
2
aaaa
abcd
Output:
97
98

Explanation:
Testcase1: The ASCII value of a is 97. So sum of ASCII values of the given string is 97+97+97+97=388
Now divide the sum by length of string. This gives 388/4=97. Finally, take floor of the average, so floor(97)=97



*/