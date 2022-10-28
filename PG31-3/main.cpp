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
	printf("1970年\n");
	for (const char* i : lst)
	{
		printf("%s\n", i);
	}

	// 日暮里駅の前に西日暮里駅を追加
	for (std::list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == "Nippori")
		{
			itr = lst.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}
	printf("\n2019年\n");
	for (const char* j : lst)
	{
		printf("%s\n", j);
	}

	// 品川駅の前に高輪ゲートウェイ駅を追加
	for (std::list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == "Shinagawa")
		{
			itr = lst.insert(itr, "Takanawa-Gateway");
			++itr;
		}
	}
	printf("\n2022年\n");
	for (const char* k : lst)
	{
		printf("%s\n", k);
	}

	return 0;
}