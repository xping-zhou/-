#ifndef __SORTING_ALGORITHM_H__
#define __SORTING_ALGORITHM_H__

#define BUBLIE_SORT 0
#define SELECT_SORT 1
#define INSERT_SORT 2
#define SHELL_SORT 3

typedef struct
{

}SORT_PARAM_S;


typedef struct
{
	int m_eFuncType;
	int(*fun_SORT_CreatInit)(SORT_PARAM_S *pstParam);
	int(*fun_MATH_Process)(int *pstArraySrc, int arrayLen, int ruleFlg);
	int(*fun_SORT_Release)(SORT_PARAM_S *pstParam);
}SORT_FUNC_S;


int SORT_CreatInit(SORT_PARAM_S *pstParam);
int SORT_BUBLIE_Process(int *arrayList, int arrayLen, int ruleFlg);
int SORT_SELECT_Process(int *arrayList, int arrayLen, int ruleFlg);
int SORT_INSERT_Process(int *arrayList, int arrayLen, int ruleFlg);
int SORT_SHELL_Process(int *arrayList, int arrayLen, int ruleFlg);
int SORT_Release(SORT_PARAM_S *pstParam);

#endif
