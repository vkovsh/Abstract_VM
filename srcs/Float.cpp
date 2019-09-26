#include "Float.hpp"

Float::Float( const Float& rhs ): Operand(Float_ID, Float_P, 32, FLOAT_PRECISION, rhs.toString()) {}

IOperand& Float::operator = ( const IOperand& rhs )
{
	if (this == &rhs)
       return *this;
	memcpy(this, &rhs, sizeof(Float));
    return *this;
}

Float::Float( std::string const & value ): Operand(Float_ID, Float_P, 32, FLOAT_PRECISION, value) {}

Float::~Float( void ) {}

std::string	Float::toString( void ) const {
	std::stringstream o;
	o << getInteger() << '.' << getFractional();
	return o.str();
}