//
// Created by u-0xffset on 10.11.20.
//

#include "Operator.hpp"

#include <utility>

MathEngine::Operator::Operator(int _pr, std::string _sr, int _ac) :
        precedence(_pr), stringRepresentation(std::move(_sr)), argumentCount(_ac) {}