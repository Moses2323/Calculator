#pragma once
#ifndef ABSTROPERATIONS_30042017_GASPARYANMOSES
#define ABSTROPERATIONS_30042017_GASPARYANMOSES

#include <string>

namespace my {

class Calculator;

/*! \brief Абстрактный класс для операций.
 *
 * Абстрактный класс для операций. Может быть создан только потомками.
 *
 * Содержит в себе информацию, присущую операциям:
 * имя операции, по которому ее находят; тип операции (бинарная или унарная).
 *
 */
class Operation {
	public:
	//! Перечислимый тип для операций (унарные или бинарные и т.п.).
	enum class Type : char {
		Binary, Unity
	};

private:
	//! Тип данной операции.
	const Type type_;
	//! Имя операции, по которому ее находят.
	const std::string operName_;

protected:
	//! Ссылка на калькулятор, который используется для вычисления отдельных строк.
	Calculator& calculator_;

	//! Конструктор. Требует тип, имя операции и калькулятор, к которому можно обращаться для вычисления строк.
	Operation(const Type& type_in, const std::string& operName_in, Calculator& calculator) : type_(type_in), operName_(operName_in), calculator_(calculator) {}

public:
	//! Деструктор.
	virtual ~Operation() {}

	//! Функция возвращает тип данной операции. \details Читает приватное поле type_.
	Type type() const { return type_; }
	//! Функция возвращает имя операции. \details Читает приватное поле operName_.
	const std::string& operName() const { return operName_; }
};



/*! \brief Абстрактный класс для бинарных операций.
 *
 * Абстрактный класс для бинарных операций. Может быть
 * создан только через потомков.
 *
 * Имеет функцию operate, которая принимает 2 строки.
 * Ее необходимо реализовать в классах-потомках.
 *
 * Также есть функция, которая проверяет символ до операции.
 * По дефолту - если символ цифра или скобка, то операция бинарная.
 * Данная функция может быть изменена в классах-потомках.
 *
 */
class BinaryOperation : public Operation {
public:
	//! Конструктор. Принимает имя операции и калькулятор, к которому можно обращаться.
	BinaryOperation(const std::string& operName_in, Calculator& calc) : Operation(Type::Binary, operName_in, calc) {}

	//! Функция вычисляет результат операции по типу " lhs oper rhs ".
	virtual double operate(const std::string& lhs, const std::string& rhs) = 0;
	//! Функция проверяет символ. Если true, то символ перед операцией означает, что операция бинарная.
	virtual bool symbolBeforeIsNum(char c) const {
		if (isdigit(c) || (c == ')') || (c == ']') || (c == '}'))		//значит это бинарный оператор
			return true;
		else                //значит не бинарный оператор
			return false;
	}

};



/*! \brief Абстрактный класс для унарных операций.
 *
 * Абстрактный класс для унарных операций. Может быть
 * создан только через потомков.
 *
 * Имеет функцию operate, которая принимает одну строку.
 * Ее необходимо реализовать в классах-потомках.
 *
 */
class UnitOperation : public Operation {
public:
	//! Конструктор. Принимает имя операции и калькулятор, к которому можно обращаться.
	UnitOperation(const std::string& operName_in, Calculator& calc) : Operation(Type::Unity, operName_in, calc) {}

	//! Функция вычисляет результат операции по типу " oper s "
	virtual double operate(const std::string& s) = 0;
	//!
	virtual bool symbolBefore(char) const { return true; }
};

}

#endif // ABSTROPERATIONS_30042017_GASPARYANMOSES
