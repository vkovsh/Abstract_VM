#ifndef OPERAND_H
# define OPERAND_H
# include <algorithm>
# include "IOperand.hpp"
// # define MAX_PRECISION 32

class Operand : public IOperand {

private:
	void	_setInteger(int32_t i);
	void	_setFractional(uint32_t f);

	//copy constructor
	Operand( const Operand& rhs ) = delete;
	
	//assignment operator
	virtual IOperand& operator = ( const IOperand& rhs ) = 0;

public:
	virtual int64_t			getValueMask( void ) const;

	virtual ePrecision		getPrecisionType( void ) const;
	virtual	size_t			getFractionWidth( void ) const;
	virtual size_t			getIntegerWidth( void ) const;
	virtual eOperandType	getType( void ) const;
	virtual int32_t			getInteger( void ) const;
	virtual uint32_t		getFractional( void ) const;

	virtual IOperand const* operator+( IOperand const & rhs ) const;
	virtual IOperand const* operator-( IOperand const & rhs ) const;
	virtual IOperand const* operator*( IOperand const & rhs ) const;
	virtual IOperand const* operator/( IOperand const & rhs ) const;
	virtual IOperand const* operator%( IOperand const & rhs ) const;

	virtual bool operator <  ( IOperand const & rhs ) const;
	virtual bool operator >  ( IOperand const & rhs ) const;
	virtual bool operator <= ( IOperand const & rhs ) const;
	virtual bool operator >= ( IOperand const & rhs ) const;
	virtual bool operator == ( IOperand const & rhs ) const;
	
	virtual ~Operand( void );

protected:
	//default constructor
	Operand( eOperandType type,
			ePrecision precisionType,
			size_t intWidth,
			size_t fractionWidth,
			std::string value);
	
	const size_t		_intWidth;
	const size_t		_fractionWidth;
	
	const ePrecision	_precisionType;

	eOperandType		_type;
	int64_t				_value;

protected:
	static const size_t MAX_INT_WIDTH = 32;
	static const size_t MAX_FRACTION_WIDTH = 32;
	static const size_t MAX_BIT_WIDTH = MAX_INT_WIDTH + MAX_FRACTION_WIDTH;
};

#endif