
#ifndef TRYCL_LNEXPRESSION_H
#define TRYCL_LNEXPRESSION_H
#include "baseExpression.h"
#include <math.h>

///A natural log expression that computes log(left), with base e
class LnExpression : public BaseExpression
{

public:

    ///Constructs a power expression
    LnExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destructs the expression
    ~LnExpression()
    {
        delete mLeft;
        delete mRight;
    }

    ///Evaluates this expression, i.e compute mLeft^mRight
    inline virtual float evaluate(float pX, float pY)
    {
        return log(mLeft->evaluate(pX,pY));
    }

    ///Prints the expression
    virtual void printExpression()
    {
        printf("ln(");
        mLeft->printExpression();
        printf(")");
    }
};

#endif //TRYCL_LNEXPRESSION_H
