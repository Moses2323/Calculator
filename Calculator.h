#pragma once
#ifndef CALCULATOR_30042017_GASPARYANMOSES
#define CALCULATOR_30042017_GASPARYANMOSES

#include <vector>
#include <memory>
#include "abstroperations.h"
#include "ForMistakes.h"

namespace my {

class Calculator {
	public:
	enum class OperationsType : char {
		DefaultCalculator, BooleanCalculator
	};
private:
	const OperationsType operationsType_;

protected:
	std::vector<char> scobStack_;
	std::vector<std::unique_ptr<Operation>> operations_;
	
	void checkCloseSymbolInStack(char toCheck, char openBracket, char closeBracket);
	int scob(const std::string& s, size_t beg = 0);
	int rscob(const std::string& s, int beg);

	size_t rfindPassBrackets(const std::string& s, const std::string& whatFind);

	bool doWithoutSpaces(const std::string& s, std::string& vs) const;

	Calculator(OperationsType t) : operationsType_(t) {
		scobStack_.reserve(10);
		operations_.reserve(100);
	}

public:
	virtual ~Calculator() {}

	OperationsType getOperationsType() const { return operationsType_; }

	double calculateIn(const std::string& s);

};


}

#endif