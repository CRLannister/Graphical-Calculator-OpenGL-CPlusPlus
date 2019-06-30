
#ifndef TRYCL_MULTIPLYEXPRESSION_H
#define TRYCL_MULTIPLYEXPRESSION_H
#include "baseExpression.h"

///A multiplication expression class
class MultiplyExpression : public BaseExpression
{

public:

    ///Constructs a new multiplication expression from a left and right expression
    MultiplyExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destructs this multiplication expression
    ~MultiplyExpression()
    {
        delete mLeft;
        delete mRight;
    }

    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY)
    {
        return mLeft->evaluate(pX, pY) * mRight->evaluate(pX, pY);
    }

    ///Prints this expression
    virtual void printExpression()
    {
        printf("(");
        mLeft->printExpression();
        printf(" * ");
        mRight->printExpression();
        printf(")");
    }
};

#endif //TRYCL_MULTIPLYEXPRESSION_H
