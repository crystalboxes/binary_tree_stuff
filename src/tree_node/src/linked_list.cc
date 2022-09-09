#include "linked_list.h"
#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& str,
                         const typename LinkedList<T>::Node& node) {
  str << node.value;
  return str;
}
