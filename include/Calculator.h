#pragma once
#ifndef CALCULATOR_30042017_GASPARYANMOSES
#define CALCULATOR_30042017_GASPARYANMOSES

#include <vector>
#include <memory>
#include <iomanip>
#include "abstroperations.h"

namespace my {

/*! \brief Абстрактный класс для калькулятора.
 *
 * Абстрактный класс для калькулятора.
 *
 * Имеет все необходимые методы, чтобы вычислять, но
 * не заполняет вектор операций.
 * В векторе операций все операции расположены по приоритету:
 * 0 - самый меньший приоритет.
 *
 * Классы-потомки должны лишь заполнять вектор операций.
 * 
 */
class Calculator {
	public:
	//! Перечислимый класс для типа калькулятора.
	enum class OperationsType : char {
		DefaultCalculator, BooleanCalculator
	};
private:
	//! Тип калькулятора.
	const OperationsType operationsType_;

protected:
	//! Вспомогательный вектор для стека скобок. Используется в любых функциях для проверки открывающей-закрывающей скобки.
	std::vector<char> scobStack_;
	//! Вектор операций. Все операции расположены по приоритету. 0 - самый меньший приоритет.
	std::vector<std::unique_ptr<Operation>> operations_;
	
	//! Функция удаляет последнюю скобку из стека скобок, если входной символ - это closeBracket. Иначе - не делает ничего. Если входной символ - closeBracket, но в стеке не openBracket, то пробрасывается исключение.
	void checkCloseSymbolInStack(char toCheck, char openBracket, char closeBracket);
	//! Функция возвращает индекс в строке для закрывающей скобки. Если входной символ не является открывающей скобкой, то просто возвращает beg.
	int scob(const std::string& s, size_t beg = 0);
	//! Функция возвращает индекс в строке для открывающей скобки. Если входной символ не является закрывающей скобкой, то просто возвращает beg.
	int rscob(const std::string& s, int beg);

	//! Функция ищет вхождение whatFind в строке s, пропуская скобки. Поиск начинается с позиции beg и идет с конца строки в начало. Возвращает начальный символ вхождения. Если идет поиск пустой строки, то возвращается просто размер строки.
	size_t rfindPassBrackets(const std::string& s, const std::string& whatFind, size_t beg = std::string::npos);

	//! Функция превращает строку vs в строку s без пробелов, если находит хоть один пробел. Возвращает true, если хоть один пробел найден.
	bool doWithoutSpaces(const std::string& s, std::string& vs) const;

	//! Конструктор. Принимает тип калькулятора.
	explicit Calculator(OperationsType t) : operationsType_(t) {
		scobStack_.reserve(10);
		operations_.reserve(100);
	}

public:
	//! Деструктор.
	virtual ~Calculator() {}

	//! Функция возвращает тип калькулятора. \details Читает приватное поле operationsType_.
	OperationsType getOperationsType() const { return operationsType_; }

	//! Функция вычисляет значение входного выражения.
	double calculateIn(const std::string& s);

};


}

#endif
