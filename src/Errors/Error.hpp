//
// Created by u-0xffset on 19.11.20.
//

#ifndef MATHENGINESHAREDLIBRARY_ERROR_HPP
#define MATHENGINESHAREDLIBRARY_ERROR_HPP

#define RETURN_TYPE_ERROR std::variant<MathEngine::Error, MathEngine::NoError>
#define RETURN_TYPE_ERROR_TREE std::variant<MathEngine::Error, MathEngine::TreeNode>
#define RETURN_TYPE_ERROR_LONGDOUBLE std::variant<MathEngine::Error, long double>
#define RETURN_TYPE_ERROR_BOOL std::variant<MathEngine::Error, bool>

#include <string>

namespace MathEngine {
    enum class ErrorType {
        FUNC_CONST_NOT_FOUND,
        INVALID_INPUT,
        UNEVEN_DISTRIBUTION_OF_PARENTHESIS,
        EMPTY_INPUT,
        TOO_MANY_DECIMALS,
        INSUFFICIENT_ARGUMENT_COUNT,
        SQUARE_ROOT_OF_NEGATIVE,
        DIVISION_BY_ZERO,
        TOO_LARGE_FACTORIAL
    };

    struct Error {
        std::string errorMessage;
        MathEngine::ErrorType errorType;

        explicit Error(MathEngine::ErrorType _errorType);
        Error(MathEngine::ErrorType _errorType, std::string _errorMessage);
    };

    struct NoError {};
}

#endif //MATHENGINESHAREDLIBRARY_ERROR_HPP
