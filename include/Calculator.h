#pragma once
#ifndef CALCULATOR_30042017_GASPARYANMOSES
#define CALCULATOR_30042017_GASPARYANMOSES

#include <vector>
#include <memory>
#include <iomanip>
#include "abstroperations.h"
#include "ForMistakes.h"

namespace my {

/*! \brief ����������� ����� ��� ������������.
 *
 * ����������� ����� ��� ������������.
 *
 * ����� ��� ����������� ������, ����� ���������, ��
 * �� ��������� ������ ��������.
 * � ������� �������� ��� �������� ����������� �� ����������:
 * 0 - ����� ������� ���������.
 *
 * ������-������� ������ ���� ��������� ������ ��������.
 * 
 */
class Calculator {
	public:
	//! ������������ ����� ��� ���� ������������.
	enum class OperationsType : char {
		DefaultCalculator, BooleanCalculator
	};
private:
	//! ��� ������������.
	const OperationsType operationsType_;

protected:
	//! ��������������� ������ ��� ����� ������. ������������ � ����� �������� ��� �������� �����������-����������� ������.
	std::vector<char> scobStack_;
	//! ������ ��������. ��� �������� ����������� �� ����������. 0 - ����� ������� ���������.
	std::vector<std::unique_ptr<Operation>> operations_;
	
	//! ������� ������� ��������� ������ �� ����� ������, ���� ������� ������ - ��� closeBracket. ����� - �� ������ ������. ���� ������� ������ - closeBracket, �� � ����� �� openBracket, �� �������������� ����������.
	void checkCloseSymbolInStack(char toCheck, char openBracket, char closeBracket);
	//! ������� ���������� ������ � ������ ��� ����������� ������. ���� ������� ������ �� �������� ����������� �������, �� ������ ���������� beg.
	int scob(const std::string& s, size_t beg = 0);
	//! ������� ���������� ������ � ������ ��� ����������� ������. ���� ������� ������ �� �������� ����������� �������, �� ������ ���������� beg.
	int rscob(const std::string& s, int beg);

	//! ������� ���� ��������� whatFind � ������ s, ��������� ������. ����� ���������� � ������� beg � ���� � ����� ������ � ������. ���������� ��������� ������ ���������. ���� ���� ����� ������ ������, �� ������������ ������ ������ ������.
	size_t rfindPassBrackets(const std::string& s, const std::string& whatFind, size_t beg = std::string::npos);

	//! ������� ���������� ������ vs � ������ s ��� ��������, ���� ������� ���� ���� ������. ���������� true, ���� ���� ���� ������ ������.
	bool doWithoutSpaces(const std::string& s, std::string& vs) const;

	//! �����������. ��������� ��� ������������.
	explicit Calculator(OperationsType t) : operationsType_(t) {
		scobStack_.reserve(10);
		operations_.reserve(100);
	}

public:
	//! ����������.
	virtual ~Calculator() {}

	//! ������� ���������� ��� ������������. \details ������ ��������� ���� operationsType_.
	OperationsType getOperationsType() const { return operationsType_; }

	//! ������� ��������� �������� �������� ���������.
	double calculateIn(const std::string& s);

};


}

#endif