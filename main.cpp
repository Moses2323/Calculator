#include <iostream>
#include <fstream>
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

void doTest() {
	ifstream fin;
	fin.open("test.txt", ios::in);
	if (!fin.is_open()) {
		cout << "Can\'t open file with name" << endl;
		cout << "\ttest.txt" << endl;
		throw;
	}

	string s = "", vs;
	double res, trueRes;
	stringstream vss;

	my::DefaultCalculator calc;
	bool allTestsFinished = true;
	while (getline(fin, s)) {
		res = calc.calculateIn(s);
//		res = my::DefaultCalculator::calculate(s);
		getline(fin, vs);

		vss << vs;
		vss >> trueRes;
		if (trueRes != res) {
			allTestsFinished = false;
			cout << "TEST was not passed:" << endl;
			cout << "s = \"" << s << "\"" << endl;
			cout << "trueRes = " << trueRes << ", res = " << res << endl;
			break;
		}
		getline(fin, vs);

		s = "";
		vss.clear();
		vss.str("");
		vs = "";
#ifdef MDBG
		cout << endl << endl;
#endif
	}
	if (allTestsFinished) {
		cout << "ALL TESTS WERE PASSED" << endl << endl;
	}

	fin.close();
}

int main() {
	doTest();

	cout << setprecision(14);

	while (true) {
		try {
			string s = "";
			getline(cin, s);

			if (s == "exit") { break; }

			my::DefaultCalculator calc;
			double res = calc.calculateIn(s);
			cout << "RESULT = " << res << endl<<endl;
		}
		catch (my::SyntaxError er) {
			er.getError();
		}
	}

//	system("pause");
	return 0;
}