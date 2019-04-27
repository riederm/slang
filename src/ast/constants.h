#pragma once

#include <string>
#include <vector>
#include <memory>
#include "ast.h"
#include "pou.h"


#include <iostream>

class IntConstant : public Expression{
    public: 
        int value;
        IntConstant(): Expression(){
            type="IntConstant";
        }
};

class BoolConstant : public Expression{
    public:
        bool value;
        BoolConstant() : Expression(){
            type="BoolConstant";
        }
};