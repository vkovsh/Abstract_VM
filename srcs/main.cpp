#include "OperandFactory.hpp"

int	main( void )
{
	std::cout << sizeof(IOperand) << std::endl;
	std::cout << sizeof(Operand) << std::endl;
	const IOperand *a = OperandFactory::getInstance().createOperand(Int8_ID, "3");
	std::cout << "a = " << a->toString() << std::endl;
	const IOperand *b = OperandFactory::getInstance().createOperand(Int8_ID, "65280");
	std::cout << "b = " << b->toString() << std::endl;
	const IOperand *c = *a * *b;
	std::cout << "c = " << c->toString() << std::endl;
	
	//const IOperand *c = OperandFactory::getInstance().createOperand(Int32_ID, "100");
	//std::cout << "a = " << a->toString() << std::endl;
	//const IOperand *d = OperandFactory::getInstance().createOperand(Float_ID, "100");
	//const IOperand *e = OperandFactory::getInstance().createOperand(Double_ID, "100");
	delete a;
	delete b;
	delete c;
	//delete d;
	//delete e;
	//return 0;
}