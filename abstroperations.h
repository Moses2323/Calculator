#pragma once
#ifndef ABSTROPERATIONS_30042017_GASPARYANMOSES
#define ABSTROPERATIONS_30042017_GASPARYANMOSES

#include <string>

namespace my {

class Calculator;

/*! \brief ����������� ����� ��� ��������.
 *
 * ����������� ����� ��� ��������. ����� ���� ������ ������ ���������.
 *
 * �������� � ���� ����������, �������� ���������:
 * ��� ��������, �� �������� �� �������; ��� �������� (�������� ��� �������).
 *
 */
class Operation {
	public:
	//! ������������ ��� ��� �������� (������� ��� �������� � �.�.).
	enum class Type : char {
		Binary, Unity
	};

private:
	//! ��� ������ ��������.
	const Type type_;
	//! ��� ��������, �� �������� �� �������.
	const std::string operName_;

protected:
	//! ������ �� �����������, ������� ������������ ��� ���������� ��������� �����.
	Calculator& calculator_;

	//! �����������. ������� ���, ��� �������� � �����������, � �������� ����� ���������� ��� ���������� �����.
	Operation(const Type& type_in, const std::string& operName_in, Calculator& calculator) : type_(type_in), operName_(operName_in), calculator_(calculator) {}

public:
	//! ����������.
	virtual ~Operation() {}

	//! ������� ���������� ��� ������ ��������. \details ������ ��������� ���� type_.
	const Type type() const { return type_; }
	//! ������� ���������� ��� ��������. \details ������ ��������� ���� operName_.
	const std::string& operName() const { return operName_; }
};



/*! \brief ����������� ����� ��� �������� ��������.
 *
 * ����������� ����� ��� �������� ��������. ����� ����
 * ������ ������ ����� ��������.
 *
 *
 *
 */
class BinaryOperation : public Operation {
public:
	BinaryOperation(const std::string& operName_in, Calculator& calc) : Operation(Type::Binary, operName_in, calc) {}

	virtual double operate(const std::string& lhs, const std::string& rhs) = 0;
	virtual bool symbolBeforeIsNum(char c) const {
		if (isdigit(c) || (c == ')') || (c == ']') || (c == '}'))		//������ ��� �������� ��������
			return true;
		else                //������ �� �������� ��������
			return false;
	}
};

class UnitOperation : public Operation {
public:
	UnitOperation(const std::string& operName_in, Calculator& calc) : Operation(Type::Unity, operName_in, calc) {}

	virtual double operate(const std::string& s) = 0;
};

}

#endif // ABSTROPERATIONS_30042017_GASPARYANMOSES