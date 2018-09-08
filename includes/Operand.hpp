#ifndef OPERAND_H
# define OPERAND_H

#include "IOperand.hpp"

typedef unsigned int uint32_t;

class Operand : public IOperand {

public:
	Operand( eOperandType type=Undefined_ID, ePrecision precision=Undefined_P );
	ePrecision		getPrecision( void ) const;
	eOperandType	getType( void ) const;
	int	& getInteger( void ) const;
	uint32_t & getFractional( void ) const;
	
	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;

	bool operator<( IOperand const & rhs ) const;
	bool operator>( IOperand const & rhs ) const;
	bool operator<=( IOperand const & rhs ) const;
	bool operator>=( IOperand const & rhs ) const;
	bool operator==( IOperand const & rhs ) const;

	std::string const & toString( void ) const;
	
	~Operand( void );

protected:
	ePrecision		_precision;
	eOperandType	_type;
	int				_integer;
	uint32_t		_fractional;
	std::string		_str;

};

class Int8 : public Operand	{
public:
	Int8( void );
	Int8( std::string const & value );
	~Int8( void );
};

class Int16 : public Operand {
public:
	Int16( void );
	Int16( std::string const & value );
	~Int16( void );
};

class Int32 : public Operand {
public:
	Int32( void );
	Int32( std::string const & value );
	~Int32( void );
};

class Float : public Operand {
public:
	Float( void );
	Float( std::string const & value );
	~Float( void );
};

class Double : public Operand {
public:
	Double( void );
	Double( std::string const & value );
	~Double( void );
};

#endif