#include <tree_node/codec.h>
#include <functional>
#include <list>
#include <sstream>
#include <vector>

void bfs_build(std::list<TreeNode*>& node_queue,
               std::list<std::string>& out_list);
std::vector<std::string> bfs(std::list<TreeNode*>& q);

std::string Codec::serialize(TreeNode* root) {
  std::list<TreeNode*> q;
  q.push_back(root);
  auto data = bfs(q);

  if (data.size() == 0) {
    return "[]";
  }

  auto i = data.size() - 1;
  while (data[i] == "null") {
    --i;
  }

  std::stringstream ss;

  ss << "[";
  for (int x = 0; x < i; x++) {
    ss << data[x];
    ss << ", ";
  }
  ss << data[i];
  ss << "]";

  return ss.str();
}

std::vector<std::string> bfs(std::list<TreeNode*>& q) {
  std::vector<std::string> level;
  std::list<TreeNode*> next_q;
  bool is_empty_level = true;

  while (q.size() != 0) {
    auto n = q.front();
    q.pop_front();
    if (n != nullptr) {
      std::stringstream ss;
      ss << n->val;

      level.push_back(ss.str());
      next_q.push_back(n->left);
      next_q.push_back(n->right);
      is_empty_level = false;
    } else {
      level.push_back("null");
    }
  }
  if (is_empty_level) {
    return level;
  }
  auto b = bfs(next_q);
  level.insert(level.end(), b.begin(), b.end());
  return level;
}

void split_into_list(const std::string& data1,
                     std::list<std::string>& out_list) {
  std::string data;
  {
    std::stringstream ss;

    for (int i = 0; i < data1.size(); ++i) {
      auto el = data1[i];
      if (el != ' ' && el != '[' && el != ']') {
        ss << el;
      }
    }

    data = ss.str();
  }

  auto& x = data;
  if (x == "") {
    return;
  }

  auto delim = ',';
  std::stringstream ss(x);
  std::string item;
  while (std::getline(ss, item, delim)) {
    out_list.push_back(std::move(item));
  }
}

TreeNode* Codec::deserialize(std::string data) {
  if (data == "[]") {
    return nullptr;
  }

  std::list<std::string> out_list;
  split_into_list(data, out_list);

  if (out_list.size() == 0) {
    return nullptr;
  }

  if (out_list.front() == "null") {
    return nullptr;
  }

  auto root = new TreeNode(std::stoi(out_list.front()));
  out_list.pop_front();

  std::list<TreeNode*> node_queue;
  node_queue.push_back(root);
  bfs_build(node_queue, out_list);

  return root;
}

void bfs_build(std::list<TreeNode*>& node_queue,
               std::list<std::string>& out_list) {
  if (out_list.size() == 0 || node_queue.size() == 0) {
    return;
  }

  std::list<TreeNode*> next_q;

  while (node_queue.size() != 0) {
    auto n = node_queue.front();
    node_queue.pop_front();

    if (n != nullptr) {
      if (out_list.size() == 0) {
        return;
      }
      auto l = out_list.front();
      std::string r = "null";
      out_list.pop_front();

      if (out_list.size() > 0) {
        r = out_list.front();
        out_list.pop_front();
      }

      if (l != "null") {
        n->left = new TreeNode(std::stoi(l));
      }

      if (r != "null") {
        n->right = new TreeNode(std::stoi(r));
      }

      next_q.push_back(n->left);
      next_q.push_back(n->right);
    }
  }

  return bfs_build(next_q, out_list);
}
