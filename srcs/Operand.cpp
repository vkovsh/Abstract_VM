#include "Operand.hpp"

Int8::Int8( void ): Operand(Int8_ID, Int8_P) {
	_fractional = 0;
};
Int8::Int8( std::string const & value ): Int8() {
	_str = value;
	_integer = std::stoi(value);
};
Int8::~Int8( void ) {};

Int16::Int16( void ): Operand(Int16_ID, Int16_P) {
	_fractional = 0;
};
Int16::Int16( std::string const & value ): Int16() {
	_str = value;
	_integer = std::stoi(value);
};
Int16::~Int16( void ) {};

Int32::Int32( void ): Operand(Int32_ID, Int32_P) {
	_fractional = 0;
};
Int32::Int32( std::string const & value ): Int32() {
	_str = value;
	_integer = std::stoi(value);
};
Int32::~Int32( void ) {};

Float::Float( void ): Operand(Float_ID, Float_P) {};
Float::Float( std::string const & value ): Float() {
	size_t sz = 0;

	_str = value;
	_integer = std::stoi(value, &sz);
	_fractional = (sz != value.size()) ? std::stoi(value.substr(sz)) : 0;
};
Float::~Float( void ) {};

Double::Double( void ): Operand(Double_ID, Double_P) {};
Double::Double( std::string const & value ): Double() {
	size_t sz = 0;

	_str = value;
	_integer = std::stoi(value, &sz);
	_fractional = (sz != value.size()) ? std::stoi(value.substr(sz)) : 0;

};
Double::~Double( void ) {};

Operand::Operand( eOperandType type, ePrecision precision): _type(type), _precision(precision) {
	std::cout << "Operand type = " << type << std::endl;
};

Operand::~Operand( void ) {};

ePrecision		Operand::getPrecision( void ) const {
	return _precision;
}

eOperandType	Operand::getType( void ) const {
	return _type;
}

std::string const & Operand::toString( void ) const {
	return _str;
}

IOperand const * Operand::operator+( IOperand const & rhs ) const {
	return NULL;
}

IOperand const * Operand::operator-( IOperand const & rhs ) const {
	return NULL;
}

IOperand const * Operand::operator*( IOperand const & rhs ) const {
	return NULL;
}

IOperand const * Operand::operator/( IOperand const & rhs ) const {
	return NULL;
}

IOperand const * Operand::operator%( IOperand const & rhs ) const {
	return NULL;
}

bool Operand::operator<( IOperand const & rhs ) const {
	return true;
}

bool Operand::operator>( IOperand const & rhs ) const {
	return true;
}

bool Operand::operator<=( IOperand const & rhs ) const {
	return true;
}

bool Operand::operator>=( IOperand const & rhs ) const {
	return true;
}

bool Operand::operator==( IOperand const & rhs ) const {
	return true;
}