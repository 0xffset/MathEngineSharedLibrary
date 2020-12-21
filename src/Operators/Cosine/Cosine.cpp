//
// Created by u-0xffset on 12.11.20.
//

#include "Cosine.hpp"

#include <utility>
#include <cmath>

MathEngine::Cosine::Cosine(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {}

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::Cosine::calc(long double params[]) {
    return RETURN_TYPE_ERROR_LONGDOUBLE{cosl(params[0])};
}
