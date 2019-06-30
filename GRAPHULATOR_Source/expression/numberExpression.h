
#ifndef TRYCL_NUMBEREXPRESSION_H
#define TRYCL_NUMBEREXPRESSION_H
#include "baseExpression.h"

///A numeric expression that simply evaluates to it's assigned float value
class NumberExpression : public BaseExpression
{

protected:

    ///The value of this numeric expression
    float mValue;

public:

    ///Constructs a new numeric expression from a float value
    NumberExpression(float pValue)
    {
        mLeft = 0;
        mRight = 0;
        mValue = pValue;
    }

    ///Destructs this numeric expression
    ~NumberExpression()
    {

    }

    ///Returns the numeric value of this expression
    inline virtual float evaluate(float pX, float pY)
    {
        return mValue;
    }

    ///Prints this expression
    virtual void printExpression()
    {
        printf("%f",mValue);
    }
};

#endif //TRYCL_NUMBEREXPRESSION_H
