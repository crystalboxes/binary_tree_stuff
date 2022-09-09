#pragma once

#include <string>
#include "linked_list.h"
#include <tree_node/tree_node.h>

class TreeSerializer {
 public:
  class Element {
   public:
    static Element as_null() {
      Element element;
      element.type = ElementType::null;
      return element;
    }

    static Element as_number(int value) {
      Element element;
      element.type = ElementType::number;
      element.value = value;
      return element;
    }

    enum ElementType { unknown, number, null };

    ElementType type;
    int value;
  };

 public:
  TreeSerializer(const std::string& in_string) { base_expression = in_string; }
  TreeNode* deserialize();

 private:
  LinkedList<Element> tokenize();
  std::string base_expression;
};

static std::ostream& operator<<(std::ostream& str,
                                const TreeSerializer::Element& node) {
  if (node.type == TreeSerializer::Element::ElementType::null) {
    str << "null";
  } else {
    str << node.value;
  }
  return str;
}
