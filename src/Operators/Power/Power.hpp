//
// Created by u-0xffset on 12.11.20.
//

#ifndef MATHENGINE_POWER_HPP
#define MATHENGINE_POWER_HPP

#include "./../Operator.hpp"
#include "../../Errors/Error.hpp"

#include <variant>

namespace MathEngine {
    class Power : public MathEngine::Operator {
    public:
        Power(int _pr, std::string _sr, int _ac);

        RETURN_TYPE_ERROR_LONGDOUBLE calc(long double params[]) override;
    };
}

#endif //MATHENGINE_POWER_HPP
