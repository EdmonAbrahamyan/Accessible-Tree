#include "List.h"

int main()
{
	List lst;
	cout << endl << "*****   INSERTIONS: *****" << endl;
	lst.insert(1, 10);
	lst.insert(1, 20);
	lst.insert(2, 30);
	lst.insert(4, 50);
	lst.insert(2, 60);
	lst.insert(4, 40);
	lst.print();

	cout << endl << "*****   REMOVAL AT 3-rd POSITION: *****" << endl;
	lst.remove(3);
	lst.print();

	cout << endl << "*****   REMOVAL AT 4-th POSITION: *****" << endl;
	lst.remove(4);
	lst.print();

	cout << endl << "*****   REMOVAL AT 1-st POSITION: *****" << endl;
	lst.remove(1);
	lst.print();
	system("pause");
	return 0;
}

