#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �P�������X�g�̍\���̂̒�`
typedef struct cell
{
	char str[8];
	struct cell* next;
}CELL;

// �v���g�^�C�v�錾
void CreateAddList(CELL* headCell, const char* buf);
void PrintList(CELL* headCell);

int main()
{
	char str[8];
	int val;
	// �擪�̃Z����錾
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("�D���Ȑ�������͂��Ă�������\n");
		printf("���͂���l: ");
		scanf_s("%s", str, 8);
		CreateAddList(&head, str);
		PrintList(&head);
		printf("\n");
	}

	return 0;
}

// �P�������X�g�����֐�
void CreateAddList(CELL* headCell, const char* buf)
{
	// �V�K�Z�����쐬
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	if (newCell != nullptr)
	{
		strcpy_s(newCell->str, 8, buf);
		// �V�K�쐬����Z���̃|�C���^->�l = �l;
		newCell->next = nullptr;
	}

	// �ǉ�����O�̍Ō��������
	while (headCell->next != nullptr)
	{
		headCell = headCell->next;
	}

	// �ǉ�����O�̍Ō���ɐV�K�Z���̃|�C���^����
	headCell->next = newCell;
}

// �P�������X�g��\������֐�
void PrintList(CELL* headCell)
{
	// next�ɉ����l�������Ă������o��
	while (headCell->next != nullptr)
	{
		headCell = headCell->next;
		printf("\n���͂��ꂽ�l�ꗗ: %s\n", headCell->str);
	}
}