#pragma once
#ifndef CALCULATOREXCEPTIONS_GASPARYAN_MOSES_28032018
#define CALCULATOREXCEPTIONS_GASPARYAN_MOSES_28032018

#include <iostream>
#include <sstream>
#include <string>

namespace my{

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
	SyntaxError(const std::string& funcName, const int& line, const std::string& fileName, const std::string& message)
	    : funcName_(funcName), line_(line), fileName_(fileName), message_(message) {}

	void getError(std::ostream& fout = std::cerr) const { fout << createError(); }
	std::string getErrorText() const { return createError(); }
};

}

#endif // CALCULATOREXCEPTIONS_GASPARYAN_MOSES_28032018
