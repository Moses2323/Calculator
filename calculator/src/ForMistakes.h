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

}

#endif
