#include "abstroperations.h"


my::Operation::Operation(const my::Operation::Type& type_in, const std::string& operName_in, my::Calculator& calculator)
    : type_(type_in), operName_(operName_in), calculator_(calculator) {}

my::Operation::~Operation() {}

bool my::BinaryOperation::symbolBeforeIsNum(char c) const {
	if (isdigit(c) || (c == ')') || (c == ']') || (c == '}'))		//значит это бинарный оператор
		return true;
	else                //значит не бинарный оператор
		return false;
}

my::UnitOperation::UnitOperation(const std::string& operName_in, my::Calculator& calc)
    : Operation(Type::Unity, operName_in, calc) {}
