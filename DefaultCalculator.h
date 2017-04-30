#pragma once
#ifndef DEFAULT_CALCULATOR_30042017_GASPARYANMOSES
#define DEFAULT_CALCULATOR_30042017_GASPARYANMOSES

#include "defcalcoperations.h"

namespace my {

class DefaultCalculator : public Calculator {
public:
	DefaultCalculator();
	virtual ~DefaultCalculator() {}

	static double calculate(const std::string& s) {
		static DefaultCalculator calc;
		return calc.calculateIn(s);
	}
};

}

#endif