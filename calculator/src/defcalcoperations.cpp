#include "defcalcoperations.h"

#include <Calculator.h>
#include <cmath>
#include <string>

namespace my {

// --------------- БИНАРНЫЕ ОПЕРАЦИИ

	double Plus::operate(const std::string& lhs, const std::string& rhs) {
		return calculator_.calculateIn(lhs) + calculator_.calculateIn(rhs);
	}
	double Minus::operate(const std::string& lhs, const std::string& rhs) {
		return calculator_.calculateIn(lhs) - calculator_.calculateIn(rhs);
	}
	double Division::operate(const std::string& lhs, const std::string& rhs) {
		return calculator_.calculateIn(lhs) / calculator_.calculateIn(rhs);
	}
	double Multiplying::operate(const std::string& lhs, const std::string& rhs) {
		return calculator_.calculateIn(lhs) * calculator_.calculateIn(rhs);
	}
	double Power::operate(const std::string& lhs, const std::string& rhs) {
		return pow(calculator_.calculateIn(lhs), calculator_.calculateIn(rhs));
	}

	// -------------------------- УНАРНЫЕ ОПЕРАЦИИ

	double Arcsin::operate(const std::string& s) {
		return std::asin(calculator_.calculateIn(s));
	}

	double Arccos::operate(const std::string& s) {
		return acos(calculator_.calculateIn(s));
	}

	double Arcctg::operate(const std::string& s) {
		double x = calculator_.calculateIn(s);
		if (x >= 0)
			return asin(1.0 / sqrt(1.0 + x*x));
		else
			return My_PI - asin(1.0/sqrt(1.0 + x*x));
	}

	double Arctg::operate(const std::string& s) {
		return atan(calculator_.calculateIn(s));
	}

	double Cosec::operate(const std::string& s) {
		return 1.0 / sin(calculator_.calculateIn(s));
	}

	double Sqrt::operate(const std::string& s) {
		return sqrt(calculator_.calculateIn(s));
	}

	double Sech::operate(const std::string& s) {
		return 1.0 / cosh(calculator_.calculateIn(s));
	}

	double Csch::operate(const std::string& s) {
		return 1.0 / sinh(calculator_.calculateIn(s));
	}

	double Sin::operate(const std::string& s) {
		return sin(calculator_.calculateIn(s));
	}

	double Cos::operate(const std::string& s) {
		return cos(calculator_.calculateIn(s));
	}

	double Ctg::operate(const std::string& s) {
		return 1.0/tan( calculator_.calculateIn(s) );
	}

	double Sec::operate(const std::string& s) {
		return 1.0 / cos(calculator_.calculateIn(s));
	}

	double Cth::operate(const std::string& s) {
		return 1.0 / tanh(calculator_.calculateIn(s));
	}

	double Tg::operate(const std::string& s) {
		return tan(calculator_.calculateIn(s));
	}

	double Ln::operate(const std::string& s) {
		return log(calculator_.calculateIn(s));
	}

	double Lg::operate(const std::string& s) {
		return log10(calculator_.calculateIn(s));
	}

	double Sh::operate(const std::string& s) {
		return sinh(calculator_.calculateIn(s));
	}

	double Ch::operate(const std::string& s) {
		return cosh(calculator_.calculateIn(s));
	}

	double Th::operate(const std::string& s) {
		return tanh(calculator_.calculateIn(s));
	}

	double UnaryMinus::operate(const std::string& s) {
		return -calculator_.calculateIn(s);
	}

}
