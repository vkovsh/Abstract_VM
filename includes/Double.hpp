#include "Operand.hpp"
#define DOUBLE_PRECISION 32

class Double : public Operand {

public:
	//copy constructor
	Double( const Double& rhs );
	
	//assignment operator
	virtual IOperand& operator = ( const IOperand& rhs );
	
	Double( std::string const & value );
	virtual ~Double( void );
	virtual std::string	toString( void ) const;

private:
	Double( void ) = delete;
};

std::ostream & operator << ( std::ostream &out, const Double &c );