#include "Operand.hpp"
#define INT8_PRECISION 0

class Int8 : public Operand	{

public:
	//copy constructor
	Int8( const Int8& rhs );
	
	//assignment operator
	virtual IOperand& operator = ( const IOperand& rhs );

	Int8( std::string const & value );
	~Int8( void );

	virtual std::string	toString( void ) const;

private:
	Int8( void ) = delete;

};