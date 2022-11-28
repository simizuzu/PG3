#include <iostream>
#include"MyList.h"
#include<string>

template<typename T>
void Display(Mylist<T>& list, int& operationNum, int& displayOperationNum);

template<typename T>
void Insert(Mylist<T>& list, int& operationNum);

template<typename T>
void Edit(Mylist<T>& list, int& operationNum);

template<typename T>
void Delete(Mylist<T>& list, int& operationNum);

template<typename T>
void Change(Mylist<T>& list, int& operationNum);

int main()
{
	Mylist<std::string> list;

	list.PushBack("banana");
	list.PushBack("apple");
	list.PushBack("orange");

	//�v�f�̑���̑���ԍ�
	int operationNum = 0;

	//�v�f�̕\���̑���ԍ�
	int displayOperationNum = 0;


	while (true)
	{
		std::cout << "[�v�f�̑���]" << std::endl;
		std::cout << "1.�v�f�̕\��" << std::endl;
		std::cout << "2.�v�f�̑}��" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.�v�f�̕ҏW" << std::endl;
			std::cout << "4.�v�f�̍폜" << std::endl;
		}

		std::cout << "5.�v�f�̕��ёւ�(�I�v�V����)" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "�����I�����Ă�������" << std::endl;

		std::cout << std::endl;

		if (operationNum == 0)
		{
			//����ԍ����擾
			std::cin >> operationNum;
		}
		system("cls");

		switch (operationNum)
		{
		case 1://�v�f�̕\��
			Display(list, operationNum, displayOperationNum);
			break;

		case 2://�Ō���ɗv�f��ǉ�
			Insert(list, operationNum);
			break;

		case 3://�C�ӂ̏ꏊ�̒l��ύX
			Edit(list, operationNum);
			break;
		case 4://�C�ӂ̏ꏊ�̍폜
			Delete(list, operationNum);
			break;
		case 5://�C�ӂ̏ꏊ�ƔC�ӂ̏ꏊ�����ւ�
			Change(list, operationNum);
			break;
		}
	}

	return 0;
}

template<typename T>
void Display(Mylist<T>& list, int& operationNum, int& displayOperationNum)
{
	std::cout << "[�v�f�̕\��]" << std::endl;
	std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
	std::cout << "2.���Ԃ��w�肵�ėv�f��\��" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;
	std::cout << std::endl;
	std::cout << "�����I�����Ă�������" << std::endl;

	//����ԍ����擾
	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum)
	{
	case 1:
		std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;

		//�ꗗ�\��
		list.ListDisplay();

		std::cout << "�v�f��:" << list.Size() << std::endl;

		break;
	case 2:
		std::cout << "[���Ԃ��w�肵�ėv�f��\��]" << std::endl;
		std::cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << std::endl;

		//�w�肷��ԍ����擾
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		//�w�肵�ĕ\��
		list.SpecifyElement(specifyNum);

		break;

	case 9:
		operationNum = 0;
		break;
	}

	//�v�f����ɖ߂�Ȃ�������
	if (displayOperationNum == 1 || displayOperationNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
		std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;

		//����ԍ����擾
		std::cin >> displayOperationNum;

		system("cls");
		switch (displayOperationNum)
		{
		case 1:
			operationNum = 1;
			break;
		case 2:
			operationNum = 0;
			break;
		default:
			break;
		}
	}
}

template<typename T>
void Insert(Mylist<T>& list, int& operationNum)
{
	std::cout << "[���X�g�v�f�̑}��]" << std::endl;
	std::cout << std::endl;
	std::cout << "�v�f��ǉ��ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
		T element{};

		std::cin >> element;

		list.PushBack(element);

		std::cout << "�v�f" << element << "��" << "�Ō���ɑ}������܂���" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
		T element{};

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "�v�f" << element << "��" << index << "�Ԗڂɑ}������܂���" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 2;
	}
}

template<typename T>
void Edit(Mylist<T>& list, int& operationNum)
{
	std::cout << "[�v�f�̕ҏW]" << std::endl;
	std::cout << std::endl;
	std::cout << "�ҏW�������v�f�̔ԍ�����͂��Ă�������" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B" << std::endl;

		T changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elementNum);
		std::cout << std::endl;

		std::cout << elementNum << "�Ԗڂ̗v�f�̒l��" << '"' << changeElement << '"' << "�ɕύX����܂���" << std::endl;
	}
	else
	{
		std::cout << elementNum << "�Ԗڂ̗v�f�̂�������܂���ł����B" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 3;
	}

}

template<typename T>
void Delete(Mylist<T>& list, int& operationNum)
{
	std::cout << "[�v�f�̍폜]" << std::endl;
	std::cout << std::endl;
	std::cout << "�폜�������v�f�̔ԍ����w�肵�Ă�������" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "�Ԗڂ̗v�f" << '"' << list.GetElement(elementNum) << '"' << "�폜���܂���" << std::endl;

		list.Delete(elementNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elementNum << "�Ԗڂ̗v�f�̂�������܂���ł����B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 4;
	}
}

template<typename T>
void Change(Mylist<T>& list, int& operationNum)
{
	std::cout << "[�v�f�̕��ёւ�]" << std::endl;
	std::cout << std::endl;
	std::cout << "���ёւ����@��I�����Ă�������" << std::endl;
	std::cout << "1.�����ŕ��ёւ���" << std::endl;
	std::cout << "2.�~���ŕ��ёւ���" << std::endl;

	int changeOperationNum;

	std::cin >> changeOperationNum;

	switch (changeOperationNum)
	{
	case 1:
	{

		list.Sort();
		std::cout << "���X�g�̗v�f�������ŕ��ёւ��܂���" << std::endl;
	}
	break;
	case 2:
		list.Sort(false);
		std::cout << "���X�g�̗v�f���~���ŕ��ёւ��܂���" << std::endl;

		break;
	default:
		break;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 5;
	}
}