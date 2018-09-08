#include "Operand.hpp"
#include "OperandFactory.hpp"

int	main( void )
{
	const IOperand *a = OperandFactory::getInstance().createOperand(Int8_ID, "100");
	std::cout << "a = " << a->toString() << std::endl;
	const IOperand *b = OperandFactory::getInstance().createOperand(Int16_ID, "100");
	std::cout << "b = " << b->toString() << std::endl;
	const IOperand *c = OperandFactory::getInstance().createOperand(Int32_ID, "100");
	std::cout << "a = " << a->toString() << std::endl;
	const IOperand *d = OperandFactory::getInstance().createOperand(Float_ID, "100");
	const IOperand *e = OperandFactory::getInstance().createOperand(Double_ID, "100");
	return 0;
}