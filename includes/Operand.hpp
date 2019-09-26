#ifndef OPERAND_H
# define OPERAND_H
# include "IOperand.hpp"
# define BIT_COUNT 64
# define MAX_PRECISION 32

class Operand : public IOperand {

private:
	void	_setInteger(int32_t i, size_t widthValue);
	void	_setFractional(uint32_t f, size_t precisionValue);

	//copy constructor
	Operand( const Operand& rhs ) = delete;
	
	//assignment operator
	virtual IOperand& operator = ( const IOperand& rhs ) = 0;

public:
	virtual int64_t			getValueMask( void ) const;

	virtual ePrecision		getPrecisionType( void ) const;
	virtual	size_t			getPrecisionValue( void ) const;
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
		size_t widthValue,
		size_t precisionValue,
		std::string value );
	
	const size_t		_precisionValue;
	const ePrecision	_precisionType;

	eOperandType		_type;
	int64_t				_value;
};

#endif