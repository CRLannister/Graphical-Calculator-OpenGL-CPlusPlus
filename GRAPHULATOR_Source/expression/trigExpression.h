
#ifndef TRYCL_TRIGEXPRESSION_H
#define TRYCL_TRIGEXPRESSION_H
#include "token.h"
#include "baseExpression.h"


///A trig expression class
class TrigExpression : public BaseExpression
{

protected:

    OperatorType mTrigFunction;


public:

    ///Constructs a new multiplication expression from a left and right expression
    TrigExpression(BaseExpression* pLeft, OperatorType pTrigFunction)
    {
        mLeft = pLeft;
        mTrigFunction = pTrigFunction;
    }

    ///Destructs this multiplication expression
    ~TrigExpression()
    {
        delete mLeft;
    }

    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY)
    {
        float lLeft = mLeft->evaluate(pX,pY);
        float lVal = 0.0f;

        switch(mTrigFunction)
        {
            case eSin:
                lVal = sin(lLeft);
                break;

            case eCos:
                lVal = cos(lLeft);
                break;

            case eTan:
                lVal = tan(lLeft);
                break;


            case eASin:
                lVal = asin(lLeft);
                break;

            case eACos:
                lVal = acos(lLeft);
                break;

            case eATan:
                lVal = atan(lLeft);
                break;

            default:
                break;

        }

        return lVal;
    }

    ///Prints this expression
    virtual void printExpression()
    {
        char* lStrRep;

        switch(mTrigFunction)
        {
            case eSin:
                lStrRep = "sin(";
                break;

            case eCos:
                lStrRep = "cos(";
                break;

            case eTan:
                lStrRep = "tan";
                break;


            case eASin:
                lStrRep = "asin(";
                break;

            case eACos:
                lStrRep = "acos(";
                break;

            case eATan:
                lStrRep = "atan(";
                break;

            default:
                break;

        }

        printf(lStrRep);
        mLeft->printExpression();
        printf(")");
    }
};

#endif //TRYCL_TRIGEXPRESSION_H
