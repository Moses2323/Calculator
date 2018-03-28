#pragma once
#ifndef DEFAULT_CALCULATOR_OPERATIONS_30042017_GASPARYANMOSES
#define DEFAULT_CALCULATOR_OPERATIONS_30042017_GASPARYANMOSES

#include "abstroperations.h"

#include <string>

namespace my {

class Calculator;

const double My_PI = 3.1415926535897932384626433832795;
const double My_E = 2.7182818284590452353602874713527;

// --------------- БИНАРНЫЕ ОПЕРАЦИИ

/*! \brief Операция + .
 *
 * Операция сложения ( 2+3 ).
 *
 */
class Plus : public BinaryOperation {
public:
	explicit Plus(Calculator& calc) : BinaryOperation("+", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief Операция - .
*
* Операция вычитания ( 2-3 ).
*
*/
class Minus : public BinaryOperation {
public:
	explicit Minus(Calculator& calc) : BinaryOperation("-", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief Операция * .
*
* Операция умножения ( 2*3 ).
*
*/
class Multiplying : public BinaryOperation {
public:
	explicit Multiplying(Calculator& calc) : BinaryOperation("*", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief Операция / .
*
* Операция деления ( 2/3 ).
*
*/
class Division : public BinaryOperation {
public:
	explicit Division(Calculator& calc) : BinaryOperation("/", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief Операция ^ .
*
* Операция степени ( 2^3 ).
*
*/
class Power : public BinaryOperation {
public:
	explicit Power(Calculator& calc) : BinaryOperation("^", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};


// -------------------------- УНАРНЫЕ ОПЕРАЦИИ


/*! \brief Арксинус .
*
*/
class Arcsin : public UnitOperation {
public:
	explicit Arcsin(Calculator& calc) : UnitOperation("arcsin", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Арккосинус .
*
*/
class Arccos : public UnitOperation {
public:
	explicit Arccos(Calculator& calc) : UnitOperation("arccos", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Арккотангенс .
*
*/
class Arcctg : public UnitOperation {
public:
	explicit Arcctg(Calculator& calc) : UnitOperation("arcctg", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Арктангенс .
*
*/
class Arctg : public UnitOperation {
public:
	explicit Arctg(Calculator& calc) : UnitOperation("arctg", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Косеканс .
*
*/
class Cosec : public UnitOperation {
public:
	explicit Cosec(Calculator& calc) : UnitOperation("cosec", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Взятие корня .
*
* Операция аналогична ^(0.5)
*
*/
class Sqrt : public UnitOperation {
public:
	explicit Sqrt(Calculator& calc) : UnitOperation("sqrt", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Секанс гиперболический .
*
*/
class Sech : public UnitOperation {
public:
	explicit Sech(Calculator& calc) : UnitOperation("sech", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Косеканс гиперболический .
*
*/
class Csch : public UnitOperation {
public:
	explicit Csch(Calculator& calc) : UnitOperation("csch", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Синус .
*
*/
class Sin : public UnitOperation {
public:
	explicit Sin(Calculator& calc) : UnitOperation("sin", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Косинус .
*
*/
class Cos : public UnitOperation {
public:
	explicit Cos(Calculator& calc) : UnitOperation("cos", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Котангенс .
*
*/
class Ctg : public UnitOperation {
public:
	explicit Ctg(Calculator& calc) : UnitOperation("ctg", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Секанс .
*
*/
class Sec : public UnitOperation {
public:
	explicit Sec(Calculator& calc) : UnitOperation("sec", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Котангенс гиперболический .
*
*/
class Cth : public UnitOperation {
public:
	explicit Cth(Calculator& calc) : UnitOperation("cth", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Тангенс .
*
*/
class Tg : public UnitOperation {
public:
	explicit Tg(Calculator& calc) : UnitOperation("tg", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Натуральный логарифм .
*
*/
class Ln : public UnitOperation {
public:
	explicit Ln(Calculator& calc) : UnitOperation("ln", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Десятичный логарифм .
*
*/
class Lg : public UnitOperation {
public:
	explicit Lg(Calculator& calc) : UnitOperation("lg", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Синус гиперболический .
*
*/
class Sh : public UnitOperation {
public:
	explicit Sh(Calculator& calc) : UnitOperation("sh", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Косинус гиперболический .
*
*/
class Ch : public UnitOperation {
public:
	explicit Ch(Calculator& calc) : UnitOperation("ch", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Тангенс гиперболический .
*
*/
class Th : public UnitOperation {
public:
	explicit Th(Calculator& calc) : UnitOperation("th", calc) {}
	virtual double operate(const std::string& s) override;
};

/*! \brief Унарный минус .
*
*/
class UnaryMinus : public UnitOperation {
public:
	explicit UnaryMinus(Calculator& calc) : UnitOperation("-", calc) {}
	virtual double operate(const std::string& s) override;
	virtual bool symbolBefore(char c) const override{
		if ((c == 'e') || (c == 'E'))
			return false;
		else
			return true;
	}
};

}

#endif
