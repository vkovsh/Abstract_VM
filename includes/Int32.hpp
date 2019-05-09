#include "Operand.hpp"
#define INT32_PRECISION 0

class Int32 : public Operand {
public:
	//copy constructor
	Int32( const Int32& rhs );
	
	//assignment operator
	virtual IOperand& operator = ( const IOperand& rhs );
	
	Int32( std::string const & value );
	~Int32( void );

	virtual std::string	toString( void ) const;
	
private:
	Int32( void ) = delete;
};

std::ostream & operator << ( std::ostream &out, const Int32 &c );