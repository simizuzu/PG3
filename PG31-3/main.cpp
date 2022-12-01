#include <iostream>
#include"MyList.h"
#include<string>

// 関数オーバーロード
template<typename T>
void Display(Mylist<T>& list, int& operationNum, int& displayOperationNum);

template<typename T>
void InsertElement(Mylist<T>& list, int& operationNum);

template<typename T>
void EditElement(Mylist<T>& list, int& operationNum);

template<typename T>
void DeleteElement(Mylist<T>& list, int& operationNum);

template<typename T>
void ChangeElement(Mylist<T>& list, int& operationNum);

int main()
{
	Mylist<std::string> list;

	// 要素一覧
	list.PushBack("banana");
	list.PushBack("apple");
	list.PushBack("orange");

	// 要素の操作の操作番号
	int operationNum = 0;
	// 要素の表示の操作番号
	int displayOpeNum = 0;

	while (true)
	{
		// 要素の操作(初期画面)
		std::cout << "[要素の操作]" << std::endl;
		std::cout << "1.要素の表示" << std::endl;
		std::cout << "2.要素の挿入" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.要素の編集" << std::endl;
			std::cout << "4.要素の削除" << std::endl;
		}

		std::cout << "5.要素の並び替え(オプション)" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "操作を選択してください" << std::endl;

		std::cout << std::endl;

		if (operationNum == 0)
		{
			// 操作番号を取得
			std::cin >> operationNum;
		}
		system("cls");

		switch (operationNum)
		{
		case 1:// 要素の表示
			Display(list, operationNum, displayOpeNum);
			break;

		case 2:// 最後尾に要素を追加
			InsertElement(list, operationNum);
			break;

		case 3:// 任意の場所の値を変更
			EditElement(list, operationNum);
			break;

		case 4:// 任意の場所の削除
			DeleteElement(list, operationNum);
			break;

		case 5:// 任意の場所と任意の場所を入れ替え
			ChangeElement(list, operationNum);
			break;
		}
	}

	return 0;
}

// 1番目の画面
template<typename T>
void Display(Mylist<T>& list, int& operationNum, int& displayOpeNum)
{
	std::cout << "[要素の表示]" << std::endl;
	std::cout << "1.要素の一覧表示" << std::endl;
	std::cout << "2.順番を指定して要素を表示" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;
	std::cout << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	// 操作番号を取得
	std::cin >> displayOpeNum;
	system("cls");

	switch (displayOpeNum)
	{
	case 1:
		std::cout << "[要素の一覧表示]" << std::endl;

		// 一覧表示
		list.ListDisplay();

		std::cout << "要素数:" << list.Size() << std::endl;

		break;
	case 2:
		std::cout << "[順番を指定して要素を表示]" << std::endl;
		std::cout << "表示したい要素の順番を指定してください。" << std::endl;

		// 指定する番号を取得
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		// 指定して表示
		list.SpecifyElement(specifyNum);
		break;

	case 9:
		operationNum = 0;
		break;
	}

	// 要素操作に戻らなかったら
	if (displayOpeNum == 1 || displayOpeNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.要素の表示に戻る" << std::endl;
		std::cout << "2.要素の操作に戻る" << std::endl;

		// 操作番号を取得
		std::cin >> displayOpeNum;
		system("cls");

		switch (displayOpeNum)
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

// 2番目の画面
template<typename T>
void InsertElement(Mylist<T>& list, int& operationNum)
{
	std::cout << "[リスト要素の挿入]" << std::endl;
	std::cout << std::endl;
	std::cout << "要素を追加場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "追加する要素の値を入力してください" << std::endl;
		T element{};

		std::cin >> element;

		list.PushBack(element);

		std::cout << "要素" << element << "が" << "最後尾に挿入されました" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "追加する要素の値を入力してください" << std::endl;
		T element{};

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "要素" << element << "が" << index << "番目に挿入されました" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		// 9を押したとき初期画面に戻る
		operationNum = 0;
	}
	else
	{
		// 9以外を押したとき[リスト要素の編集]の最初の画面に戻る
		operationNum = 2;
	}
}

// 3番目の画面
template<typename T>
void EditElement(Mylist<T>& list, int& operationNum)
{
	std::cout << "[要素の編集]" << std::endl;
	std::cout << std::endl;
	std::cout << "編集したい要素の番号を入力してください" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.SearchElement(elementNum))
	{
		std::cout << elementNum << "番目の要素の変更する値を入力してください。" << std::endl;

		T changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elementNum);
		std::cout << std::endl;

		std::cout << elementNum << "番目の要素の値が" << '"' << changeElement << '"' << "に変更されました" << std::endl;
	}
	else
	{
		std::cout << elementNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		// 9を押したとき初期画面に戻る
		operationNum = 0;
	}
	else
	{
		// 9以外を押したとき[要素の編集]の最初の画面に戻る
		operationNum = 3;
	}
}

// 4番目の画面
template<typename T>
void DeleteElement(Mylist<T>& list, int& operationNum)
{
	std::cout << "[要素の削除]" << std::endl;
	std::cout << std::endl;
	std::cout << "削除したい要素の番号を指定してください" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.SearchElement(elementNum))
	{
		std::cout << elementNum << "番目の要素" << '"' << list.GetElement(elementNum) << '"' << "削除しました" << std::endl;

		list.Delete(elementNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elementNum << "番目の要素が見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		// 9を押したとき初期画面に戻る
		operationNum = 0;
	}
	else
	{
		// 9以外を押したとき[要素の削除]の最初の画面に戻る
		operationNum = 4;
	}
}

// 5番目の画面
template<typename T>
void ChangeElement(Mylist<T>& list, int& operationNum)
{
	std::cout << "[要素の並び替え]" << std::endl;
	std::cout << std::endl;
	std::cout << "並び替え方法を選択してください" << std::endl;
	std::cout << "1.昇順で並び替える" << std::endl;
	std::cout << "2.降順で並び替える" << std::endl;

	int changeSortNum;

	std::cin >> changeSortNum;

	switch (changeSortNum)
	{
	case 1:
	{
		list.SortElement();
		std::cout << "リストの要素を昇順で並び替えました" << std::endl;
	}
	break;

	case 2:
		list.SortElement(false);
		std::cout << "リストの要素を降順で並び替えました" << std::endl;
		break;

	default:
		break;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		// 9を押したとき初期画面に戻る
		operationNum = 0;
	}
	else
	{
		// 9以外を押したとき[要素並び替え]の最初の画面に戻る
		operationNum = 5;
	}
}