#ifndef TRYCL_MODEXPRESSION_H
#define TRYCL_MODEXPRESSION_H
#include "baseExpression.h"

///Modulo operation in the expression tree. Computes left % right.
class ModExpression : public BaseExpression
{

public:

    ///Constructs an addition expression from a left and right expression
    ModExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destroys this expression
    ~ModExpression()
    {
        delete mLeft;
        delete mRight;
    }

    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY)
    {
        return fmod(mLeft->evaluate(pX, pY),mRight->evaluate(pX, pY));
    }

    ///Prints the expression to the console
    virtual void printExpression()
    {
        printf("(");
        mLeft->printExpression();
        printf(" %% ");
        mRight->printExpression();
        printf(")");
    }

};
#endif //TRYCL_MODEXPRESSION_H
