#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
/*****************************************/
/*

最长公共子序列，带备忘录的自底向上的求解过程

*/
/*****************************************/

int lcs(char * s1, char *s2, int **note)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	note = (int **) malloc(sizeof(int *)*(len1+1));

	for(int i = 0; i <= len1; i++ )
		note[i] = (int *) malloc(sizeof(int)*(len2+1));

	for (int i = 0; i <= len1; i++ )
		note[i][0] = 0;

	for (int j = 0; j <= len2; j++ )
			note[0][j] = 0;

	for (int i = 1; i <= len1; i++ )
	{
		for (int j=1; j <= len2; j++ )
		{
			if ( s1[i-1] == s2[j-1])
			{
				note[i][j] = note[i-1][j-1] + 1;
			}else
			{
				note[i][j] = max(note[i][j-1], note[i-1][j]);
			}
		}
	}
	return note[len1][len2];
}

int main(int argc, char const *argv[])
{
	int **note = NULL;

	char s1[] = "abcdfa";

	char s2[] = "bcadh";

	int res = lcs(s1, s2, note);

	cout<<"最长公共子序列："<<res<<endl;

	return 0;
}