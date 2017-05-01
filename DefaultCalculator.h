#pragma once
#ifndef DEFAULT_CALCULATOR_30042017_GASPARYANMOSES
#define DEFAULT_CALCULATOR_30042017_GASPARYANMOSES

#include "defcalcoperations.h"

namespace my {

/*! \brief ������� �����������.
 *
 * ������� �����������, ����� �� ������ ����.
 * �������� ������� ��������, �����
 * 
 * +,-,/,*,^,sin,cos,tg,ctg � �.�.
 *
 * ����� �������������:
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
	//! �����������. ��������� ������ ��������.
	DefaultCalculator();
	//! ����������.
	virtual ~DefaultCalculator() {}

	//! ����������� ������� ��� ���������� ���������. ��������� �� ��������� �����������, �.�. ���� ������� ����������� � ������� ����������� ����������.
	static double calculate(const std::string& s) {
		static DefaultCalculator calc;
		return calc.calculateIn(s);
	}
};

}

#endif