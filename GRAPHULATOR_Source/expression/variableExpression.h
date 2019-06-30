#ifndef TRYCL_VARIABLEEXPRESSION_H
#define TRYCL_VARIABLEEXPRESSION_H
#include "baseExpression.h"

//An expression that can contain a variable representation, in this case x or y
class VariableExpression : public BaseExpression
{
protected:

    //The variable type, x=true and y= false
    bool mVariable;

public:

    //Constructs a new VariableExpression
    VariableExpression(bool pVariable)
    {
        mVariable = pVariable;
    }

    //Destroys this variable expression
    ~VariableExpression()
    {
    }

    //Evaluates this variable expressions
    inline virtual float evaluate(float pX, float pY)
    {
        //Return pX if this is an x variable, or pY if this a y
        if(mVariable)
            return pX;
        else
            return pY;
    }

    //Prints this expression
    virtual void printExpression()
    {
        if(mVariable)
            printf("x");
        else
            printf("y");
    }
};

//Global X and Y variables, since we only really need one instance of each
static VariableExpression* gXVar = new VariableExpression(true);
static VariableExpression* gYVar = new VariableExpression(false);

//Defines to make them easy to access and see
#define XVAR gXVar
#define YVAR gYVar

#endif //TRYCL_VARIABLEEXPRESSION_H
