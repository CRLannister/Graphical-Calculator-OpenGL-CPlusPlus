
#ifndef TRYCL_LOGEXPRESSION_H
#define TRYCL_LOGEXPRESSION_H
#include "baseExpression.h"
#include <math.h>

///A log expression that computes log(left), with base 10
class LogExpression : public BaseExpression
{

public:

    ///Constructs a power expression
    LogExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destructs the expression
    ~LogExpression()
    {
        delete mLeft;
        delete mRight;
    }

    ///Evaluates this expression, i.e compute mLeft^mRight
    inline virtual float evaluate(float pX, float pY)
    {
        return log10(mLeft->evaluate(pX,pY));
    }

    ///Prints the expression
    virtual void printExpression()
    {
        printf("log(");
        mLeft->printExpression();
        printf(")");
    }
};

#endif //TRYCL_LOGEXPRESSION_H
