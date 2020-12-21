//
// Created by u-0xffset on 21.12.20.
//

#ifndef MATHENGINESHAREDLIBRARY_RULESET_HPP
#define MATHENGINESHAREDLIBRARY_RULESET_HPP

#include <variant>

#include "./../../TreeNodes/TreeNode.hpp"
#include "./../../Errors/Error.hpp"

namespace MathEngine {
    class RuleSet {
        virtual RETURN_TYPE_ERROR_BOOL applyRule(MathEngine::TreeNode &t) = 0;
    };
}

#endif //MATHENGINESHAREDLIBRARY_RULESET_HPP
