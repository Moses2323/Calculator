#include <iostream>
#include "DefaultCalculator.h"
using namespace std;


void testDouble() {
	/*
	stringstream vss;
	vss << "-.e4";
	double ddd = -2;
	vss >> ddd;
	cout << ddd << endl;
	system("pause");
	return 0;
	*/

	string vs;
	while (1) {
		cin >> vs;
		double d;
		if (my::isDouble(vs,d))
			cout << "it is Double" << endl << endl;
		else
			cout << "it is NOT double" << endl << endl;

		vs.clear();
		vs = "";
	}
}

void testString() {
	string vs;
	string toFind = "sin";
	vs = "sin";
	size_t find = vs.rfind(toFind);
	cout << find << endl;

	string vs2 = "sdfsdf";
	vs2 = vs.substr(find + toFind.size());
	cout << "\""<<vs2 <<"\", size = "<<vs2.size()<< endl;
}

int main() {
//	testString();

	while (true) {
		try {
			string s = "";
			getline(cin, s);

			my::DefaultCalculator calc;
			double res = calc.calculateIn(s);
			cout << "RESULT = " << res << endl<<endl;
		}
		catch (my::SyntaxError er) {
			er.getError();
		}
	}

	system("pause");
	return 0;
}