//
// Created by u-0xffset on 12.11.20.
//

#include "Constant.hpp"

#include <utility>

MathEngine::Constant::Constant(long double _value, std::string _sr) :
        value(_value), stringRepresentation(std::move(_sr)) {}