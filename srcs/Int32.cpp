#include "Int32.hpp"

Int32::Int32( const Int32& rhs ): Operand(Int32_ID, Int32_P, 32, INT32_PRECISION, rhs.toString()) {};

IOperand& Int32::operator = ( const IOperand& rhs )
{
	if (this == &rhs)
		return *this;
	memcpy(this, &rhs, sizeof(Int32));
    return *this;
};

Int32::Int32( std::string const & value ): Operand(Int32_ID, Int32_P, 32, INT32_PRECISION, value)
{
};

Int32::~Int32( void ) {};

std::string	Int32::toString( void ) const {
	std::stringstream o;
	o << getInteger();
	return o.str();
};