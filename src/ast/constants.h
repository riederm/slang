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
};