// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//��pArr��ȡnSelect��Ԫ�ص���ϣ�����0��1����1��0��ͬһ��ϣ�
void combine_select(int* pArr, int nArrLen, int* pResult, int nSelect, int nTotolSelect)
{
	if (nSelect > nArrLen)
	{
		return;
	}

	//�㷨�ؼ��㣺
	//��pArr��ȡnSelect��Ԫ�أ�һ��ȡһ������ôȡ�ĵ�һ��������Ӧ����[0, nArrLen - nSelect] 
	//ȡ����һ���������������1���Ѿ�ȡ�꣬��ô������2����Ҫ����ȡ����ô�����µ�������ȥȡnSelect-1�����ݹ飩
	for (int i = 0; i <= nArrLen - nSelect; i++)
	{
		pResult[nTotolSelect - nSelect] = pArr[i];	//ȡһ��
		
		if (nSelect - 1 > 0)//��Ҫ����ȡ
		{
			combine_select(pArr + i + 1 /*�������*/, nArrLen - i - 1, pResult, nSelect - 1, nTotolSelect);
		}
		else//�Ѿ�ȡ��
		{
			//�����
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
		printf("\n��arr��ȡ%d��Ԫ�ص������:\n", i);
		combine_select(arr, nNum, pResult, i, i);
	}

	getchar();
	return 0;
}

