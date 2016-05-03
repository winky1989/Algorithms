// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//从pArr中取nSelect个元素的组合（即先0后1、先1后0是同一组合）
void combine_select(int* pArr, int nArrLen, int* pResult, int nSelect, int nTotolSelect)
{
	if (nSelect > nArrLen)
	{
		return;
	}

	//算法关键点：
	//从pArr中取nSelect个元素，一次取一个，那么取的第一个的区间应当是[0, nArrLen - nSelect] 
	//取完这一个后，有两种情况：1是已经取完，那么结束；2是需要继续取，那么在余下的数组中去取nSelect-1个（递归）
	for (int i = 0; i <= nArrLen - nSelect; i++)
	{
		pResult[nTotolSelect - nSelect] = pArr[i];	//取一个
		
		if (nSelect - 1 > 0)//还要继续取
		{
			combine_select(pArr + i + 1 /*区间后移*/, nArrLen - i - 1, pResult, nSelect - 1, nTotolSelect);
		}
		else//已经取满
		{
			//计算和
			int nSum = 0;
			for (int j = 0; j < nTotolSelect; j++)
			{
				printf("%d ", pResult[j]);
				nSum += pResult[j];
			}
			printf(" sum = %d.\n", nSum);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int nNum = sizeof(arr)/sizeof(int);

	int* pResult = new int [nNum];
	for (int i = 1; i <= nNum; i++)
	{
		printf("\n从arr中取%d个元素的组合有:\n", i);
		combine_select(arr, nNum, pResult, i, i);
	}

	getchar();
	return 0;
}

