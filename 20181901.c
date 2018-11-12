#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void IndexAddMat(int (*Mat)[3]);
void ptrProdMat(int (* Mat)[3]);

int main()
{
	int Mat[3][3];

	for (int wid = 0; wid < 3; wid++)
	{
		for (int clmn = 0; clmn < 3; clmn++)
		{
			printf("Mat[%d][%d] : ", wid, clmn);
			scanf("%d", &Mat[wid][clmn]);
		}
	}

	printf("\n");

	for (int wid = 0; wid < 3; wid++)
	{
		for (int clmn = 0; clmn < 3; clmn++)
		{
			printf("%d	", Mat[wid][clmn]);
		}
		printf("\n");
	}

	printf("\n");

	IndexAddMat(Mat);
	
	for (int wid = 0; wid < 3; wid++)
	{
		for (int clmn = 0; clmn < 3; clmn++)
		{
			printf("%d	", Mat[wid][clmn]);
		}
		printf("\n");
	}

	printf("\n");

	ptrProdMat(Mat);

	for (int wid = 0; wid < 3; wid++)
	{
		for (int clmn = 0; clmn < 3; clmn++)
		{
			printf("%d	", Mat[wid][clmn]);
		}
		printf("\n");
	}

	return 0;
}



void IndexAddMat(int( *Mat)[3])
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			Mat[i][j] = Mat[i][j] * 2;	
}

void ptrProdMat(int (*Mat)[3])
{
	int temp[3][3] = { NULL };

	for (int i = 0; i<3; i++)
		for (int j = 0; j < 3; j++)
			for (int m = 0; m < 3; m++)
				*(*(temp+i)+j) += (*(*(Mat+i)+m)) * (*(*(Mat+m)+j)); 

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			*(*(Mat+i)+j) = *((*temp+i)+j);
}