#ifndef OPERANDFACTORY_H
# define OPERANDFACTORY_H
# include "Operand.hpp"

typedef IOperand const * (*createOp)( std::string const & value );

class OperandFactory	{

public:
	static OperandFactory & getInstance( void );
	OperandFactory(OperandFactory const& rhs) = delete;
	void operator=(OperandFactory const& rhs) = delete;
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
	const createOp _createOps[Total_ID] = {};
	OperandFactory( void );
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};

#endif