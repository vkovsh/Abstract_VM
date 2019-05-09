#include "Operand.hpp"
#define FLOAT_PRECISION 16

class Float : public Operand {
public:
	//copy constructor
	Float( const Float& rhs );
	
	//assignment operator
	virtual IOperand& operator = ( const IOperand& rhs );

	Float( std::string const & value );
	~Float( void );

	virtual std::string	toString( void ) const;

private:
	Float( void );
};

std::ostream & operator << ( std::ostream &out, const Float &c );