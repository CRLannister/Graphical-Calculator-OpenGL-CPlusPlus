

#ifndef TRYCL_ADDEXPRESSION_H
#define TRYCL_ADDEXPRESSION_H
#include "baseExpression.h"

///Addition operation in the expression tree. Adds two expressions together.
class AddExpression : public BaseExpression
{

public:

    ///Constructs an addition expression from a left and right expression
    AddExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destroys this expression
    ~AddExpression()
    {
        delete mLeft;
        delete mRight;
    }

    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY)
    {
        return mLeft->evaluate(pX, pY) + mRight->evaluate(pX, pY);
    }

    ///Prints the expression to the console
    virtual void printExpression()
    {
        printf("(");
        mLeft->printExpression();
        printf(" + ");
        mRight->printExpression();
        printf(")");
    }

};
#endif //TRYCL_ADDEXPRESSION_H
