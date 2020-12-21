//
// Created by u-0xffset on 12.11.20.
//

#include "Subtraction.hpp"

#include <utility>

MathEngine::Subtraction::Subtraction(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {}

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::Subtraction::calc(long double params[]) {
    return RETURN_TYPE_ERROR_LONGDOUBLE{params[1] - params[0]};
}
