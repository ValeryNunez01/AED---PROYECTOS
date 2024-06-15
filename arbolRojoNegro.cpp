#include <iostream>
using namespace std;

struct Node {
  int NodeData;
  Node *parentNode;
  Node *leftNode;
  Node *rightNode;
  int NodeColor;
};

typedef Node *NodePtr;

class REDBLACKTREE {
 private:
  NodePtr root;
  NodePtr TNULL;

  void INITIALIZENULLNode(NodePtr node, NodePtr parentNode) {
    node->NodeData = 0;
    node->parentNode = parentNode;
    node->leftNode = NULL;
    node->rightNode = NULL;
    node->NodeColor = 0;
  }

  // The Preorder
  void PREORDERHELPER(NodePtr node) {


/*window.adpushup.adpTags.que.push(function(){
window.adpushup.adpTags.display("ADP_45492_728X90_66b1eed8-efb1-464a-a03f-53a47bb2d7ad");
});*/

    if (node != TNULL) {
      cout << node->NodeData << " ";
      PREORDERHELPER(node->leftNode);
      PREORDERHELPER(node->rightNode);
    }
  }

  // The Inorder
  void INORDERHELPER(NodePtr node) {
    if (node != TNULL) {
      INORDERHELPER(node->leftNode);
      cout << node->NodeData << " ";
      INORDERHELPER(node->rightNode);
    }
  }

  // the Post order
  void POSTORDERHELPER(NodePtr node) {
    if (node != TNULL) {
      POSTORDERHELPER(node->leftNode);
      POSTORDERHELPER(node->rightNode);
      cout << node->NodeData << " ";
    }
  }

  NodePtr SEARCHTREEHELPER(NodePtr node, int key) {
    if (node == TNULL || key == node->NodeData) {
      return node;
    }

    if (key < node->NodeData) {
      return SEARCHTREEHELPER(node->leftNode, key);
    }
    return SEARCHTREEHELPER(node->rightNode, key);
  }

  // For balancing the tree after deletion
  void DELETEFIX(NodePtr x) {
    NodePtr s;
    while (x != root && x->NodeColor == 0) {
      if (x == x->parentNode->leftNode) {
        s = x->parentNode->rightNode;
        if (s->NodeColor == 1) {
          s->NodeColor = 0;
          x->parentNode->NodeColor = 1;
          LEFTROTATE(x->parentNode);
          s = x->parentNode->rightNode;
        }

        if (s->leftNode->NodeColor == 0 && s->rightNode->NodeColor == 0) {
          s->NodeColor = 1;
          x = x->parentNode;
        } else {
          if (s->rightNode->NodeColor == 0) {
            s->leftNode->NodeColor = 0;
            s->NodeColor = 1;
            RIGHTNODEROTATE(s);
            s = x->parentNode->rightNode;
          }

          s->NodeColor = x->parentNode->NodeColor;
          x->parentNode->NodeColor = 0;
          s->rightNode->NodeColor = 0;
          LEFTROTATE(x->parentNode);
          x = root;
        }
      } else {
        s = x->parentNode->leftNode;
        if (s->NodeColor == 1) {
          s->NodeColor = 0;
          x->parentNode->NodeColor = 1;
          RIGHTNODEROTATE(x->parentNode);
          s = x->parentNode->leftNode;
        }

        if (s->rightNode->NodeColor == 0 && s->rightNode->NodeColor == 0) {
          s->NodeColor = 1;
          x = x->parentNode;
        } else {
          if (s->leftNode->NodeColor == 0) {
            s->rightNode->NodeColor = 0;
            s->NodeColor = 1;
            LEFTROTATE(s);
            s = x->parentNode->leftNode;
          }

          s->NodeColor = x->parentNode->NodeColor;
          x->parentNode->NodeColor = 0;
          s->leftNode->NodeColor = 0;
          RIGHTNODEROTATE(x->parentNode);
          x = root;
        }
      }
    }
    x->NodeColor = 0;
  }

