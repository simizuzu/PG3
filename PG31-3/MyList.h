#pragma once
#include <iostream>

template <typename T>
struct Cell
{
	//�l
	T value_;
	//�O�̃Z�����w���|�C���^
	Cell* prev_;
	//���̃Z�����w���|�C���^
	Cell* next_;

	//�R���X�g���N�^
	Cell()
	{
		//�_�~�[�m�[�h��p��
		prev_ = this;
		next_ = this;
	}

	Cell(T value, Cell* prev, Cell* next)
	{
		value_ = value;
		prev_ = prev;
		next_ = next;
	}
};

template <class T>
class Mylist
{
public:
	Mylist()
	{
		head = new Cell<T>();
		no = 0;
	}

	~Mylist()
	{

	}

	//��ԑO�ɒǉ�
	void PushFront(T value_)
	{
		Cell<T>* cur = head;
		AddAfterCell(value_, cur);
	}

	/// <summary>
	/// ��Ԍ��ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	void PushBack(T value_)
	{
		Cell<T>* cur = head->prev_;
		AddAfterCell(value_, cur);
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ǉ�����ꏊ(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* headCell = nullptr;
		headCell = head;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num; i++)
		{
			headCell = headCell->next_;
		}

		//�ǉ�
		AddAfterCell(value_, headCell);
	}

	/// <summary>
	/// �v�f������
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	bool SearchElement(int num)
	{
		if (num < 0 || num>=no)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�̒l��ύX
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ύX����ꏊ(0~)</param>
	bool ChangeValue(T value_, int num)
	{
		if (num < 0 || num>=no)
		{
			return false;
		}

		Cell<T>* headCell = nullptr;
		headCell = head;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			headCell = headCell->next_;
		}

		//�ύX
		headCell->value_ = value_;

		return true;
	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
	void ListDisplay()
	{
		Cell<T>* ptr = head->next_;

		std::cout << "�v�f�ꗗ:{" << std::endl;

		int index = 0;
		for (int i = 0; i < no - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->value_ << '"' << ',' << std::endl;
			ptr = ptr->next_;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->value_ << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	/// <summary>
	/// �v�f���w��
	/// </summary>
	/// <param name="num">�w�肷��ԍ�</param>
	void SpecifyElement(int num)
	{
		Cell<T>* headCell = nullptr;
		headCell = head;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			headCell = headCell->next_;
			index++;
		}

		std::cout << index << ':' << headCell->value_ << '\n';
	}

	int Size()
	{
		return no;
	}

	bool Delete(int num)
	{
		if (num < 0 || num>=no)
		{
			return false;
		}

		Cell<T>* headCell = nullptr;
		headCell = head;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			headCell = headCell->next_;
		}

		headCell->prev_->next_ = headCell->next_;
		headCell->next_->prev_ = headCell->next_;

		delete headCell;

		no--;

		return true;
	}

	/// <summary>
	/// �v�f�̓���ւ�
	/// </summary>
	void SortElement(bool flag = true)
	{
		Cell<T>* headCell = nullptr;

		for (int i = 0; i < (no - 1); i++)
		{
			for (int j = (no - 1); j > i; j--)
			{
				headCell = GetCell(j);
				if (flag)
				{
					if (headCell->value_ < headCell->prev_->value_)
					{
						T value = headCell->value_;
						ChangeValue(headCell->prev_->value_, j);
						ChangeValue(value, j - 1);
					}
				}
				else
				{
					if (headCell->value_ > headCell->prev_->value_)
					{
						T value = headCell->value_;
						ChangeValue(headCell->prev_->value_, j);
						ChangeValue(value, j - 1);
					}
				}
			}
		}
	}

	T GetElement(int num)
	{
		Cell<T>* headCell = nullptr;
		headCell = head;

		for (int i = 0; i < num + 1; i++)
		{
			headCell = headCell->next_;
		}

		return headCell->value_;
	}

private:

	// ����p�擪�̋�̃Z��
	Cell<T>* head;
	int no;

	// �Z�����w�������ɒǉ�
	void AddAfterCell(T v, Cell<T>* node)
	{
		// �V�����Z���𐶐�
		Cell<T>* newCell = new Cell<T>(v, node, node->next_);
		node->next_->prev_ = newCell;
		node->next_ = newCell;
		node = newCell;
		no++;
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* headCell = head;

		// �C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			headCell = headCell->next_;
		}

		return headCell;
	}
};
