cmake_minimum_required(VERSION 3.17)
project(MathEngineSharedLibrary)

set(CMAKE_CXX_STANDARD 17)

add_library(MathEngineSharedLibrary SHARED
        src/Main.hpp
        src/HeaderOfConvenience.hpp
        src/Calculator/Calculator.hpp
        src/Constants/Constant.hpp
        src/Constants/Constant.cpp
        src/Parsing/RPNtoBinaryTree/RPNtoBinaryTree.hpp
        src/Parsing/RPNtoBinaryTree/RPNtoBinaryTree.cpp
        src/Parsing/InfixToRPN/InfixToRPN.hpp
        src/Parsing/InfixToRPN/InfixToRPN.cpp
        src/Parsing/InputParser/InputParser.cpp
        src/Parsing/InputParser/InputParser.hpp
        src/Errors/ShowError/ShowError.hpp
        src/Errors/ShowError/ShowError.cpp
        src/Errors/IncludeErrors.hpp
        src/Calculator/Calculator.cpp
        src/HeaderOfConvenience.cpp
        src/Operators/Sine/Sine.cpp
        src/Operators/Sine/Sine.hpp
        src/Operators/SquareRoot/SquareRoot.cpp
        src/Operators/SquareRoot/SquareRoot.hpp
        src/Operators/Tangent/Tangent.hpp
        src/Operators/Tangent/Tangent.cpp
        src/Operators/Cosine/Cosine.hpp
        src/Operators/Cosine/Cosine.cpp
        src/Operators/Operator.hpp
        src/Operators/Power/Power.cpp
        src/Operators/Power/Power.hpp
        src/Operators/IncludeOperators.hpp
        src/Operators/Addition/Addition.hpp
        src/Operators/Addition/Addition.cpp
        src/Operators/Multiplication/Multiplication.cpp
        src/Operators/Multiplication/Multiplication.hpp
        src/Operators/Sign/Sign.hpp
        src/Operators/Sign/Sign.cpp
        src/Operators/Subtraction/Subtraction.cpp
        src/Operators/Subtraction/Subtraction.hpp
        src/Operators/Division/Division.cpp
        src/Operators/Division/Division.hpp
        src/Operators/Operator.cpp
        src/TreeNodes/TreeNode.cpp
        src/TreeNodes/TreeNode.hpp
        src/Main.cpp
        src/Errors/Error.hpp src/Errors/Error.cpp src/Operators/Factorial/Factorial.cpp src/Operators/Factorial/Factorial.hpp src/Parsing/RuleSets/RuleSet.hpp src/Parsing/RuleSets/IncludeRuleSets.hpp src/Parsing/RuleSets/SineSpecialCases/SineSpecialCases.cpp src/Parsing/RuleSets/SineSpecialCases/SineSpecialCases.hpp)