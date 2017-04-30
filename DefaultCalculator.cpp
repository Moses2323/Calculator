#include "DefaultCalculator.h"

namespace my {

DefaultCalculator::DefaultCalculator() : Calculator(Calculator::OperationsType::DefaultCalculator) {
	operations_.push_back(std::unique_ptr<Plus>( new Plus(*this) ));
	operations_.push_back(std::unique_ptr<Minus>( new Minus(*this)));
	operations_.push_back(std::unique_ptr<Division>( new Division(*this)));
	operations_.push_back(std::unique_ptr<Multiplying>( new Multiplying(*this)));
	operations_.push_back(std::unique_ptr<Power>( new Power(*this)));
}

}