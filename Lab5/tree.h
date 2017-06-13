#ifndef TREE_CLASS
#define TREE_CLASS
class tree {
private:

  struct node {
    int val;
    struct node * left;
    struct node * right;
  };

  struct node * root;
  void traverseDelete(struct node *r);
  void sortedRec(struct node *r);

public:


  explicit tree();
  ~tree();
  void insert(int v);
  void sorted();
  struct node * successor(struct node * p);
  struct node * predecessor(struct node * p);
  void printTree(struct node * root);
  struct node * deleteNodeHelper(struct node *r, int val);
  void deleteNode(int val);
  struct node * minimum(struct node * root);
  struct node * maximum(struct node * root);
  struct node * getRoot();
  struct node * search(int v);
  struct node * searchHelper(struct node *root, int v);
  

};
#endif
