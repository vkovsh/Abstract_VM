#include "Operand.hpp"
#define INT16_PRECISION 0

class Int16 : public Operand {

public:
	//copy constructor
	Int16( const Int16& rhs );
	
	//assignment operator
	virtual IOperand& operator = ( const IOperand& rhs );

	Int16( std::string const & value );
	~Int16( void );

	virtual std::string	toString( void ) const;

private:
	Int16( void ) = delete;
};

std::ostream & operator << ( std::ostream &out, const Int16 &c );