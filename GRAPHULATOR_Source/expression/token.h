

#ifndef TRYCL_TOKEN_H
#define TRYCL_TOKEN_H
#include <string>

//The type for this token, i.e whether it's an operator, numerical literal or variable
enum TokenType
{
    //Non-used type, generic
            eBase,

    //A literal number, i.e. "5" or "100.022"
            eLiteral,

    //A variable, i.e. "x" or "y"
            eVariable,

    //An operator, i.e +,/,^, tan, etc
            eOperator
};

enum OperatorType
{
    eAddition,
    eSubtraction,

    eMultiplication,

    eDivision,

    eMod,

    ePower,
    eRoot,
    eLog,
    eLn,

    eSin,
    eCos,
    eTan,

    eASin,
    eACos,
    eATan,

    eSinH,
    eCosH,
    eTanH,

    eASinH,
    eACosH,
    eATanH

};

//A class for storing a single token in an input string
class Token
{
protected:

    //The string representation of the token
    std::string mValue;

    //The type of token
    TokenType	mType;

    //The value of the token as a float, for literals
    double		mValueAsFloat;

public:

    //Constructs a token from a string representation and type
    Token(TokenType pType, std::string pRepresentation);

    //Constructs a literal token from a double value
    Token(double pValue);

    //Return the string representation of the token
    std::string	toString();

    //Returns the float value of the token, for literals
    double		getValue();

    //Returns the type of token
    TokenType	getType();
};

#endif //TRYCL_TOKEN_H
