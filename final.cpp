//Fuente: Delft Stack

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

    //inicializar un nodo ya creado
  void INITIALIZENULLNode(NodePtr node, NodePtr parentNode) {
    node->NodeData = 0;
    node->parentNode = parentNode;
    node->leftNode = NULL;
    node->rightNode = NULL;
    node->NodeColor = 0;
  }

  //recorrer e imprimir el arbol en preorden
  void PREORDERHELPER(NodePtr node) {
    if (node != TNULL) {
      cout << node->NodeData << " ";
      PREORDERHELPER(node->leftNode);
      PREORDERHELPER(node->rightNode);
    }
  }

  //recorrer e imprimir el arbol en orden
  void INORDERHELPER(NodePtr node) {
    if (node != TNULL) {
      INORDERHELPER(node->leftNode);
      cout << node->NodeData << " ";
      INORDERHELPER(node->rightNode);
    }
  }

  //recorrer e imprimir el arbol en postorden
  void POSTORDERHELPER(NodePtr node) {
    if (node != TNULL) {
      POSTORDERHELPER(node->leftNode);
      POSTORDERHELPER(node->rightNode);
      cout << node->NodeData << " ";
    }
  }

    //puscar cierto numero dentro del arbol
  NodePtr SEARCHTREEHELPER(NodePtr node, int key) {
    //si se encuentra el numero o si el nodo actual es nulo
    if (node == TNULL || key == node->NodeData) {
      return node;
    }

    //buscar en la siguiente rama
    if (key < node->NodeData) {
      return SEARCHTREEHELPER(node->leftNode, key);
    }
    return SEARCHTREEHELPER(node->rightNode, key);
  }

  // rebalancear el arbol
  void DELETEFIX(NodePtr x) {
    NodePtr s;

    //mientras x no sea la raiz y no sea de color negro
    while (x != root && x->NodeColor == 0) {
        //si x es un hijo izquierdo
      if (x == x->parentNode->leftNode) {
        //s es el hermano de x
        s = x->parentNode->rightNode;
        //si el hermano es rojo
        if (s->NodeColor == 1) {
            //el hermano es negro
          s->NodeColor = 0;
          //el padre es rojo
          x->parentNode->NodeColor = 1;
          //rotar a la izquierda con eje en el padre de x
          LEFTROTATE(x->parentNode);
          //s es el nuevo de x, previamente el hijo izquierdo de s
          s = x->parentNode->rightNode;
        }

        //propiedad 4
        //si ambos hijos de s son de color negro
        if (s->leftNode->NodeColor == 0 && s->rightNode->NodeColor == 0) {
            //s es rojo
          s->NodeColor = 1;
          //x es su padre
          x = x->parentNode;
        } else {
            //si el hijo derecho es negro
          if (s->rightNode->NodeColor == 0) {
            //el hijo isquierdo es negro
            s->leftNode->NodeColor = 0;
            //s es rojo
            s->NodeColor = 1;
            //rotación a la derecha con eje en s
            RIGHTNODEROTATE(s);
            //s es el hermano de x, el cual es el nuevo padre de s, previamente el hijo izquierdo de s
            s = x->parentNode->rightNode;
          }

          s->NodeColor = x->parentNode->NodeColor;
          x->parentNode->NodeColor = 0;
          s->rightNode->NodeColor = 0;
          //rotamos a la izquierda con eje en el padre de x
          LEFTROTATE(x->parentNode);
          //x es igual a la raiz para salir del bucle
          x = root;
        }
      } else {
        //lo mismo pero a la derecha
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

    //trasplantar v al lugar de u
  void RBTRANSPLANT(NodePtr u, NodePtr v) {
    if (u->parentNode == NULL) {
        //si u es el nodo raiz
      root = v;
    } else if (u == u->parentNode->leftNode) {
        //si u es el izquierdo
      u->parentNode->leftNode = v;
    } else {
        //si u es el derecho
      u->parentNode->rightNode = v;
    }
    //configurar padres
    v->parentNode = u->parentNode;
  }

//eliminar un cierto numero
  void DELETENODEHELPER(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;

    //buscar el nodo a eliminar
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

    //si no se encuentra el nodo
    if (z == TNULL) {
      cout << "The Key is not found in the tree" << endl;
      return;
    }

    //si se encuentra el nodo
    y = z;
    int y_original_NodeColor = y->NodeColor;
    //si el hijo izquierdo es nulo
    if (z->leftNode == TNULL) {
      x = z->rightNode;

      //trasplantar el hijo derecho al nodo actual
      RBTRANSPLANT(z, z->rightNode);
    } else if (z->rightNode == TNULL) {
        //si el hijo derecho es nulo trasplantar el hijo izquierdo al nodo actual
      x = z->leftNode;
      RBTRANSPLANT(z, z->leftNode);
    } else {
        //si ambos hijos existen
        //ir 1 a la derecha y todo a la izquierda
        //y será el nodo menor del lado derecho del arbol a partir del nodo actual
      y = minimum(z->rightNode);
      //reemplazar el color por del nodo actual
      y_original_NodeColor = y->NodeColor;
      x = y->rightNode;
      
      //si el nodo derecho no tuvo un hijo izquierdo
      if (y->parentNode == z) {
        x->parentNode = y;
      } else {
        //trasplantar el hijo derecho de y a la ubicacion de y
        RBTRANSPLANT(y, y->rightNode);
        //el hijo derecho de y será el hijo derecho del nodo actual
        y->rightNode = z->rightNode;
        //configurar los padres
        y->rightNode->parentNode = y;
      }

        //trasplantar a y a la posicion del nodo actual
      RBTRANSPLANT(z, y);
      //configurar el lado izquierdo del nodo actual
      y->leftNode = z->leftNode;
      y->leftNode->parentNode = y;
      y->NodeColor = z->NodeColor;
    }
    //borrar el nodo actual
    delete z;
    if (y_original_NodeColor == 0) {
        //rebalancear los hijos a la derecha del nodo y
      DELETEFIX(x);
    }
  }

  // rebalancear el arbol luego de una inserción
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
    //proposicion 2
    //la raiz es de color negro
    root->NodeColor = 0;
  }

  void PRINTHELPER(NodePtr root, string indent, bool last) {
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
    //si la raiz no es nula
    if (root)
      PRINTHELPER(this->root, "", true);
    else 
        cout << endl << "arbol vacio";
  }
};

int menu(){
    int opcion;

    cout << endl << "1. insertar nodo";
    cout << endl << "2. eliminar nodo";
    cout << endl << "3. visualizar arbol";
    cout << endl << "4. salir";

    cout << endl << "ingrese una opcion : ";
    cin >> opcion;
    return opcion;
}

int main() {
  REDBLACKTREE DEMOBST;
  bool corriendo = true;
    int x;

  while(corriendo){
    switch(menu()){
        case 1:
            cout << endl << "insertar un numero : ";
            cin >> x;
            DEMOBST.INSERTNODE(x);
            break;

        case 2:
            cout << endl << "eliminar un numero : ";
            cin >> x;
            DEMOBST.DELETENODE(x);
            break;

        case 3:
            DEMOBST.printTree();
            break;

        case 4:
            cout << endl << "saliendo";
            corriendo = false;
            break;

        default:
            cout << endl << "no se encuentra la opcion";
    }
  }

  /*
  DEMOBST.INSERTNODE(51);
  DEMOBST.INSERTNODE(44);
  DEMOBST.INSERTNODE(62);
  DEMOBST.INSERTNODE(34);
  DEMOBST.INSERTNODE(85);
  DEMOBST.INSERTNODE(54);

  DEMOBST.printTree();
  cout << endl << "After deleting" << endl;
  DEMOBST.DELETENODE(51);
  DEMOBST.printTree();
  */
}
