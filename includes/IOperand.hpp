#ifndef IOPERAND_H
# define IOPERAND_H
# include <iostream>
# include <string>

enum eOperandType { Undefined_ID=-1, Int8_ID, Int16_ID, Int32_ID, Float_ID, Double_ID, Total_ID };
enum ePrecision { Undefined_P=-1, Int8_P=0, Int16_P, Int32_P, Float_P, Double_P, Total_Precision };

class IOperand	{

public:
	virtual ePrecision		getPrecision( void ) const = 0;
	virtual eOperandType	getType( void ) const = 0;
	
	virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0;

	virtual bool operator<( IOperand const & rhs ) const = 0;
	virtual bool operator>( IOperand const & rhs ) const = 0;
	virtual bool operator<=( IOperand const & rhs ) const = 0;
	virtual bool operator>=( IOperand const & rhs ) const = 0;
	virtual bool operator==( IOperand const & rhs ) const = 0;

	virtual std::string const & toString( void ) const = 0;
	
	virtual ~IOperand( void ) {}

};

#endif