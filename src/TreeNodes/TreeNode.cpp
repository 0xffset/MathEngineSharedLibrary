//
// Created by u-0xffset on 12.11.20.
//

#include "TreeNode.hpp"

#include <utility>

MathEngine::TreeNode::TreeNode(TreeNodeType::Type _type, long double _value) :
        type(_type), value(_value) {}

MathEngine::TreeNode::TreeNode(TreeNodeType::Type _type, long double _value, std::vector<TreeNode> _nodes) :
        type(_type), value(_value), nodes(std::move(_nodes)) {}