#include <tree_node/codec.h>
#include <list>

void serialize_recurse(TreeNode* root, std::stringstream& ss);
TreeNode* deserialize_recurse(std::list<std::string>& elems);

std::string Codec::serialize(TreeNode* root) {
  if (!root) {
    return "[]";
  }

  std::stringstream ss;
  ss << "[";
  serialize_recurse(root, ss);
  ss << "]";

  return ss.str();
}

TreeNode* Codec::deserialize(std::string data) {
  auto x = data.substr(1, data.size() - 2);

  if (x == "") {
    return nullptr;
  }
  auto delim = ',';
  std::stringstream ss(x);
  std::string item;
  std::list<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(std::move(item));
  }
  return deserialize_recurse(elems);
}

void serialize_recurse(TreeNode* root, std::stringstream& ss) {
  if (!root) {
    ss << "null,";
  } else {
    ss << root->val << ",";
    serialize_recurse(root->left, ss);
    serialize_recurse(root->right, ss);
  }
}

TreeNode* deserialize_recurse(std::list<std::string>& elems) {
  if (elems.front() == "null") {
    elems.pop_front();
    return nullptr;
  }
  
  if (elems.size() == 0) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(std::stoi(elems.front()));
  elems.pop_front();
  root->left = deserialize_recurse(elems);
  root->right = deserialize_recurse(elems);

  return root;
}
