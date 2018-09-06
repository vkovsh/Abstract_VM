#include "OperandFactory.hpp"

OperandFactory & OperandFactory::getInstance( void ) {
	static OperandFactory instance;
	return instance;
}

OperandFactory::OperandFactory( void ) {};

IOperand const * OperandFactory::createInt8( std::string const & value ) const {
	return new Int8(value);
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const {
	return new Int16(value);
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const {
	return new Int32(value);
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const {
	return new Float(value);
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const {
	return new Double(value);
}