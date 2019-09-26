
#include "OperandFactory.hpp"

void	Operand::_setInteger(int32_t i, size_t widthValue)
{
	{
		int32_t currentIntVal = _value >> MAX_PRECISION;
		_value ^= static_cast<int64_t>(currentIntVal) << MAX_PRECISION;
	}
	printf("before = 0x%lx\n", _value);
	
	{
		int32_t cuttedIntValue = i << (MAX_PRECISION - widthValue);
		cuttedIntValue >>= MAX_PRECISION - widthValue; 
		_value |= static_cast<int64_t>(cuttedIntValue) << MAX_PRECISION;
	}
	printf("after = 0x%lx\n", _value);
}

void	Operand::_setFractional(uint32_t f, size_t precisionValue)
{
	uint32_t currentFractionalVal = _value;
	_value ^= currentFractionalVal;
	
	{
		int32_t cuttedFractionValue = f << (MAX_PRECISION - precisionValue);
		cuttedFractionValue >>= MAX_PRECISION - precisionValue; 
		f = static_cast<uint32_t>(cuttedFractionValue);
	}

	uint8_t *valArr = (uint8_t *)(&f);
	if (f) {
		while (valArr[3] == 0) {
			f <<= 8;
		}
	}
	_value |= f;
}

Operand::Operand( eOperandType type,
					ePrecision precisionType,
					size_t widthValue,
					size_t precisionValue,
					std::string value): _type(type),
										_precisionType(precisionType),
										_precisionValue(precisionValue)
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
	if (fractionPart == "") fractionPart = "0";
	uint32_t f = static_cast<uint32_t>(std::stoi(fractionPart));
	_value = 0;
	// printf("0x%lx\n", _value);
	_setInteger(i, widthValue);
	// printf("0x%lx\n", _value);
	_setFractional(f, precisionValue);
	// printf("0x%lx\n", _value);
};

ePrecision		Operand::getPrecisionType( void ) const {
	return _precisionType;
}

size_t			Operand::getPrecisionValue( void ) const {
	return _precisionValue;
}

eOperandType	Operand::getType( void ) const {
	return _type;
}

int64_t			Operand::getValueMask( void ) const {
	return _value;
}


int32_t Operand::getInteger( void ) const {
	return _value >> MAX_PRECISION;
}

uint32_t Operand::getFractional( void ) const {
	uint32_t fractional = _value ^ ((_value >> _precisionValue) << _precisionValue);
	if (_value >= 0) {
		return fractional;
	}
	return (~fractional + 1);
}

IOperand const * Operand::operator+( IOperand const & rhs ) const {
	eOperandType targetType;
	size_t targetPrecisionValue;

	if (getPrecisionType() > rhs.getPrecisionType()) {
		targetType = getType();
		targetPrecisionValue = getPrecisionValue();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getPrecisionValue();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value + rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_PRECISION;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_PRECISION);
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
		targetPrecisionValue = getPrecisionValue();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getPrecisionValue();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value - rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_PRECISION;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_PRECISION);
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
		targetPrecisionValue = getPrecisionValue();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getPrecisionValue();
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
	int32_t integer = sum >> MAX_PRECISION;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_PRECISION);
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
		targetPrecisionValue = getPrecisionValue();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getPrecisionValue();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value / rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_PRECISION;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_PRECISION);
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
		targetPrecisionValue = getPrecisionValue();
	}
	else {
		targetType = rhs.getType();
		targetPrecisionValue = rhs.getPrecisionValue();
	}
	
	std::stringstream ss;

	printf("{0x%lx}\n", _value);
	printf("{0x%lx}\n", rhs.getValueMask());
	int64_t sum = _value % rhs.getValueMask();
	printf("{0x%lx}\n", sum);
	int32_t integer = sum >> MAX_PRECISION;
	uint32_t fractional = sum ^ (static_cast<int64_t>(integer) << MAX_PRECISION);
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