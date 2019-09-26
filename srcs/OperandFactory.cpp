#include "OperandFactory.hpp"


IOperand const * OperandFactory::createOperandFromInstance( eOperandType type, std::string const & value )
{
	return OperandFactory::getInstance().createOperand(type, value);
}

OperandFactory & OperandFactory::getInstance( void ) {
	static OperandFactory instance;
	std::cout << "Factory ready!" << std::endl;
	return instance;
}

OperandFactory::OperandFactory( void ) {
	std::cout << "Factory alive!" << std::endl;
};

OperandFactory::~OperandFactory( void ) {
	std::cout << "Factory destroyed!" << std::endl;
};

IOperand const * OperandFactory::_createInt8( std::string const & value ) const {
	return new Int8(value);
}

IOperand const * OperandFactory::_createInt16( std::string const & value ) const {
	return new Int16(value);
}

IOperand const * OperandFactory::_createInt32( std::string const & value ) const {
	return new Int32(value);
}

IOperand const * OperandFactory::_createFloat( std::string const & value ) const {
	return new Float(value);
}

IOperand const * OperandFactory::_createDouble( std::string const & value ) const {
	return new Double(value);
}

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const {
	return (this->*(_createOps[type]))(value);
}