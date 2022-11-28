#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 単方向リストの構造体の定義
typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

// プロトタイプ宣言
void CreateAddList(CELL* currentCell, int val);
void PrintList(CELL* endCell);
CELL* GetInsertListAddress(CELL* endCell,int iterator);

int main()
{
	int iterator;
	int inputValue;
	CELL* insertCell;

	// 先頭のセルを宣言
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true)
	{
		printf("何番目のセルの後ろに挿入しますか？？\n");
		scanf_s("%d", &iterator);

		printf("挿入する値を入力してください\n");
		scanf_s("%d",&inputValue);

		insertCell = GetInsertListAddress(&head,iterator);
		CreateAddList(insertCell, inputValue);

		PrintList(&head);
		printf("\n");
	}

	return 0;
}

CELL* GetInsertListAddress(CELL* endCell, int iterator)
{
	for (int i = 0; i < iterator; i++)
	{
		if (endCell->next)
		{
			endCell = endCell->next;
		}
		else
		{
			break;
		}
	}

	return endCell;
}


// 単方向リストを作る関数
void CreateAddList(CELL* currentCell, int val)
{
	// 新規セルを作成
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	if (newCell != nullptr)
	{
		newCell->val = val;
		newCell->prev = currentCell;
		newCell->next = currentCell->next;
	}


	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}
	
	// 追加する前の最後尾に新規セルのポインタを代入
	currentCell->next = newCell;
}

// 単方向リストを表示する関数
void PrintList(CELL* endCell)
{
	int no = 1;
	// nextに何か値が入っている限り出力
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d番目", no);
		//printf("%p", endCell->prev);
		printf("%5d\n", endCell->val);
		//printf("(%p)", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
}