#pragma once
#ifndef FORMISTAKES_30042017_GASPARYANMOSES
#define FORMISTAKES_30042017_GASPARYANMOSES

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace my{

template<typename T>
inline std::string toStr(const T& p) {
	std::stringstream vss;
	vss << p;
	return vss.str();
}

inline void print_mistaka(const std::string& funcName, int line, const std::string& message) {
	std::cerr << "ERROR in " << funcName << " : line " << line << std::endl;
	std::cerr << "\t" << message << std::endl;
	throw;
}

template<typename T>
inline void printVec(const std::vector<T>& v, std::ostream& fout = std::cout) {
	fout << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		fout << " " << v[i] << " ";
	}
	fout << "]";
}

inline bool isDouble(const std::string& s, double& d) {
#ifdef MDBG
	std::cout << "isDouble launched with s=\"" << s << "\"" << std::endl;
#endif

	if (s.size() == 0)
		return false;

	if (!isdigit(s[0])) {	//-4, .3,  +5
		if ((s[0] == '.') || (s[0] == '-') || (s[0] == '+')) {
			if (s.size() == 1)			// "-", "+", "."
				return false;

			if (!isdigit(s[1])) {		// "-g", "--", "+h",  ".y"
				return false;
			}
		}
		else {				// g,   sfsfs,   ui
			return false;
		}
	}

	std::stringstream vss;
	std::string vs;

	vss << s;

	vss >> d;

	vss >> vs;
#ifdef MDBG
	std::cout << "d = " << d << std::endl;
#endif

	if (vs.size() > 0)		// 1g ,   2e-34ui  , -34e-3i
		return false;
	else
		return true;
}

class SyntaxError : std::exception {
	std::string funcName_;
	int line_;
	std::string fileName_;
	std::string message_;

	std::string createError() const {
		std::stringstream vss;
		vss << "Syntax ERROR in " << funcName_ << " : line " << line_ << ", file " << fileName_ << std::endl;
		vss << "\t" << message_ << std::endl;
		return vss.str();
	}

public:
	SyntaxError(const std::string& funcName, const int& line, const std::string& fileName, const std::string& message) : funcName_(funcName), line_(line), fileName_(fileName), message_(message) {}

	void getError(std::ostream& fout = std::cerr) const { fout << createError(); }
	std::string getErrorText() const { return createError(); }
};

}

#endif