  void RBTRANSPLANT(NodePtr u, NodePtr v) {
    if (u->parentNode == NULL) {
      root = v;
    } else if (u == u->parentNode->leftNode) {


/*window.adpushup.adpTags.que.push(function(){
window.adpushup.adpTags.display("11994_ADP_45492_728X90_6ceba180-c3ab-4848-9570-3e144abe8fd9");
});*/

      u->parentNode->leftNode = v;
    } else {
      u->parentNode->rightNode = v;
    }
    v->parentNode = u->parentNode;
  }

  void DELETENODEHELPER(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->NodeData == key) {
        z = node;
      }

      if (node->NodeData <= key) {
        node = node->rightNode;
      } else {
        node = node->leftNode;
      }
    }

    if (z == TNULL) {
      cout << "The Key is not found in the tree" << endl;
      return;
    }

    y = z;
    int y_original_NodeColor = y->NodeColor;
    if (z->leftNode == TNULL) {
      x = z->rightNode;
      RBTRANSPLANT(z, z->rightNode);
    } else if (z->rightNode == TNULL) {
      x = z->leftNode;
      RBTRANSPLANT(z, z->leftNode);
    } else {
      y = minimum(z->rightNode);
      y_original_NodeColor = y->NodeColor;
      x = y->rightNode;
      if (y->parentNode == z) {
        x->parentNode = y;
      } else {
        RBTRANSPLANT(y, y->rightNode);
        y->rightNode = z->rightNode;
        y->rightNode->parentNode = y;
      }

      RBTRANSPLANT(z, y);
      y->leftNode = z->leftNode;
      y->leftNode->parentNode = y;
      y->NodeColor = z->NodeColor;
    }
    delete z;
    if (y_original_NodeColor == 0) {
      DELETEFIX(x);
    }
  }

  // balance the tree after insertion
  void INSERTFIX(NodePtr k) {
    NodePtr u;
    while (k->parentNode->NodeColor == 1) {
      if (k->parentNode == k->parentNode->parentNode->rightNode) {
        u = k->parentNode->parentNode->leftNode;
        if (u->NodeColor == 1) {
          u->NodeColor = 0;
          k->parentNode->NodeColor = 0;
          k->parentNode->parentNode->NodeColor = 1;
          k = k->parentNode->parentNode;
        } else {
          if (k == k->parentNode->leftNode) {
            k = k->parentNode;
            RIGHTNODEROTATE(k);
          }
          k->parentNode->NodeColor = 0;
          k->parentNode->parentNode->NodeColor = 1;
          LEFTROTATE(k->parentNode->parentNode);
        }
      } else {
        u = k->parentNode->parentNode->rightNode;

        if (u->NodeColor == 1) {
          u->NodeColor = 0;
          k->parentNode->NodeColor = 0;
          k->parentNode->parentNode->NodeColor = 1;
          k = k->parentNode->parentNode;
        } else {
          if (k == k->parentNode->rightNode) {
            k = k->parentNode;
            LEFTROTATE(k);
          }
          k->parentNode->NodeColor = 0;
          k->parentNode->parentNode->NodeColor = 1;
          RIGHTNODEROTATE(k->parentNode->parentNode);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->NodeColor = 0;
  }

  void PRINTHELPER(NodePtr root, string indent, bool last) {

/*
window.adpushup.adpTags.que.push(function(){
window.adpushup.adpTags.display("ADP_45492_728X90_769fb77a-b6a5-4947-aab6-bd97f2c30c20");
});*/

    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R-----";
        indent += "    ";
      } else {
        cout << "L-----";
        indent += "|   ";
      }

      string sNodeColor = root->NodeColor ? "RED" : "BLACK";
      cout << root->NodeData << "(" << sNodeColor << ")" << endl;
      PRINTHELPER(root->leftNode, indent, false);
      PRINTHELPER(root->rightNode, indent, true);
    }
  }

 public:
  REDBLACKTREE() {
    TNULL = new Node;
    TNULL->NodeColor = 0;
    TNULL->leftNode = NULL;
    TNULL->rightNode = NULL;
    root = TNULL;
  }

  void preorder() { PREORDERHELPER(this->root); }

  void inorder() { INORDERHELPER(this->root); }

  void postorder() { POSTORDERHELPER(this->root); }

  NodePtr searchTree(int k) { return SEARCHTREEHELPER(this->root, k); }

  NodePtr minimum(NodePtr node) {
    while (node->leftNode != TNULL) {
      node = node->leftNode;
    }
    return node;
  }

  NodePtr maximum(NodePtr node) {
    while (node->rightNode != TNULL) {
      node = node->rightNode;
    }
    return node;
  }

  NodePtr successor(NodePtr x) {
    if (x->rightNode != TNULL) {
      return minimum(x->rightNode);
    }

    NodePtr y = x->parentNode;
    while (y != TNULL && x == y->rightNode) {
      x = y;
      y = y->parentNode;
    }
    return y;
  }

  NodePtr predecessor(NodePtr x) {
    if (x->leftNode != TNULL) {
      return maximum(x->leftNode);
    }

    NodePtr y = x->parentNode;
    while (y != TNULL && x == y->leftNode) {
      x = y;
      y = y->parentNode;
    }

    return y;
  }

  void LEFTROTATE(NodePtr x) {
    NodePtr y = x->rightNode;
    x->rightNode = y->leftNode;
    if (y->leftNode != TNULL) {
      y->leftNode->parentNode = x;
    }
    y->parentNode = x->parentNode;
    if (x->parentNode == NULL) {
      this->root = y;
    } else if (x == x->parentNode->leftNode) {
      x->parentNode->leftNode = y;
    } else {
      x->parentNode->rightNode = y;
    }
    y->leftNode = x;
    x->parentNode = y;
  }

  void RIGHTNODEROTATE(NodePtr x) {
    NodePtr y = x->leftNode;
    x->leftNode = y->rightNode;
    if (y->rightNode != TNULL) {
      y->rightNode->parentNode = x;
    }
    y->parentNode = x->parentNode;


/*window.adpushup.adpTags.que.push(function(){
window.adpushup.adpTags.display("ADP_45492_728X90_b4aa9dd3-4c73-49db-96ca-2dbd224bfa58");
});*/

    if (x->parentNode == NULL) {
      this->root = y;
    } else if (x == x->parentNode->rightNode) {
      x->parentNode->rightNode = y;
    } else {
      x->parentNode->leftNode = y;
    }
    y->rightNode = x;
    x->parentNode = y;
  }

  // Inserting a node
  void INSERTNODE(int key) {
    NodePtr node = new Node;
    node->parentNode = NULL;
    node->NodeData = key;
    node->leftNode = TNULL;
    node->rightNode = TNULL;
    node->NodeColor = 1;

    NodePtr y = NULL;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->NodeData < x->NodeData) {
        x = x->leftNode;
      } else {
        x = x->rightNode;
      }
    }

    node->parentNode = y;
    if (y == NULL) {
      root = node;
    } else if (node->NodeData < y->NodeData) {
      y->leftNode = node;
    } else {
      y->rightNode = node;
    }

    if (node->parentNode == NULL) {
      node->NodeColor = 0;
      return;
    }

    if (node->parentNode->parentNode == NULL) {
      return;
    }

    INSERTFIX(node);
  }

  NodePtr getRoot() { return this->root; }

  void DELETENODE(int NodeData) { DELETENODEHELPER(this->root, NodeData); }

  void printTree() {
    if (root) {
      PRINTHELPER(this->root, "", true);
    }
  }
};

int main() {
  REDBLACKTREE DEMOBST;
  DEMOBST.INSERTNODE(51);
  DEMOBST.INSERTNODE(44);
  DEMOBST.INSERTNODE(62);
  DEMOBST.INSERTNODE(34);
  DEMOBST.INSERTNODE(85);
  DEMOBST.INSERTNODE(54);

  DEMOBST.printTree();
  cout << endl << "After deleting" << endl;
  DEMOBST.DELETENODE(62);
  DEMOBST.printTree();
}
