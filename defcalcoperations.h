#pragma once
#ifndef DEFAULT_CALCULATOR_OPERATIONS_30042017_GASPARYANMOSES
#define DEFAULT_CALCULATOR_OPERATIONS_30042017_GASPARYANMOSES

#include <string>
#include "abstroperations.h"
#include "Calculator.h"

namespace my {

class Plus : public BinaryOperation {
public:
	explicit Plus(Calculator& calc) : BinaryOperation("+", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

class Minus : public BinaryOperation {
public:
	explicit Minus(Calculator& calc) : BinaryOperation("-", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

class Division : public BinaryOperation {
public:
	explicit Division(Calculator& calc) : BinaryOperation("/", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

class Multiplying : public BinaryOperation {
public:
	explicit Multiplying(Calculator& calc) : BinaryOperation("*", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

class Power : public BinaryOperation {
public:
	explicit Power(Calculator& calc) : BinaryOperation("^", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

}

#endif