#ifndef IOPERAND_H
# define IOPERAND_H
# include <iostream>
#include <sstream>
# include <string.h>

enum eOperandType
{
	Int8_ID = 0,
	Int16_ID = 1,
	Int32_ID = 2,
	Float_ID = 3,
	Double_ID = 4,
	Total_ID = 5,
};

enum ePrecision
{
	Int8_P = 0,
	Int16_P = 1,
	Int32_P = 2,
	Float_P = 3,
	Double_P = 4,
	Total_Precision = 5,
};

class IOperand	{

public:
	virtual int64_t			getValueMask( void ) const  = 0;
	virtual ePrecision		getPrecisionType( void ) const = 0;
	virtual	size_t			getFractionWidth( void ) const = 0;
	virtual size_t			getIntegerWidth( void ) const = 0;
	virtual eOperandType	getType( void ) const = 0;
	virtual int32_t			getInteger( void ) const = 0;
	virtual uint32_t 		getFractional( void ) const = 0;
	
	virtual IOperand const* operator + ( IOperand const & rhs ) const = 0;
	virtual IOperand const* operator - ( IOperand const & rhs ) const = 0;
	virtual IOperand const* operator * ( IOperand const & rhs ) const = 0;
	virtual IOperand const* operator / ( IOperand const & rhs ) const = 0;
	virtual IOperand const* operator % ( IOperand const & rhs ) const = 0;

	virtual bool operator <  ( IOperand const & rhs ) const = 0;
	virtual bool operator >  ( IOperand const & rhs ) const = 0;
	virtual bool operator <= ( IOperand const & rhs ) const = 0;
	virtual bool operator >= ( IOperand const & rhs ) const = 0;
	virtual bool operator == ( IOperand const & rhs ) const = 0;
	
	virtual IOperand& operator = ( const IOperand& rhs ) = 0;

	virtual std::string	toString( void ) const = 0;
	
	virtual ~IOperand( void ) {};
};

#endif