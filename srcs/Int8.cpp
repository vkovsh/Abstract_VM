#include "Int8.hpp"

Int8::Int8( const Int8& rhs ): Operand(Int8_ID, Int8_P, 8, INT8_PRECISION, rhs.toString()) {};

IOperand& Int8::operator = ( const IOperand& rhs )
{
	if (this == &rhs)
       return *this;
	memcpy(this, &rhs, sizeof(Int8));
    return *this;
};

Int8::Int8( std::string const & value ): Operand(Int8_ID, Int8_P, 8, INT8_PRECISION, value) {}

Int8::~Int8( void ) {}

std::string	Int8::toString( void ) const {
	std::stringstream o;
	o << getInteger();
	return o.str();
}