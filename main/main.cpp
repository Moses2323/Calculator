#include <iostream>
#include <fstream>

#include <DefaultCalculator.h>
#include <calculatorexceptions.h>

void testString() {
	std::string vs;
	std::string toFind = "sin";
	vs = "sin";
	size_t find = vs.rfind(toFind);
	std::cout << find << std::endl;

	std::string vs2 = "sdfsdf";
	vs2 = vs.substr(find + toFind.size());
	std::cout << "\""<<vs2 << "\", size = " << vs2.size() << std::endl;
}

void doTest(const std::string& filename) {
	std::cout << "TESTING STARTED..." << std::endl;
	std::ifstream fin;
	fin.open(filename, std::ios::in);
	if (!fin.is_open()) {
		std::cout << "Can\'t open file with name" << std::endl;
		std::cout << "\ttest.txt" << std::endl;
		throw;
	}

	std::string s = "", vs;
	double res, trueRes;
	std::stringstream vss;

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
			std::cout << "TEST was not passed:" << std::endl;
			std::cout << "s = \"" << s << "\"" << std::endl;
			std::cout << "trueRes = " << trueRes << ", res = " << res << std::endl;
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
		std::cout << "ALL TESTS WERE PASSED" << std::endl << std::endl;
	}

	fin.close();
}

int main() {
    #ifdef TESTING
	doTest("../../test.txt");
    #endif

	std::cout << std::setprecision(14);

	std::cout << "This is calculator. Just print your expression here (ex.: \"2+3*4\")." << std::endl;
	std::cout << "To exit from calculator print \"exit\"" << std::endl << std::endl;

	while (true) {
		try {
			std::string s = "";
			getline(std::cin, s);
            #ifdef TESTING
			std::cout << "s = " << s << std::endl;
            #endif

			if (s == "exit") { break; }

			my::DefaultCalculator calc;
			double res = calc.calculateIn(s);
			std::cout << "RESULT = " << res << std::endl << std::endl;
		}
		catch (my::SyntaxError er) {
			er.getError();
		}
	}

	return 0;
}
