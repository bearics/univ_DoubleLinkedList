#include <iostream>
#include <cstdlib>
#include "Bag.h"

using namespace std;

void show_copy_constructor(Bag copy_bag);

int main(int argc, char *argv[])
{
	Bag bag;
	Bag::value_type data;
	int menu_bag = 0;

	// make temp bag
	Bag empty_bag;
	Bag temp_bag;
	Bag temp_bag2;
	Bag temp_bag3;

	while (1) {
		cout << endl << endl;
		bag.show_content();
		cout << "1. Insert" << endl;
		cout << "2. Erase" << endl;
		cout << "3. Count" << endl; 
		cout << "4. Sort" << endl;
		cout << "5. Show operator +, =" << endl;
		cout << "6. Show operator ==" << endl;
		cout << "7. Show operator +=" << endl;
		cout << "8. Show copy constructor" << endl;
		cout << "9. Exit" << endl;
		cout << "Type number : ";
		cin >> menu_bag;
		switch (menu_bag) {
		case 1:
			cout << "Type the data : ";
			cin >> data;
			bag.insert(data);
			break;
		case 2:
			cout << "Type the data : ";
			cin >> data;
			bag.erase_one(data);
			cout << "Finish to erase." << endl;
			break;
		case 3:
			cout << "Type the data : ";
			cin >> data;
			cout << data << " is been used " << bag.count(data) << " times in bag." << endl;
			break;
		case 4:
			cout << "--------------------------------------" << endl;
			cout << "              Show Sort" << endl;
			cout << "--------------------------------------" << endl;
			cout << "    bag's list" << endl;
			bag.show_content();
			bag.sort();
			cout << "    After sort." << endl;
			bag.show_content();
			break;
		case 5:
			temp_bag = empty_bag;
			temp_bag2 = empty_bag;
			temp_bag3 = empty_bag;
			temp_bag.insert(1);
			temp_bag.insert(2);
			temp_bag2.insert(10);
			cout << endl << endl;
			cout << "--------------------------------------" << endl;
			cout << "          Show operator =, +" << endl;
			cout << "--------------------------------------" << endl;
			cout << "    temp_bag's list" << endl;
			temp_bag.show_content();
			cout << "    temp_bag2's list" << endl;
			temp_bag2.show_content();
			temp_bag3 = temp_bag + temp_bag2;
			cout << endl << "         Result" << endl;
			cout << "temp_bag3 = temp_bag + temp_bag2" << endl << endl;
			temp_bag3.show_content();
			cout << endl << endl;
			break;
		case 6:
			temp_bag = empty_bag;
			temp_bag2 = empty_bag;
			temp_bag3 = empty_bag;
			temp_bag.insert(1);
			cout << "--------------------------------------" << endl;
			cout << "          Show operator ==" << endl;
			cout << "--------------------------------------" << endl;
			cout << "temp_bag == temp_bag" << endl << "Result : ";
			if (temp_bag == temp_bag)
				cout << "True" << endl;
			else
				cout << "False" << endl;

			cout << "temp_bag == temp_bag2" << endl << "Result : ";
			if (temp_bag == temp_bag2)
				cout << "True" << endl;
			else
				cout << "False" << endl;
			break;
		case 7:
			temp_bag = empty_bag;
			temp_bag2 = empty_bag;
			temp_bag3 = empty_bag;
			temp_bag.insert(5);
			temp_bag.insert(6);
			temp_bag2.insert(9);
			cout << endl << endl;
			cout << "--------------------------------------" << endl;
			cout << "          Show operator +=" << endl;
			cout << "--------------------------------------" << endl;
			cout << "    temp_bag's list" << endl;
			temp_bag.show_content();
			cout << "    temp_bag2's list" << endl;
			temp_bag2.show_content();
			temp_bag += temp_bag2;
			cout << "--------------------------------------" << endl;
			cout << "         Result" << endl;
			cout << "temp_bag += temp_bag2" << endl;
			cout << "--------------------------------------" << endl;
			cout << "    temp_bag's list" << endl;
			temp_bag.show_content();
			cout << endl << endl;
			break;
		case 8:
			temp_bag = empty_bag;
			show_copy_constructor(bag);
			break;
		case 9:
			return 0;
		}
	}
}

void show_copy_constructor(Bag copy_bag)
{
	Bag copyBag(copy_bag);
	cout << "--------------------------------------" << endl;
	cout << "          Show copy constructor" << endl;
	cout << "--------------------------------------" << endl;
	cout << "          bag's list" << endl;
	copy_bag.show_content();
	cout << "--------------------------------------" << endl;
	cout << "        Make copy constructor" << endl;
	cout << "        Bag copyBag(bag)" << endl;
	cout << "--------------------------------------" << endl;
	cout << "    copyBag's list" << endl;
	copyBag.show_content();
}