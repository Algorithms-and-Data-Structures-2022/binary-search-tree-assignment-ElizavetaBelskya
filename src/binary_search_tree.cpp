#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
      clear(root_);
      root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* node = find(key, root_);
    if (node != nullptr) {
      return node->value;
    } else {
      return std::nullopt;
    }
  }

  bool BinarySearchTree::Contains(int key) const {
    if (Find(key) != std::nullopt) {
      return true;
    }
    return false;
  }

  bool BinarySearchTree::IsEmpty() const {
    return (root_== nullptr);
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ != nullptr) {
      find_min(root_);
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ != nullptr) {
      find_max(root_);
    }
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    if (root_ != nullptr) {
      return root_;
    } else {
      return nullptr;
    }
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node->key == key) {
      node->value = value;
    } else if (key > node->key) {
      insert(key, value, node->right);
    } else if (key < node->key) {
      insert(key, value, node->left);
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node->key == key) {
      if (node->left == nullptr && node->right == nullptr) {
        node = nullptr;
        return true;
      } else if (node->right == nullptr) {
        node = node->left;
        node->left = nullptr;
        return true;
      } else if (node->left == nullptr) {
        node = node->right;
        node->right = nullptr;
        return true;
      } else {
        node->key = find_min(node->right)->key;
        node->value = find_min(node->right)->value;
        find_min(node->right) == nullptr;
        return true;
      }
    }
    if (node->left != nullptr || node->right != nullptr) {
      if (key > node->key) {
        remove(key, node->right);
      } else if (key < node->key) {
        remove(key,  node->left);
      }
    }
    return false;

  }

  void BinarySearchTree::clear(Node* node) {
    if (node == nullptr) {
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }
    if (key > node->key) {
      find(key, node->right);
    }
    if (key < node->key) {
      find(key, node->left);
    }
    return node;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (node->left != nullptr) {
      return find_min(node->left);
    } else {
      return node;
    }
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (node->right != nullptr) {
      return find_min(node->right);
    } else {
      return node;
    }
  }

}  // namespace assignment