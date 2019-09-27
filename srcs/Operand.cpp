
#include "OperandFactory.hpp"

void	Operand::_setInteger(int32_t i)
{
	//erase old integer value 
	{
		int32_t currentIntVal = _value >> Operand::MAX_FRACTION_WIDTH;
		_value ^= static_cast<int64_t>(currentIntVal) << Operand::MAX_FRACTION_WIDTH;
	}
	
	//set new integer value
	{
		int32_t cuttedIntValue = i << (Operand::MAX_INT_WIDTH - _intWidth);
		cuttedIntValue >>= Operand::MAX_INT_WIDTH - _intWidth; 
		_value |= static_cast<int64_t>(cuttedIntValue) << Operand::MAX_INT_WIDTH;
	}
}

void	Operand::_setFractional(uint32_t f)
{
	//erase old fractional value 
	{
		uint32_t currentFractionalVal = (_value << MAX_INT_WIDTH) >> MAX_INT_WIDTH;
		_value ^= currentFractionalVal;
	}

	{
		int32_t cuttedFractionValue = f << (MAX_FRACTION_WIDTH - _fractionWidth);
		cuttedFractionValue >>= MAX_FRACTION_WIDTH - _fractionWidth; 
		f = static_cast<uint32_t>(cuttedFractionValue);
	}

	uint8_t *valArr = (uint8_t *)(&f);
	if (f)
	{
		while (valArr[3] == 0)
		{
			f <<= 8;
		}
	}
	_value |= f;
}

Operand::Operand( eOperandType type,
					ePrecision precisionType,
					size_t intWidth,
					size_t fractionWidth,
					std::string value): _type(type),
										_precisionType(precisionType),
										_intWidth(intWidth),
										_fractionWidth(fractionWidth)
{
	std::stringstream ss(value);
	std::string intPart;
	std::getline(ss, intPart, '.');
	std::string fractionPart;
	std::getline(ss, fractionPart);

	ss.str("");
	ss.clear();

	int32_t i = std::stoi(intPart);
	printf("i = %i\n", i);
	if (fractionPart == "")
		fractionPart = "0";
	uint32_t f = static_cast<uint32_t>(std::stoi(fractionPart));
	for (auto it = fractionPart.begin(); it != fractionPart.end(); ++i)
	{
		if (*it != '0')
			break ;
		f /= 10; 
	}
	_value = 0;
	_setInteger(i);
	_setFractional(f);
};

ePrecision		Operand::getPrecisionType( void ) const {
	return _precisionType;
}

size_t			Operand::getFractionWidth( void ) const {
	return _fractionWidth;
}

size_t			Operand::getIntegerWidth( void ) const
{
	return _intWidth;
}

eOperandType	Operand::getType( void ) const {
	return _type;
}

int64_t			Operand::getValueMask( void ) const {
	return _value;
}


int32_t Operand::getInteger( void ) const
{
	return _value >> MAX_FRACTION_WIDTH;
}

uint32_t Operand::getFractional( void ) const
{
	uint32_t fractional = static_cast<uint32_t>(_value);
	fractional >>= MAX_FRACTION_WIDTH - _fractionWidth;
	return (_value & (static_cast<uint64_t>(1) << 63)) ? (~fractional + 1) : fractional;
}

IOperand const * Operand::operator+( IOperand const & rhs ) const {
	eOperandType targetType;
	size_t targetPrecisionValue;

	if (getPrecisionType() > rhs.getPrecisionType()) {
		targetType = getType();
		targetPrecisionValue = getFractionWidth();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getFractionWidth();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value + rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_FRACTION_WIDTH;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_INT_WIDTH);
	if (sum < 0)
		fractional = ~fractional + 1;

	ss << integer << "." << fractional; 
	return OperandFactory::createOperandFromInstance(targetType, ss.str());
}

IOperand const * Operand::operator-( IOperand const & rhs ) const {
	eOperandType targetType;
	size_t targetPrecisionValue;

	if (getPrecisionType() > rhs.getPrecisionType()) {
		targetType = getType();
		targetPrecisionValue = getFractionWidth();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getFractionWidth();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value - rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_FRACTION_WIDTH;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_INT_WIDTH);
	if (sum < 0)
		fractional = ~fractional + 1;

	ss << integer << "." << fractional; 
	return OperandFactory::createOperandFromInstance(targetType, ss.str());
}

IOperand const * Operand::operator*( IOperand const & rhs ) const {
	eOperandType targetType;
	size_t targetPrecisionValue;

	if (getPrecisionType() > rhs.getPrecisionType()) {
		targetType = getType();
		targetPrecisionValue = getFractionWidth();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getFractional();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	//int64_t sum = (_value >> 10)* rhs.getValueMask();
	int64_t dd  = rhs.getValueMask();
	int64_t d1 = _value;
	int reg = 0;
	char a;
	if (dd && d1) {
		while (!(a = dd) && !(a = d1)) {
			dd >>= 8;
			d1 >>= 8;
			reg += 8;
		}
	}

	std::cout << reg << std::endl;
	std::cout << d1 << "  " << dd << std::endl;
	uint64_t sum = static_cast<int64_t>(d1 * dd) << reg;
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_FRACTION_WIDTH;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_FRACTION_WIDTH);
	if (sum < 0)
		fractional = ~fractional + 1;

	ss << integer << "." << fractional; 
	return OperandFactory::createOperandFromInstance(targetType, ss.str());
}

IOperand const * Operand::operator/( IOperand const & rhs ) const {
	eOperandType targetType;
	size_t targetPrecisionValue;

	if (getPrecisionType() > rhs.getPrecisionType()) {
		targetType = getType();
		targetPrecisionValue = getFractionWidth();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getFractionWidth();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value / rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_FRACTION_WIDTH;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_INT_WIDTH);
	if (sum < 0)
		fractional = ~fractional + 1;

	ss << integer << "." << fractional; 
	return OperandFactory::createOperandFromInstance(targetType, ss.str());
}

IOperand const * Operand::operator%( IOperand const & rhs ) const {
	eOperandType targetType;
	size_t targetPrecisionValue;

	if (getPrecisionType() > rhs.getPrecisionType()) {
		targetType = getType();
		targetPrecisionValue = getFractionWidth();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getFractionWidth();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value % rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_FRACTION_WIDTH;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_INT_WIDTH);
	if (sum < 0)
		fractional = ~fractional + 1;

	ss << integer << "." << fractional; 
	return OperandFactory::createOperandFromInstance(targetType, ss.str());
}

bool Operand::operator<( IOperand const & rhs ) const {
	return _value < rhs.getValueMask();
}

bool Operand::operator>( IOperand const & rhs ) const {
	return !(*this < rhs);
}

bool Operand::operator<=( IOperand const & rhs ) const {
	return *this < rhs || *this == rhs;
}

bool Operand::operator>=( IOperand const & rhs ) const {
	return *this > rhs || *this == rhs;
}

bool Operand::operator==( IOperand const & rhs ) const {
	return _value == getValueMask();
}

Operand::~Operand( void ) {}