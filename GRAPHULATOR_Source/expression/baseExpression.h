

#ifndef TRYCL_BASEEXPRESSION_H
#define TRYCL_BASEEXPRESSION_H
#include <stdio.h>
#include <math.h>

///The base expression class from which all other expression types are derived
class BaseExpression
{

protected:

    ///The left hand side of the expression, either another expression, a variable or a number
    BaseExpression* mLeft;

    ///The right hand side of the expression
    BaseExpression* mRight;

public:

    ///Constructs a new expression
    BaseExpression()
    {
        mLeft = mRight = 0;
    }

    ///Constructs an expression from two sides
    BaseExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destroys an expression
    ~BaseExpression()
    {
        if(mLeft)
            delete mLeft;

        if(mRight)
            delete mRight;
    }


    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY) = 0;

    ///Prints the expression
    virtual void printExpression() = 0;
};

#endif //TRYCL_BASEEXPRESSION_H
