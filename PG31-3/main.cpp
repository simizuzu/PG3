#include <stdio.h>
#include <vector>
#include <list>

int main()
{
	std::list<const char *> lst = {
		"Tokyo","Yurakucho","Shimbashi","Hamamatsucho","Tamachi",
		"Shinagawa","Osaki","Gotanda","Meguro","Ebisu",
		"Shibuya","Harajuku","Yoyogi","Shinjuku","Shin-Okubo",
		"Takadanobaba","Mejiro","Ikebukuro","Otsuka","Sugamo",
		"Komagome","Tabata","Nippori","Uguisudani","Ueno",
		"Okachimachi","Akihabara","Kanda"
	};
	printf("1970�N\n");
	for (const char* i : lst)
	{
		printf("%s\n", i);
	}

	// ���闢�w�̑O�ɐ����闢�w��ǉ�
	for (std::list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == "Nippori")
		{
			itr = lst.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}
	printf("\n2019�N\n");
	for (const char* j : lst)
	{
		printf("%s\n", j);
	}

	// �i��w�̑O�ɍ��փQ�[�g�E�F�C�w��ǉ�
	for (std::list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = lst.insert(itr, "Takanawa-Gateway");
			++itr;
		}
	}
	printf("\n2022�N\n");
	for (const char* k : lst)
	{
		printf("%s\n", k);
	}

	return 0;
}