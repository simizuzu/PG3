#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �P�������X�g�̍\���̂̒�`
typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

// �v���g�^�C�v�錾
void CreateAddList(CELL* currentCell, int val);
void PrintList(CELL* endCell);
CELL* GetInsertListAddress(CELL* endCell,int iterator);

int main()
{
	int iterator;
	int inputValue;
	CELL* insertCell;

	// �擪�̃Z����錾
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	while (true)
	{
		printf("���Ԗڂ̃Z���̌��ɑ}�����܂����H�H\n");
		scanf_s("%d", &iterator);

		printf("�}������l����͂��Ă�������\n");
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


// �P�������X�g�����֐�
void CreateAddList(CELL* currentCell, int val)
{
	// �V�K�Z�����쐬
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
	
	// �ǉ�����O�̍Ō���ɐV�K�Z���̃|�C���^����
	currentCell->next = newCell;
}

// �P�������X�g��\������֐�
void PrintList(CELL* endCell)
{
	int no = 1;
	// next�ɉ����l�������Ă������o��
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d�Ԗ�", no);
		//printf("%p", endCell->prev);
		printf("%5d\n", endCell->val);
		//printf("(%p)", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
}