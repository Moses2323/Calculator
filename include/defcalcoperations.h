#pragma once
#ifndef DEFAULT_CALCULATOR_OPERATIONS_30042017_GASPARYANMOSES
#define DEFAULT_CALCULATOR_OPERATIONS_30042017_GASPARYANMOSES

#include <string>
#include <cmath>
#include "abstroperations.h"
#include "Calculator.h"

namespace my {

const double My_PI = 3.1415926535897932384626433832795;
const double My_E = 2.7182818284590452353602874713527;

// --------------- �������� ��������

/*! \brief �������� + .
 *
 * �������� �������� ( 2+3 ).
 *
 */
class Plus : public BinaryOperation {
public:
	explicit Plus(Calculator& calc) : BinaryOperation("+", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief �������� - .
*
* �������� ��������� ( 2-3 ).
*
*/
class Minus : public BinaryOperation {
public:
	explicit Minus(Calculator& calc) : BinaryOperation("-", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief �������� * .
*
* �������� ��������� ( 2*3 ).
*
*/
class Multiplying : public BinaryOperation {
public:
	explicit Multiplying(Calculator& calc) : BinaryOperation("*", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief �������� / .
*
* �������� ������� ( 2/3 ).
*
*/
class Division : public BinaryOperation {
public:
	explicit Division(Calculator& calc) : BinaryOperation("/", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};

/*! \brief �������� ^ .
*
* �������� ������� ( 2^3 ).
*
*/
class Power : public BinaryOperation {
public:
	explicit Power(Calculator& calc) : BinaryOperation("^", calc) {}
	virtual double operate(const std::string& lhs, const std::string& rhs) override;
};


// -------------------------- ������� ��������


/*! \brief �������� .
*
*/
class Arcsin : public UnitOperation {
public:
	explicit Arcsin(Calculator& calc) : UnitOperation("arcsin", calc) {}
	virtual double operate(const std::string& s) override {
		return std::asin(calculator_.calculateIn(s));
	}
};

/*! \brief ���������� .
*
*/
class Arccos : public UnitOperation {
public:
	explicit Arccos(Calculator& calc) : UnitOperation("arccos", calc) {}
	virtual double operate(const std::string& s) override {
		return acos(calculator_.calculateIn(s));
	}
};

/*! \brief ������������ .
*
*/
class Arcctg : public UnitOperation {
	inline double actg(const double& x) const {
		if (x >= 0)
			return asin(1.0 / sqrt(1.0 + x*x));
		else
			return My_PI - asin(1.0/sqrt(1.0 + x*x));
	}

public:
	explicit Arcctg(Calculator& calc) : UnitOperation("arcctg", calc) {}
	virtual double operate(const std::string& s) override {
		return actg(calculator_.calculateIn(s));
	}
};

/*! \brief ���������� .
*
*/
class Arctg : public UnitOperation {
public:
	explicit Arctg(Calculator& calc) : UnitOperation("arctg", calc) {}
	virtual double operate(const std::string& s) override {
		return atan(calculator_.calculateIn(s));
	}
};

/*! \brief �������� .
*
*/
class Cosec : public UnitOperation {
public:
	explicit Cosec(Calculator& calc) : UnitOperation("cosec", calc) {}
	virtual double operate(const std::string& s) override {
		return 1.0 / sin(calculator_.calculateIn(s));
	}
};

/*! \brief ������ ����� .
*
* �������� ���������� ^(0.5)
*
*/
class Sqrt : public UnitOperation {
public:
	explicit Sqrt(Calculator& calc) : UnitOperation("sqrt", calc) {}
	virtual double operate(const std::string& s) override {
		return sqrt(calculator_.calculateIn(s));
	}
};

/*! \brief ������ ��������������� .
*
*/
class Sech : public UnitOperation {
public:
	explicit Sech(Calculator& calc) : UnitOperation("sech", calc) {}
	virtual double operate(const std::string& s) override {
		return 1.0 / cosh(calculator_.calculateIn(s));
	}
};

/*! \brief �������� ��������������� .
*
*/
class Csch : public UnitOperation {
public:
	explicit Csch(Calculator& calc) : UnitOperation("csch", calc) {}
	virtual double operate(const std::string& s) override {
		return 1.0 / sinh(calculator_.calculateIn(s));
	}
};

/*! \brief ����� .
*
*/
class Sin : public UnitOperation {
public:
	explicit Sin(Calculator& calc) : UnitOperation("sin", calc) {}
	virtual double operate(const std::string& s) override {
		return sin(calculator_.calculateIn(s));
	}
};

/*! \brief ������� .
*
*/
class Cos : public UnitOperation {
public:
	explicit Cos(Calculator& calc) : UnitOperation("cos", calc) {}
	virtual double operate(const std::string& s) override {
		return cos(calculator_.calculateIn(s));
	}
};

/*! \brief ��������� .
*
*/
class Ctg : public UnitOperation {
	inline double ctg(const double& x) const {
		return 1.0/tan(x);
	}

public:
	explicit Ctg(Calculator& calc) : UnitOperation("ctg", calc) {}
	virtual double operate(const std::string& s) override {
		return ctg(calculator_.calculateIn(s));
	}
};

/*! \brief ������ .
*
*/
class Sec : public UnitOperation {
public:
	explicit Sec(Calculator& calc) : UnitOperation("sec", calc) {}
	virtual double operate(const std::string& s) override {
		return 1.0 / cos(calculator_.calculateIn(s));
	}
};

/*! \brief ��������� ��������������� .
*
*/
class Cth : public UnitOperation {
public:
	explicit Cth(Calculator& calc) : UnitOperation("cth", calc) {}
	virtual double operate(const std::string& s) override {
		return 1.0 / tanh(calculator_.calculateIn(s));
	}
};

/*! \brief ������� .
*
*/
class Tg : public UnitOperation {
public:
	explicit Tg(Calculator& calc) : UnitOperation("tg", calc) {}
	virtual double operate(const std::string& s) override {
		return tan(calculator_.calculateIn(s));
	}
};

/*! \brief ����������� �������� .
*
*/
class Ln : public UnitOperation {
public:
	explicit Ln(Calculator& calc) : UnitOperation("ln", calc) {}
	virtual double operate(const std::string& s) override {
		return log(calculator_.calculateIn(s));
	}
};

/*! \brief ���������� �������� .
*
*/
class Lg : public UnitOperation {
public:
	explicit Lg(Calculator& calc) : UnitOperation("lg", calc) {}
	virtual double operate(const std::string& s) override {
		return log10(calculator_.calculateIn(s));
	}
};

/*! \brief ����� ��������������� .
*
*/
class Sh : public UnitOperation {
public:
	explicit Sh(Calculator& calc) : UnitOperation("sh", calc) {}
	virtual double operate(const std::string& s) override {
		return sinh(calculator_.calculateIn(s));
	}
};

/*! \brief ������� ��������������� .
*
*/
class Ch : public UnitOperation {
public:
	explicit Ch(Calculator& calc) : UnitOperation("ch", calc) {}
	virtual double operate(const std::string& s) override {
		return cosh(calculator_.calculateIn(s));
	}
};

/*! \brief ������� ��������������� .
*
*/
class Th : public UnitOperation {
public:
	explicit Th(Calculator& calc) : UnitOperation("th", calc) {}
	virtual double operate(const std::string& s) override {
		return tanh(calculator_.calculateIn(s));
	}
};

/*! \brief ������� ����� .
*
*/
class UnaryMinus : public UnitOperation {
public:
	explicit UnaryMinus(Calculator& calc) : UnitOperation("-", calc) {}
	virtual double operate(const std::string& s) override {
		return -calculator_.calculateIn(s);
	}
	virtual bool symbolBefore(char c) const override{
		if ((c == 'e') || (c == 'E'))
			return false;
		else
			return true;
	}
};

}

#endif
