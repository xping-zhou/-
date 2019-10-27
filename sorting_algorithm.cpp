#include"sorting_algorithm.h"

#include<iostream>
#include<stdio.h>

int SORT_CreatInit(SORT_PARAM_S *pstParam)
{
	return 0;
}

int SORT_BUBLIE_Process(int *arrayList, int arrayLen, int ruleFlg)
{
	int i, j;
	int temp = arrayLen;
	int tempVar;

	if (ruleFlg > 0)
	{
		for (int i = 0; i < arrayLen - 1; i++)
		{
			for (int j = 0; j < temp - 1; j++)
			{
				if (arrayList[j]>arrayList[j + 1])
				{
					tempVar = arrayList[j];
					arrayList[j] = arrayList[j + 1];
					arrayList[j + 1] = tempVar;
				}
				else
				{
					continue;
				}
			}
			temp--;
		}
	}
	else
	{
		for (int i = 0; i < arrayLen - 1; i++)
		{
			for (int j = 0; j < temp - 1; j++)
			{
				if (arrayList[j]<arrayList[j + 1])
				{
					tempVar = arrayList[j];
					arrayList[j] = arrayList[j + 1];
					arrayList[j + 1] = tempVar;
				}
				else
				{
					continue;
				}
			}
			temp--;
		}
	}



	return 0;
}

int SORT_SELECT_Process(int *arrayList, int arrayLen, int ruleFlg)
{
	int i, j;

	if (ruleFlg)
	{
		for (int i = 0; i<arrayLen - 1; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j<arrayLen; j++)
			{
				if (arrayList[j]<arrayList[minIndex])
				{
					minIndex = j;
				}
			}

			if (minIndex != i)
			{
				int temp = arrayList[i];
				arrayList[i] = arrayList[minIndex];
				arrayList[minIndex] = temp;
			}
		}
	}
	else
	{
		for (int i = 0; i<arrayLen - 1; i++)
		{
			int maxIndex = i;
			for (int j = i + 1; j<arrayLen; j++)
			{
				if (arrayList[j]>arrayList[maxIndex])
				{
					maxIndex = j;
				}
			}

			if (maxIndex != i)
			{
				int temp = arrayList[i];
				arrayList[i] = arrayList[maxIndex];
				arrayList[maxIndex] = temp;
			}
		}
	}

	return 0;
}

int SORT_INSERT_Process(int *arrayList, int arrayLen, int ruleFlg)
{
	int temp;

	if (ruleFlg)
	{
		for (int i = 0; i<arrayLen - 1; i++)
		{
			for (int j = i + 1; j>0; j--)
			{
				if (arrayList[j] < arrayList[j - 1])
				{
					temp = arrayList[j - 1];
					arrayList[j - 1] = arrayList[j];
					arrayList[j] = temp;
				}
				else {         //不需要交换
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i<arrayLen - 1; i++)
		{
			for (int j = i + 1; j>0; j--)
			{
				if (arrayList[j] > arrayList[j - 1])
				{
					temp = arrayList[j - 1];
					arrayList[j - 1] = arrayList[j];
					arrayList[j] = temp;
				}
				else {         //不需要交换
					break;
				}
			}
		}
	}
	
	return 0;
}

int SORT_SHELL_Process(int *arrayList, int arrayLen, int ruleFlg)
{
	int temp = 0;
	int incre = arrayLen;

	if (ruleFlg)
	{
		while (1)
		{
			incre = incre / 2;

			for (int k = 0; k<incre; k++) //根据增量分为若干子序列
			{
				for (int i = k + incre; i<arrayLen; i += incre)
				{
					for (int j = i; j>k; j -= incre)
					{
						if (arrayList[j]<arrayList[j - incre])
						{
							temp = arrayList[j - incre];
							arrayList[j - incre] = arrayList[j];
							arrayList[j] = temp;
						}
						else {
							break;
						}
					}
				}
			}

			if (incre == 1)
			{
				break;
			}
		}
	}
	else
	{
		while (1)
		{
			incre = incre / 2;

			for (int k = 0; k<incre; k++) //根据增量分为若干子序列
			{
				for (int i = k + incre; i<arrayLen; i += incre)
				{
					for (int j = i; j>k; j -= incre)
					{
						if (arrayList[j]>arrayList[j - incre])
						{
							temp = arrayList[j - incre];
							arrayList[j - incre] = arrayList[j];
							arrayList[j] = temp;
						}
						else {
							break;
						}
					}
				}
			}

			if (incre == 1)
			{
				break;
			}
		}
	}
	
	return 0;
}

int SORT_Release(SORT_PARAM_S *pstParam)
{
	return 0;
}
