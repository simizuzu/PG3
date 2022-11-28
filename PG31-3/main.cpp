#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 単方向リストの構造体の定義
typedef struct cell
{
	char str[8];
	struct cell* next;
}CELL;

// プロトタイプ宣言
void CreateAddList(CELL* headCell, const char* buf);
void PrintList(CELL* headCell);

int main()
{
	char str[8];
	int val;
	// 先頭のセルを宣言
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("好きな数字を入力してください\n");
		printf("入力する値: ");
		scanf_s("%s", str, 8);
		CreateAddList(&head, str);
		PrintList(&head);
		printf("\n");
	}

	return 0;
}

// 単方向リストを作る関数
void CreateAddList(CELL* headCell, const char* buf)
{
	// 新規セルを作成
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	if (newCell != nullptr)
	{
		strcpy_s(newCell->str, 8, buf);
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
		printf("\n入力された値一覧: %s\n", headCell->str);
	}
}