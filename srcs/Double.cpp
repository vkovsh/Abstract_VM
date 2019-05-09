#include "Double.hpp"

Double::Double( const Double& rhs ): Operand(Double_ID, Double_P, DOUBLE_PRECISION, rhs.toString()){}

IOperand& Double::operator = ( const IOperand& rhs )
{
	if (this == &rhs)
       return *this;
	memcpy(this, &rhs, sizeof(Double));
    return *this;
}

Double::Double( std::string const & value ): Operand(Double_ID, Double_P, DOUBLE_PRECISION, value) {}

Double::~Double( void ) {}

std::string	Double::toString( void ) const {
	std::stringstream o;
	o << getInteger() << '.' << getFractional();
	return o.str();
}