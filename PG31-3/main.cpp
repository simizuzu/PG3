#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �P�������X�g�̍\���̂̒�`
typedef struct cell
{
	int val;
	struct cell *next;
}CELL;

// �v���g�^�C�v�錾
void CreateAddList(CELL* headCell, int Num);
void PrintList(CELL* headCell);

int main()
{
	int val;
	// �擪�̃Z����錾
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("���͂��Ă������� : ");
		scanf_s("%d", &val);
		CreateAddList(&head, val);
		PrintList(&head);
		printf("\n");
	}

	return 0;
}

// �P�������X�g�����֐�
void CreateAddList(CELL* headCell, int Num)
{
	// �V�K�Z�����쐬
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	// null�`�F�b�N
	if (newCell)
	{
		newCell->val = '\0';
		newCell->val = Num;
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
		printf("���ʂ��o�� : %d\n", headCell->val);
	}
}