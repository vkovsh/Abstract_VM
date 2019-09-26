#ifndef OPERANDFACTORY_H
# define OPERANDFACTORY_H
# include "operands.h"

class OperandFactory
{
public:
	static IOperand const * createOperandFromInstance( eOperandType type, std::string const & value );

private:
	typedef IOperand const * (OperandFactory::*createOp)( std::string const & value ) const;
	
private:
	static OperandFactory & getInstance( void );
	
public:
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
	const createOp _createOps[Total_ID] = {&OperandFactory::_createInt8,
		&OperandFactory::_createInt16, &OperandFactory::_createInt32,
		&OperandFactory::_createFloat, &OperandFactory::_createDouble};
	IOperand const* _createInt8( std::string const & value ) const;
	IOperand const* _createInt16( std::string const & value ) const;
	IOperand const* _createInt32( std::string const & value ) const;
	IOperand const* _createFloat( std::string const & value ) const;
	IOperand const* _createDouble( std::string const & value ) const;

private:
	OperandFactory( void );
	~OperandFactory( void );

private:
	OperandFactory(OperandFactory const& rhs) = delete;
	void operator=(OperandFactory const& rhs) = delete;
};
#endif