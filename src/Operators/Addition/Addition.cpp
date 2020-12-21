//
// Created by u-0xffset on 12.11.20.
//

#include "Addition.hpp"

#include <utility>

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::Addition::calc(long double params[]) {
    return RETURN_TYPE_ERROR_LONGDOUBLE{params[0] + params[1]};
}

MathEngine::Addition::Addition(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {}
