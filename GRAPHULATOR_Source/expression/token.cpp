
#include "token.h"

//Constructs a token from a string representation and type
Token::Token(TokenType pType, std::string pRepresentation)
{
    mType = pType;
    mValue = pRepresentation;
}

//Constructs a literal token from a double value
Token::Token(double pValue)
{
    mValueAsFloat = pValue;
    mType = eLiteral;
}

//Returns the float value of the token, for literals
double Token::getValue()
{
    return mValueAsFloat;
}

//Returns the type of token
TokenType Token::getType()
{
    return mType;
}

//Return the string representation of the token
std::string Token::toString()
{
    return mValue;
}
