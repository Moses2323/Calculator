#pragma once
#ifndef DEFAULT_CALCULATOR_30042017_GASPARYANMOSES
#define DEFAULT_CALCULATOR_30042017_GASPARYANMOSES

#include "defcalcoperations.h"

namespace my {

/*! \brief Обычный калькулятор.
 *
 * Обычный калькулятор, каким он должен быть.
 * Содержит обычные операции, вроде
 * 
 * +,-,/,*,^,sin,cos,tg,ctg и т.п.
 *
 * Схема использования:
 * \code
 * 
 * std::string s = "3 + 2*(7-3)";
 * my::DefaultCalculator calc;
 * double res = calc.calculateIn(s);
 *
 * std::cout<<"result = "<<res<<std::endl;
 *
 * \endcode
 *
 */
class DefaultCalculator : public Calculator {
public:
	//! Конструктор. Заполняет вектор операций.
	DefaultCalculator();
	//! Деструктор.
	virtual ~DefaultCalculator() {}

	//! Статическая функция для вычисления выражения. Позволяет не создавать калькулятор, т.к. сама создает калькулятор с помощью статической переменной.
	static double calculate(const std::string& s) {
		static DefaultCalculator calc;
		return calc.calculateIn(s);
	}
};

}

#endif