//
// Created by u-0xffset on 27.11.20.
//

#ifndef MATHENGINESHAREDLIBRARY_FACTORIAL_HPP
#define MATHENGINESHAREDLIBRARY_FACTORIAL_HPP

#include "./../Operator.hpp"
#include "../../Errors/Error.hpp"

#include <variant>

namespace MathEngine {
    class Factorial : public MathEngine::Operator {
    public:
        Factorial(int _pr, std::string _sr, int _ac);

        RETURN_TYPE_ERROR_LONGDOUBLE calc(long double params[]) override;
    };
}

#endif //MATHENGINESHAREDLIBRARY_FACTORIAL_HPP
