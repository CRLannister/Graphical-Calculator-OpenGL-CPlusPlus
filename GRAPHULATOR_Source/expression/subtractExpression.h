

#ifndef TRYCL_SUBTRACTEXPRESSION_H
#define TRYCL_SUBTRACTEXPRESSION_H
#include "baseExpression.h"

//A subtraction operation
class SubtractExpression : public BaseExpression
{

public:

    ///Creates a new subtraction expression
    SubtractExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destroys the expression
    ~SubtractExpression()
    {
        delete mLeft;
        delete mRight;
    }

    ///Evaluates the expression at pX, pY
    inline virtual float evaluate(float pX, float pY)
    {
        return mLeft->evaluate(pX, pY) - mRight->evaluate(pX, pY);
    }

    ///Prints the expression
    virtual void printExpression()
    {
        printf("(");
        mLeft->printExpression();
        printf(" - ");
        mRight->printExpression();
        printf(")");
    }

};

#endif //TRYCL_SUBTRACTEXPRESSION_H
