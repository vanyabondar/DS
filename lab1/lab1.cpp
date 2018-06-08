#include "List.h"
#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;
List *First = nullptr;
List *Second = nullptr;

int main()
{
	int x, n;
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> s;
		Add(&First, x, s);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> s;
		Add(&Second, x, s);
	}

	cout << "List1:" << endl;
	Write(First);

	cout << "List2:" << endl;
	Write(Second);

	Pasting(&First, &Second);

	cout << "List3:" << endl;
	Write(First);

	Clear(First);
	system("pause");

	return 0;
}
