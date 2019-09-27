#include "OperandFactory.hpp"

int	main( void )
{
	// const IOperand *a = OperandFactory::createOperandFromInstance(Int8_ID, "3");
	// std::cout << "a = " << a->toString() << std::endl;
	// const IOperand *b = OperandFactory::createOperandFromInstance(Int8_ID, "65282");
	// std::cout << "b = " << b->toString() << std::endl;
	// const IOperand *c = *a * *b;
	// std::cout << "c = " << c->toString() << std::endl;
	const IOperand *f = OperandFactory::createOperandFromInstance(Float_ID, "3.95");
	std::cout << "f = " << f->toString() << std::endl;
	//const IOperand *c = OperandFactory::getInstance().createOperand(Int32_ID, "100");
	//std::cout << "a = " << a->toString() << std::endl;
	//const IOperand *d = OperandFactory::getInstance().createOperand(Float_ID, "100");
	//const IOperand *e = OperandFactory::getInstance().createOperand(Double_ID, "100");
	// delete a;
	// delete b;
	// delete c;
	delete f;
	//delete d;
	//delete e;
	//return 0;
}