
#ifndef __APPLE__

#include "baseExpression.h"
#include "addExpression.h"
#include "divideExpression.h"
#include "lnExpression.h"
#include "logExpression.h"
#include "modExpression.h"
#include "multiplyExpression.h"
#include "numberExpression.h"
#include "powExpression.h"
#include "subtractExpression.h"
#include "trigExpression.h"
#include "variableExpression.h"
#include "rpnBuilder.h"
#include "token.h"

#else

#include "expression/baseExpression.h"
#include "expression\addExpression.h"
#include "expression\divideExpression.h"
#include "expression\multiplyExpression.h"
#include "expression\numberExpression.h"
#include "expression\powExpression.h"
#include "expression\subtractExpression.h"
#include "expression\variableExpression.h"
#include "RPN/rpnBuilder.h"
#include "RPN/token.h"

#endif


BaseExpression* processString(std::string s)
{
    RPNBuilder* builder = new RPNBuilder();
    std::vector<Token> vec = builder->convertToRPN(s);

    std::stack<BaseExpression*> lExpression;
    for(int i =0; i<vec.size(); i++)
    {
        if(vec[i].getType() == eVariable)
        {
            if(vec[i].toString() == "x")
                lExpression.push(XVAR);
            else
                lExpression.push(YVAR);
        }
        else if(vec[i].getType() == eLiteral)
        {
            lExpression.push(new NumberExpression(atof(vec[i].toString().c_str())));
        }
        else if(vec[i].getType() == eOperator)
        {
            BaseExpression* lRight = lExpression.top();
            lExpression.pop();
            BaseExpression* lLeft  =lExpression.top();
            lExpression.pop();

            switch(vec[i].toString()[0])
            {
                case '+':
                    lExpression.push(new AddExpression(lLeft, lRight));
                    break;
                case '-':
                    lExpression.push(new SubtractExpression(lLeft, lRight));
                    break;
                case '*':
                    lExpression.push(new MultiplyExpression(lLeft, lRight));
                    break;
                case '/':
                    lExpression.push(new DivideExpression(lLeft, lRight));
                    break;
                case '^':
                    lExpression.push(new PowerExpression(lLeft, lRight));
                    break;
                default:
                    break;
            }
        }
    }

    return lExpression.top();
}
