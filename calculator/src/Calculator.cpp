#include <Calculator.h>

#include "abstroperations.h"
#include <calculatorexceptions.h>
#include "ForMistakes.h"

namespace my {

Calculator::Calculator(Calculator::OperationsType t) : operationsType_(t) {
	scobStack_.reserve(10);
	operations_.reserve(100);
}

Calculator::~Calculator() {}

void Calculator::checkCloseSymbolInStack(char toCheck, char openBracket, char closeBracket) {
	if (toCheck == closeBracket) {
		if ((scobStack_.size() > 0) && (scobStack_[scobStack_.size() - 1] == openBracket)) {
			scobStack_.pop_back();
		}
		else {
			throw my::SyntaxError(toStr(__FUNCTION__) + "(char,char,char)", __LINE__, __FILE__, "syntax error in bracket. Closing bracket are not correspond to opened bracket");
		}
	}
}

int Calculator::scob(const std::string& s, size_t beg) {
	scobStack_.resize(0);
	for (size_t i = beg; i < s.size(); ++i) {
#ifdef MDBG
		std::cout << "in scob cheking symbol " << s[i] << std::endl;
#endif

		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
			scobStack_.push_back(s[i]);
		}
		else {
			checkCloseSymbolInStack(s[i], '(', ')');
			checkCloseSymbolInStack(s[i], '[', ']');
			checkCloseSymbolInStack(s[i], '{', '}');
		}

		if (scobStack_.size() == 0)
			return i;
	}
	if (scobStack_.size() == 0)
		return beg;

	throw my::SyntaxError(toStr(__FUNCTION__) + "(const string&,size_t)", __LINE__, __FILE__, "there is no closing bracket");
}

int Calculator::rscob(const std::string& s, int beg) {
	scobStack_.resize(0);
	for (int i = beg; i >= 0; --i) {
#ifdef MDBG
		std::cout << "in rscob cheking symbol " << s[i] << std::endl;
#endif

		if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']')) {
			scobStack_.push_back(s[i]);
		}
		else {
			checkCloseSymbolInStack(s[i], ')', '(');
			checkCloseSymbolInStack(s[i], ']', '[');
			checkCloseSymbolInStack(s[i], '}', '{');
		}

		if (scobStack_.size() == 0)
			return i;
	}
	if (scobStack_.size() == 0)
		return beg;

	throw my::SyntaxError(toStr(__FUNCTION__) + "(const string&,size_t)", __LINE__, __FILE__, "there is no opening bracket");
}

size_t Calculator::rfindPassBrackets(const std::string & s, const std::string& whatFind, size_t beg){
//	int L = static_cast<int>(s.size());
	int Lwf = static_cast<int>(whatFind.size());
	if (Lwf == 0) {
		return s.size();
	}

	if (beg > s.size() - 1)
		beg = s.size() - 1;

	bool found;

	for (int i = static_cast<int>(beg); i >= 0; --i) {
		if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']')){
			i = rscob(s, i);
		}
		if (s[i] == whatFind[Lwf-1]) {
			found = true;
			for (int k = 2; k <= Lwf; ++k) {
				if (s[i-k+1] != whatFind[Lwf-k]) {
					found = false;
					break;
				}
			}
			if (found)
				return i - Lwf + 1;
		}
	}

	return std::string::npos;
}

bool Calculator::doWithoutSpaces(const std::string& s, std::string& vs) const {
	vs.clear();
	bool needToNewString = false;

	size_t fnd = 0;
	fnd = s.find(' ');
	if (fnd != std::string::npos) {
		needToNewString = true;
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] != ' ')
				vs.push_back(s[i]);
		}
	}
#ifdef MDBG
	std::cout << "vs in doWithoutSpaces = " << vs << std::endl;
#endif

	return needToNewString;
}

double Calculator::calculateIn(const std::string& s) {
	std::string withoutSpaces;
	if (doWithoutSpaces(s, withoutSpaces)) {
		return calculateIn(withoutSpaces);
	}
#ifdef MDBG
	std::cout << "s = \"" << s << "\"" << std::endl;
#endif
	int L = s.size();

	int lastSc = 0;
	int k = 0;
	for (; k < L; ++k) {
		if ((s[k] == '(') || (s[k] == '{') || (s[k] == '[')) {
			lastSc = scob(s, k);
			if (lastSc != L - k - 1)
				break;
		}
		else {
			break;
		}
	}
#ifdef MDBG
	std::cout << "in CalculateIn scob k = " << k << std::endl;
#endif
	if (k != 0)
		return calculateIn(s.substr(k, L - 2 * k));

	size_t find;
	BinaryOperation* bo;
	UnitOperation* uo;
	size_t begSymbol = std::string::npos;
	bool needUseBegSymbol = false;

	int Noper = static_cast<int>(operations_.size());

	for (int i = 0; i < Noper; ++i) {
		if (needUseBegSymbol) {
			find = rfindPassBrackets(s, operations_[i]->operName(), begSymbol);
			needUseBegSymbol = false;
		}
		else
			find = rfindPassBrackets(s, operations_[i]->operName());

		if (find != std::string::npos) {
			if (operations_[i]->type() == Operation::Type::Binary) {			//бинарный оператор
				if (find > 0) {
					bo = static_cast<BinaryOperation*>(operations_[i].get());

#ifdef MDBG
					std::cout << "Binary operation found = " << operations_[i]->operName() << std::endl;
					std::cout << "\t s1 = \"" << s.substr(0, find) << "\"" << std::endl;
					std::cout << "\t s2 = \"" << s.substr(find + (bo->operName()).size())<< "\"" << std::endl;
#endif

					if (bo->symbolBeforeIsNum(s[find - 1])) {
#ifdef MDBG
						std::cout << "\tthis is real binary operation. do calculate." << std::endl;
#endif
						return bo->operate(s.substr(0, find), s.substr(find + (bo->operName()).size()));
					}
					else {
						begSymbol = find - 1;
						needUseBegSymbol = true;
						--i;
#ifdef MDBG
						std::cout << "\tthis is NOT real binary operation. do nothing." << std::endl;
#endif
						continue;
					}
				}
			}
			else if (operations_[i]->type() == Operation::Type::Unity) {		//унарный оператор
				uo = static_cast<UnitOperation*>(operations_[i].get());
#ifdef MDBG
				std::cout << "Unary operation found = " << operations_[i]->operName() << std::endl;
				std::cout << "\t s = \"" << s.substr(find + uo->operName().size()) << "\"" << std::endl;
#endif
				if (find > 0) {
					char vvc = s[find-1];
					if (uo->symbolBefore(vvc)) {
						double result = uo->operate(s.substr(find + uo->operName().size()));
						std::stringstream vss;
						vss.precision(15);
						vss << result;
						std::string vs = s.substr(0, find) + vss.str();
					//	return uo->operate(s.substr(find + uo->operName().size()));
						return calculateIn(vs);
					}
					else {
						begSymbol = find - 1;
						needUseBegSymbol = true;
						--i;
						continue;
					}
				}
				return uo->operate(s.substr(find + uo->operName().size()));
			}
			else {
				print_mistaka(toStr(__FUNCTION__) + "(const string&)", __LINE__, "Unknown operation Type. It is not a Binary or Unity type.");
			}
		}
	}

	double d = 0;
	if (isDouble(s, d)) {
		return d;
	}
	else {
	        throw my::SyntaxError(toStr(__FUNCTION__) + "(const string&)", __LINE__, __FILE__, "Can\'t recognize operation \'" + s + "\'");
	}
}

}
