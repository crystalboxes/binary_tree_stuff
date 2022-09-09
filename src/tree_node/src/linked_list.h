#pragma once
#include <functional>
#include <memory>
#include <sstream>

template <typename T>
class LinkedList {
 public:
  class Node {
   public:
    Node(T in_value) { value = in_value; }
    T value;

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& rhs);

    std::shared_ptr<Node> next = nullptr;

   private:
    friend LinkedList;
  };

  std::shared_ptr<Node> head = nullptr;

  LinkedList<T> reversed() {
    LinkedList<T> the_list;

    auto first = this->head;
    while (first) {
      the_list.add(first->value);
      first = first->next;
    }

    return the_list;
  }

  template <typename V>
  LinkedList<V> map(std::function<V(T)> fn) const {
    LinkedList<V> the_list;

    auto first = this->head;
    while (first) {
      T value = first->value;
      auto converted = fn(value);
      the_list.add(converted);
      first = first->next;
    }

    return the_list.reversed();
  }

  void add(const T& value) {
    auto new_head = std::make_shared<Node>(value);
    new_head->next = head;
    this->head = new_head;
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
  auto node = list.head;
  os << "[";
  bool isStarted = false;

  while (node) {
    if (isStarted) {
      os << ", ";
    } else {
      isStarted = true;
    }

    os << node->value;
    node = node->next;
  }

  os << "]";
  return os;
}
