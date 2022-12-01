#pragma once
#include <iostream>

template <typename T>
struct Cell
{
	//値
	T value_;
	//前のセルを指すポインタ
	Cell* prev_;
	//次のセルを指すポインタ
	Cell* next_;

	//コンストラクタ
	Cell()
	{
		//ダミーノードを用意
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

	//一番前に追加
	void PushFront(T value_)
	{
		Cell<T>* cur = head;
		AddAfterCell(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void PushBack(T value_)
	{
		Cell<T>* cur = head->prev_;
		AddAfterCell(value_, cur);
	}

	/// <summary>
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* headCell = nullptr;
		headCell = head;

		//任意の場所まで移動
		for (int i = 0; i < num; i++)
		{
			headCell = headCell->next_;
		}

		//追加
		AddAfterCell(value_, headCell);
	}

	/// <summary>
	/// 要素を検索
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
	/// 任意の場所の値を変更
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">変更する場所(0~)</param>
	bool ChangeValue(T value_, int num)
	{
		if (num < 0 || num>=no)
		{
			return false;
		}

		Cell<T>* headCell = nullptr;
		headCell = head;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			headCell = headCell->next_;
		}

		//変更
		headCell->value_ = value_;

		return true;
	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void ListDisplay()
	{
		Cell<T>* ptr = head->next_;

		std::cout << "要素一覧:{" << std::endl;

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
	/// 要素を指定
	/// </summary>
	/// <param name="num">指定する番号</param>
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

		//任意の場所まで移動
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
	/// 要素の入れ替え
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

	// 代入用先頭の空のセル
	Cell<T>* head;
	int no;

	// セルが指した後ろに追加
	void AddAfterCell(T v, Cell<T>* node)
	{
		// 新しいセルを生成
		Cell<T>* newCell = new Cell<T>(v, node, node->next_);
		node->next_->prev_ = newCell;
		node->next_ = newCell;
		node = newCell;
		no++;
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* headCell = head;

		// 任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			headCell = headCell->next_;
		}

		return headCell;
	}
};
