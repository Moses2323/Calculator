#include "DefaultCalculator.h"

namespace my {

DefaultCalculator::DefaultCalculator() : Calculator(Calculator::OperationsType::DefaultCalculator) {
	operations_.push_back(std::unique_ptr<Plus>( new Plus(*this) ));
	operations_.push_back(std::unique_ptr<Minus>( new Minus(*this)));
	
	operations_.push_back(std::unique_ptr<Multiplying>( new Multiplying(*this)));
	operations_.push_back(std::unique_ptr<Division>(new Division(*this)));

//	operations_.push_back(std::unique_ptr<Power>( new Power(*this)));

	operations_.push_back(std::unique_ptr<Arcsin>(new Arcsin(*this)));
	operations_.push_back(std::unique_ptr<Arccos>(new Arccos(*this)));
	operations_.push_back(std::unique_ptr<Arcctg>(new Arcctg(*this)));
	operations_.push_back(std::unique_ptr<Cosec>(new Cosec(*this)));
	operations_.push_back(std::unique_ptr<Sqrt>(new Sqrt(*this)));
	operations_.push_back(std::unique_ptr<Sech>(new Sech(*this)));
	operations_.push_back(std::unique_ptr<Csch>(new Csch(*this)));
	operations_.push_back(std::unique_ptr<Sin>(new Sin(*this)));
	operations_.push_back(std::unique_ptr<Cos>(new Cos(*this)));
	operations_.push_back(std::unique_ptr<Ctg>(new Ctg(*this)));
	operations_.push_back(std::unique_ptr<Sec>(new Sec(*this)));
	operations_.push_back(std::unique_ptr<Cth>(new Cth(*this)));
	operations_.push_back(std::unique_ptr<Tg>(new Tg(*this)));
	operations_.push_back(std::unique_ptr<Ln>(new Ln(*this)));
	operations_.push_back(std::unique_ptr<Lg>(new Lg(*this)));
	operations_.push_back(std::unique_ptr<Sh>(new Sh(*this)));
	operations_.push_back(std::unique_ptr<Ch>(new Ch(*this)));
	operations_.push_back(std::unique_ptr<Th>(new Th(*this)));

	operations_.push_back(std::unique_ptr<UnaryMinus>(new UnaryMinus(*this)));

	operations_.push_back(std::unique_ptr<Power>(new Power(*this)));
}

}