#include "defcalcoperations.h"

namespace my {

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

}