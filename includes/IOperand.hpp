#ifndef IOPERAND_H
# define IOPERAND_H
# include <iostream>
#include <sstream>
# include <string.h>

enum eOperandType { Undefined_ID=-1, Int8_ID, Int16_ID, Int32_ID, Float_ID, Double_ID, Total_ID };

enum ePrecision { Undefined_P=-1, Int8_P, Int16_P, Int32_P, Float_P, Double_P, Total_Precision };

class IOperand	{

public:
	virtual int64_t			getValueMask( void ) const  = 0;
	virtual ePrecision		getPrecisionType( void ) const = 0;
	virtual	size_t			getPrecisionValue( void ) const = 0;
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