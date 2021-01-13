#include<iostream>
#include<cstdlib>
#include<ctime>

#define CLOCKS_PER_SE 1000

using namespace std;
/***************************************/
/*
自上而下的设计：朴素递归方式寻找最优解

当n稍大时非常消耗性能,效率很差
*/
/***************************************/

int cut(int n, int p[])
{
	if ( n == 0)
	{
		/* code */
		return 0;
	}
	int maxprice = 0;
	for (int i=1; i<= n; i++)
	{
		if (i < 11)
		{
			/* code */
			int val = p[i] + cut(n - i, p);
			maxprice = (maxprice > val ? maxprice : val);
		}else
			break;
	}
	return maxprice;
}

/***************************************/
/*
自上而下的设计：带备忘录的递归方式寻找最优解

以空间换时间带来性能的提升
*/
/***************************************/
int cut2(int n, int p[], int note[])
{
	if ( n == 0)
	{
		/* code */
		return 0;
	}
	if (note[n] > 0)
	{
		/* code */
		return note[n];
	}
	int maxprice = 0;
	for (int i=1; i<= n; i++)
	{
		if (i < 11)
		{
			/* code */
			int val = p[i] + cut2(n - i, p, note);
			maxprice = (maxprice > val ? maxprice : val);
		}else
			break;
	}
	note[n] = maxprice;//加入备忘录
	return maxprice;
}

/***************************************/
/*
自底向上的带备忘录的求解过程
*/
/***************************************/

int cut3(int n,int p[],int note[])
{
	if (n == 0 )
		return 0;

	if ( note[n] > 0 )
	{
		return note[n];
	}

	for( int i = 1; i<= n; i++ )
	{
		int iv = 0;//保存长度为i时的最大值
		for( int j = 1; j <= 10 && j <= i; j++ )
		{
			int v = p[j] + note[ i-j ];
			iv = iv > v ? iv : v;
		}
		note[i] = iv;
	}
	return note[n];
}


int main(int argc, char const *argv[])
{
	/* code */
	int len = 0;//钢条长度
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};//钢条各尺寸价格
	clock_t start,end;

	printf("%s", "请输入钢条长度：");
	scanf("%d",&len);

	int *nt = new int[len+1];
	int *nt2 = new int[len+1];
	int r= 0 ;
	double time_use = 0.0;

	/*加入备忘录的自定向下的递归*/
	start = clock();
	r = cut2(len,p,nt);
	end = clock();
	time_use = (double)(end-start)/CLOCKS_PER_SE;
	cout<<"钢条切割最大价值(加入备忘录递归)："<< r <<"，耗时："<< time_use <<"s"<<endl;

	/*朴素递归*/
	start = clock();
	r = cut(len,p);
	end = clock();
	time_use = (double)(end-start)/CLOCKS_PER_SE;
	cout<<"钢条切割最大价值(朴素递归)："<< r <<"，耗时："<< time_use <<"s"<<endl;

	/*自底向上的求解*/
	start = clock();
	r = cut3(len,p,nt2);
	end = clock();
	time_use = (double)(end-start)/CLOCKS_PER_SE;
	cout<<"钢条切割最大价值(自底向上的求解)："<< r <<"，耗时："<< time_use <<"s"<<endl;

	return 0;
}