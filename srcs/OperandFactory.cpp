#include "OperandFactory.hpp"

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

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const {
	return (this->*(_createOps[type]))(value);
}