#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 単方向リストの構造体の定義
typedef struct cell
{
	int val;
	struct cell *next;
}CELL;

// プロトタイプ宣言
void CreateAddList(CELL* headCell, int Num);
void PrintList(CELL* headCell);

int main()
{
	int val;
	// 先頭のセルを宣言
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("入力してください : ");
		scanf_s("%d", &val);
		CreateAddList(&head, val);
		PrintList(&head);
		printf("\n");
	}

	return 0;
}

// 単方向リストを作る関数
void CreateAddList(CELL* headCell, int Num)
{
	// 新規セルを作成
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	// nullチェック
	if (newCell)
	{
		newCell->val = '\0';
		newCell->val = Num;
		// 新規作成するセルのポインタ->値 = 値;
		newCell->next = nullptr;
	}

	// 追加する前の最後尾を検索
	while (headCell->next != nullptr)
	{
		headCell = headCell->next;
	}

	// 追加する前の最後尾に新規セルのポインタを代入
	headCell->next = newCell;
}

// 単方向リストを表示する関数
void PrintList(CELL* headCell)
{
	// nextに何か値が入っている限り出力
	while (headCell->next != nullptr)
	{
		headCell = headCell->next;
		printf("結果を出力 : %d\n", headCell->val);
	}
}