#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    if (root_!= nullptr){
      insert(key, value, root_);
    } else {
      Node* newNode = new Node(key, value);
      root_ = newNode;
    }
  }

  bool BinarySearchTree::Remove(int key) {
    if (root_ != nullptr) {
      return remove(key, root_);
    }
    return false;
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
      return find_min(root_)->value;
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ != nullptr) {
      return find_max(root_)->value;
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
      if (node->right!= nullptr) {
        insert(key, value, node->right);
      } else {
        Node* newNode = new Node(key,value);
        node->right = newNode;
      }
    } else if (key < node->key) {
      if (node->left!= nullptr) {
        insert(key, value, node->left);
      } else {
        Node* newNode = new Node(key,value);
        node->left = newNode;
      }
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
        Node* minim = find_min(node->right);
        node->key = minim->key;
        node->value = minim->value;
        return remove(minim->key, node->right);
      }
    } else if (key > node->key) {
      if (node->right != nullptr) {
        return remove(key, node->right);
      } else {
        return false;
      }
    } else if (key < node->key){
      if (node->left != nullptr) {
        return remove(key, node->left);
      } else {
        return false;
      }
    }
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
      return find(key, node->right);
    }
    if (key < node->key) {
      return find(key, node->left);
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
      return find_max(node->right);
    } else {
      return node;
    }
  }

}  // namespace assignment