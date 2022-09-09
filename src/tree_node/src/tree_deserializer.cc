#include "tree_deserializer.h"
#include <iostream>

LinkedList<TreeSerializer::Element> TreeSerializer::tokenize() {
  int n = base_expression.size();

  LinkedList<TreeSerializer::Element> expressions;

  int position = 0;
  std::string num_to_build;

  while (position < n) {
    auto el = base_expression[position];

    switch (el) {
      case '[':
      case ' ':
        break;
      case 'n':
        expressions.add(Element::as_null());
        position += 4;
        continue;
      case ',':
      case ']':
        if (num_to_build.size() != 0) {
          auto value = std::stoi(num_to_build);
          expressions.add(Element::as_number(value));
          num_to_build = "";
        }
        break;
      default: {
        num_to_build += el;
      } break;
    }
    ++position;
  }

  return expressions.reversed();
}

TreeNode* TreeSerializer::deserialize() {
  struct IntermediateStruct {
    TreeNode* value = nullptr;
  };

  LinkedList<IntermediateStruct> expressions =
      this->tokenize().map<IntermediateStruct>(
          [](TreeSerializer::Element in_value) {
            IntermediateStruct st;
            if (in_value.type == TreeSerializer::Element::ElementType::null) {
              st.value = nullptr;
            } else {
              st.value = new TreeNode(in_value.value);
            }
            return st;
          });

  auto node = expressions.head;
  auto kids = expressions.head;

  auto root = kids;
  kids = kids->next;

  while (node != nullptr) {
    if (node->value.value != nullptr) {
      if (kids) {
        node->value.value->left = kids->value.value;
        kids = kids->next;
      }

      if (kids) {
        node->value.value->right = kids->value.value;
        kids = kids->next;
      }
    }

    node = node->next;
  }

  return root->value.value;
}
