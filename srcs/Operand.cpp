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

int	& Operand::getInteger( void ) const {
	return _integer;
}

uint32_t & Operand::getFractional( void ) const {
	return _fractional;
}

IOperand const * Operand::operator+( IOperand const & rhs ) const {
	if (getPrecision() >= rhs.getPrecision()) {
		return this;	
	}
	return &rhs;
}

IOperand const * Operand::operator-( IOperand const & rhs ) const {
	if (getPrecision() >= rhs.getPrecision()) {
		return this;	
	}
	return &rhs;
}

IOperand const * Operand::operator*( IOperand const & rhs ) const {
	if (getPrecision() >= rhs.getPrecision()) {
		return this;	
	}
	return &rhs;
}

IOperand const * Operand::operator/( IOperand const & rhs ) const {
	if (getPrecision() >= rhs.getPrecision()) {
		return this;	
	}
	return &rhs;
}

IOperand const * Operand::operator%( IOperand const & rhs ) const {
	if (getPrecision() >= rhs.getPrecision()) {
		return this;	
	}
	return &rhs;
}

bool Operand::operator<( IOperand const & rhs ) const {
	int i1, i2;
	uint32_t f1, f2;
	
	i1 = getInteger();
	i2 = rhs.getInteger();
	f1 = getFractional();
	f2 = getFractional();
	if (i1 == i2 && f1 == f2) {
		return getType() < rhs.getType();
	}
	else if (i1 == i2) {
		return (i1 < 0 && i2 < 0) ? f1 > f2 : f1 < f2;
	}
	return i1 < i2;
}

bool Operand::operator>( IOperand const & rhs ) const {
	return !(this < rhs);
}

bool Operand::operator<=( IOperand const & rhs ) const {
	return this < rhs || this == rhs;
}

bool Operand::operator>=( IOperand const & rhs ) const {
	return this > rhs || this == rhs;
}

bool Operand::operator==( IOperand const & rhs ) const {
	return getInteger() == rhs.getInteger() && getFractional() == rhs.getFractional();
}