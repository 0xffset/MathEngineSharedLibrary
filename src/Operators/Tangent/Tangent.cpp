//
// Created by u-0xffset on 12.11.20.
//

#include "Tangent.hpp"

#include <utility>
#include <cmath>

MathEngine::Tangent::Tangent(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {}

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::Tangent::calc(long double params[]) {
    return RETURN_TYPE_ERROR_LONGDOUBLE{tanl(params[0])};
}
