/*
You are given a string S and a Pattern P. You need to find all matches of hash of P in string S. Also, print the index (0 based) at which the pattern's hash is found. If no match is found, print -1.
Note: All the matches should have same length as pattern P. 

Note: All the matches should have same length as pattern P.

The hash of pattern P is calculated by summing the values of characters as they appear in the alphabets table. For reference, a is 1, b is 2, ...z is 26. Now, using the mentioned values, hash of ab is 1+2=3.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains the string S. The second line contains the pattern P.

Output:
For each testcase, in a new line, print the matches and index separated by a space. All the matches should be printed in their own separate lines.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test; 
	while(test--)
    {
        string str1,str2;
        cin >> str1 >> str2;

        if(str2.size() > str1.size())
        {
            cout << -1 << '\n';
        }else{

            bool gotit = false;
            long HashP = 0;
            long HashC = 0;
            for(int i=0;i<str2.size();i++){

                if(str2[i] >= 97){
                    HashP = HashP + (str2[i] - 'a' + 1);
                }else{
                    HashP = HashP + (str2[i] - 'A' + 1);
                }

                if(str1[i] >= 97){
                    HashC = HashC + (str1[i] - 'a' + 1);
                }else{
                    HashC = HashC + (str1[i] - 'A' + 1);
                }
                
                
            }

            if(HashC == HashP){
                gotit = true;
                for(int i=0;i<str2.size();i++)
                    cout << str1[i];
                cout << " " << 0 << '\n';
            }

            for(int i=0; i+str2.size() < str1.size();i++){
                
                if(str1[i] >= 97){
                    HashC = HashC - (str1[i] - 'a' + 1);
                }else{
                    HashC = HashC - (str1[i] - 'A' + 1);
                }


                if(str1[i+str2.size()] >= 97){
                    HashC = HashC + (str1[i+str2.size()] - 'a' + 1);
                }else{
                    HashC = HashC + (str1[i+str2.size()] - 'A' + 1);
                }

                if(HashC == HashP){
                    gotit = true;
                    for(int j=i+1;j<=str2.size()+i;j++)
                        cout << str1[j];
                    cout  << " " << i+1 << '\n';
                }

            }

            if(gotit==false)
                cout << "-1" << '\n';

        }
    }
	return 0;
}


/*
Sample Input

Input:
1
bacdaabaa
aab
Output:
aab 4
aba 5
baa 6

Explanation:
Testcase1: P is aab, and S is bacdaabaa
Now, the hash of P: aab is 1+1+2=4
In the string S, the hash value of 4 is obtained by the following:
aab=1+1+2=4, at index 4
aba=1+2+1=4, at index 5
baa=2+1+1=4, at index 6

*/