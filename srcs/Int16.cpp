#include "Int16.hpp"

Int16::Int16( const Int16& rhs ): Operand(Int16_ID, Int16_P, 16, INT16_PRECISION, rhs.toString()) {};

IOperand& Int16::operator = ( const IOperand& rhs )
{
	if (this == &rhs)
       return *this;
	memcpy(this, &rhs, sizeof(Int16));
    return *this;
};

Int16::Int16( std::string const & value ): Operand(Int16_ID, Int16_P, 16, INT16_PRECISION, value) {};

Int16::~Int16( void ) {};

std::string	Int16::toString( void ) const {
	std::stringstream o;
	o << getInteger();
	return o.str();
};