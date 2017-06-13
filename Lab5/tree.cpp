#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

tree::tree() {
  root = NULL;
  return;
}

void tree::traverseDelete(struct node * r) {
  if (r == NULL)
    return;
  traverseDelete(r->left);
  traverseDelete(r->right);
  delete r;
  return;
}

tree::~tree() {
  traverseDelete(root);
  return;
}

void tree::insert(int v) {
  struct node * p;
  struct node * q;

  if (root == NULL)
  {
    p = new struct node;
    p->left = NULL;
    p->right = NULL;
    p->val = v;
    root = p;
    return;
  }
  q = root;
  while ((v <= q->val && q->left != NULL) || (v>q->val && q->right != NULL)) {
    if (v <= q->val)
      q = q->left;
    else
      q = q->right;
  }
  p = new struct node;
  p->left = NULL;
  p->right = NULL;
  p->val = v;
  if (v <= q->val)
    q->left = p;
  else
    q->right = p;
  return;
}

void tree::sortedRec(struct node * r) {

  if (r == NULL)
    return;
  sortedRec(r->left);
  cout << r->val << " ";
  sortedRec(r->right);
  return;
}

void tree::sorted() {
  sortedRec(root);
}

void tree::deleteNode(int val) {
  root = deleteNodeHelper(root, val);
}

tree::node * tree::deleteNodeHelper(tree::node *r, int val) {

  if (r == NULL) {
    return r;
  }
  else if (val < r->val) {
    r->left = deleteNodeHelper(r->left, val);
  }
  else if (val > r->val) {
    r->right = deleteNodeHelper(r->right, val);
  }
  else {
    // Case 1: No Child
    if (r->left == NULL && r->right == NULL) {
      delete r;
      r = NULL;
      return r;
    }
    else if (r->left == NULL) { // Case 2: One Child
      node *temp = r;
      r = r->right;
      delete temp;
      return r;
    }
    else if (r->right == NULL) {
      node *temp = r;
      r = r->left;
      delete temp;
      return r;
    }
    else {
      node *temp = minimum(r->right);
      r->val = temp->val;
      r->right = deleteNodeHelper(r->right, temp->val);
    }
  }
  return r;
}

tree::node * tree::minimum(tree::node * root) {

  if (root == NULL)
    return root;
  else if (root->left == NULL) {
    return root;
  }
  return minimum(root->left);
}

tree::node * tree::maximum(tree::node *root) {
  if (root == NULL)
    return root;
  else if (root->right == NULL) {
    return root;
  }
  return maximum(root->right);
}

void tree::printTree(tree::node *root) {
  if (root == NULL)
    return;
  cout << root->val << " ";
  printTree(root->left);
  printTree(root->right);
}

tree::node * tree::getRoot() {
  return root;
}

tree::node * tree::search(int v) {

  return searchHelper(root, v);
}

tree::node * tree::searchHelper(tree::node* root,int v) {
  
  if (root == NULL)
    return root;
  else if (root->val == v) {
    return root;
  }
  if (root->val > v){
    return searchHelper(root->left,v);
  }
    return searchHelper(root->right,v);

}

tree::node * tree::successor(tree::node *current) {
  if (current == NULL) {
    return NULL;
  }
  if (current->right != NULL) {
    node * temp = current->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }
    return temp;

  }else {
    node * successor = NULL;
    node * ancestor = root;
    while (ancestor != current) {
      if (current->val < ancestor->val) {
        successor = ancestor;
        ancestor = ancestor->left;
      }
      else {
        ancestor = ancestor->right;
      }
    }
    return successor;
  }
}

tree::node * tree::predecessor(tree::node *current) {
  if (current == NULL) {
    return NULL;
  }
  if (current->left != NULL) {
    node * temp = current->left;
    while (temp->right != NULL) {
      temp = temp->right;
    }
    return temp;

  }
  else {
    node * predecessor = NULL;
    node * ancestor = root;
    while (ancestor != current) {
      if (current->val > ancestor->val) {
        predecessor = ancestor;
        ancestor = ancestor->right;
      }
      else {
        ancestor = ancestor->left;
      }
    }
    return predecessor;
  }
}