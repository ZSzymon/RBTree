#include <bits/stdc++.h>
#include <assert.h>
#include "Test.h"
using namespace std;


//template<class Key,class Comp = less<Key>>
//class RBT{
//private:

//    struct Node;
//    bool canRecolor = true;
//    enum Color{RED,BLACK};
//    struct Node{
//        Key key;
//        Color color;
//        Node *left,*right,*parent;
//        Node(Key key):left(nullptr),right(nullptr),parent(nullptr),key(key){
//            color = RED;
//        }
//        bool operator<(Key k){
//            return Comp(this->key,k) < 0;
//        }
//        bool operator>(Key k){
//            return Comp(this->key,k) > 0;
//        }
//        bool operator==(Key k){
//            return Comp(this->key,k) ==0;
//        }
//    };
//    Node *root;

//    Node *getExisingChild(Node *node){
//        return node->left ? node->left : node->right;
//    }

//    Node *getMinOfSubTree(Node *rootOfTree) const
//    {
//        if(rootOfTree){
//            Node *temp=rootOfTree;
//            do{
//                rootOfTree = temp;
//                temp = temp->left;
//            }while(temp);

//            return rootOfTree;
//        }else
//            return nullptr;

//    }
//    Node *getMaxOfSubTree(Node *rootOfTree) const
//    {
//        if(rootOfTree){
//            Node *temp=rootOfTree;
//            do{
//                rootOfTree = temp;
//                temp = temp->right;
//            }while(temp);

//            return rootOfTree;

//        }else
//            return nullptr;

//    }
//    Node *getSuccessor(Node *node) const{
//        if(!node)
//            return nullptr;

//        if(node->right){
//            return getMinOfSubTree(node->right);
//        }else{
//            Node *successor = nullptr;
//            Node *tempRoot = root;
//            while(tempRoot){
//                if(node->key < tempRoot->key){
//                    successor = tempRoot;
//                    tempRoot = tempRoot->left;
//                }
//                else if(node->key > tempRoot->key)
//                    tempRoot = tempRoot->right;
//                else
//                    break;
//            }

//            return successor;
//        }
//    }
//    Node *getPredecessor(Node *node) const
//    {
//        if(node->left){
//            return getMaxOfSubTree(node->left);
//        }else{
//            Node *temp = node->parent;
//            while(temp && temp->right != node){
//                node = temp;
//                temp = temp->parent;
//            }
//            return temp;
//        }
//    }
//    Node *getGrandParent(Node *node){
//        if(node && node->parent && node->parent->parent)
//            return node->parent->parent;
//        return nullptr;
//    }
//    Node *getParent(Node* node){
//        //assert(node->parent);
//        return node->parent;
//    }
//    Node *getSibling(Node *node){
//        if(node->parent)
//          return node->parent->key > node->key ? node->parent->right : node->parent->left;
//        return nullptr;
//    }
//    Node *getUncle(Node *node){
//        Node *grandFather = getGrandParent(node);
//        if(grandFather)
//            return node->key < grandFather->key ? grandFather->right : grandFather->left;

//        return nullptr;
//    }
//    bool hasNoChilds(Node *node){
//        return !node->left && !node->right;
//    }

//    bool hasOneChild(Node *node){
//        return (node->left && !node->right) || (!node->left && node->right);
//    }

//    bool hasTwoChilds(Node *node){
//        return !hasNoChilds(node);
//    }

//    bool hasParent(Node *node){
//        return node->parent != nullptr;
//    }


//    bool isRoot(Node *node){
//        if(node)
//            return node == root;
//        return true;
//    }
//    bool isUncleOnRightSide(Node *node,Node*grandParent){
//        assert(node && grandParent);
//        return node->key < grandParent->key;
//    }
//    bool isUncleOnLeftSide(Node *node, Node *grandParent){
//        return !isUncleOnRightSide(node,grandParent);
//    }
//    bool isLeftChild(Node *node){
//        assert(node->parent != nullptr);
//        return node->parent->key > node->key;

//    }
//    bool isRightChild(Node *node){
//        assert(node->parent != nullptr);
//        return node->parent->key < node->key;
//    }

//    Color getColorOf(Node *node){
//        if(node)
//            return node->color;
//        return BLACK;
//    }
//    void setRoot(Node* newRoot){
//        root = newRoot;
//        root->color = BLACK;
//    }
//    void _insertBST_StyleOld(Node *newNode){
//        if(root){
//            Node *temp = root;
//            Node *parent;
//            while(temp){
//                parent = temp;
//                if(newNode->key < temp->key){
//                    temp = temp->left;
//                }else{
//                    temp = temp->right;
//                }
//            }
//            temp = newNode;
//            temp->parent = parent;
//            newNode->key < parent->key ? parent->left = newNode : parent->right = newNode;
//        }

//    }
//    void _insertBST_Style(Node *newNode){
//        if(root){
//            Node *temp = root;
//            Node *parent;
//            while(temp){
//                parent = temp;
//                if(newNode->key < temp->key){
//                    temp = temp->left;
//                }else if(newNode->key > temp->key){
//                    temp = temp->right;
//                }else{
//                    return;
//                }
//            }
//            temp = newNode;
//            temp->parent = parent;
//            newNode->key < parent->key ? parent->left = newNode : parent->right = newNode;
//        }

//    }
//    void changeColor(Node *node, Color newColor){
//        if(node)
//            node->color = newColor;
//    }
//    void reverseColor(Node *node){
//        assert(node);
//        node->color = node->color == BLACK ? RED : BLACK;
//    }
//    void aVersion(Node *node){
//        changeColor(node->parent,BLACK);
//        changeColor(getUncle(node),BLACK);
//        changeColor(getGrandParent(node),RED);

//    }
//    void rightRotate(Node *node){
//        if(isRoot(node))
//            root = node->left;
//        Node *A,*B,*C,*p,*a,*b;
//        a = node->left; b = node; p = b->parent;
//        A = a->left; B = a->right; C = b->left;
//        if(p)
//            isLeftChild(b) ? p->left = a : p->right = a;
//        a->parent = p;
//        a->right = b;
//        b->parent = a;
//        b->left = B;

//        if(B)
//            B->parent = b;



//    }
//    void leftRotate(Node *node){
//        if(isRoot(node))
//            root = node->right;
//        Node *A,*B,*C,*p,*a,*b;
//        a = node;
//        b = a->right;
//        p = a->parent;
//        A = a->left; B = b->left; C = b->right;
//        if(p)
//            isLeftChild(a) ? p->left = b : p->right = b;
//        b->parent = p;
//        b->left = a;
//        a->parent = b;

//        a->right = B;
//        if(B)
//            B->parent = a;




//    }


//    void updateParentAndNode(Node *node, Node *parent){
//        if(parent->parent == node)
//            swap(parent,node);
//    }
//    void reColor(Node *node){
//        if(!node)
//            return;
//        if(isRoot(node)){
//            changeColor(node,BLACK);

//        }

//        if(getColorOf(node->parent) != BLACK && !isRoot(node)){
//            Node *uncle = getUncle(node);
//            Node *parent = getParent(node);
//            Node *grandParent = getGrandParent(node);
//            //I
//            if(getColorOf(uncle) == RED){
//                aVersion(node);
//                reColor(grandParent);

//            }
//            //b version
//            else if(getColorOf(uncle) == BLACK){
//                //II
//                //co jezeli uncle nie istnieje
//                if(isRightChild(node) && isUncleOnRightSide(node,grandParent)){
//                    leftRotate(parent);

//                }

//                //lustrzane odbicie.
//                else if(isLeftChild(node) && isUncleOnLeftSide(node,grandParent)){
//                    rightRotate(parent);

//                }

//                if(parent->parent == node)
//                    swap(parent,node);
//                //updateParentAndNode(node,parent);
//                //po rotacji wskazniki parent i node moga byc na odwrót. Sprawdz to.
//                //III
//                // przyjmuje ze wskazniki parent and node sa poprawne.
//                //czy wujek tutaj zawsze jest czarny ?
//                if(getColorOf(uncle) == BLACK && isLeftChild(node) && isUncleOnRightSide(node,grandParent)){
//                    rightRotate(grandParent);

//                }

//                else if(getColorOf(uncle)== BLACK && isRightChild(node) && isUncleOnLeftSide(node,grandParent)){
//                    leftRotate(grandParent);

//                }

//                updateParentAndNode(node,parent);
//                reverseColor(parent);
//                reverseColor(getSibling(node));



//            }


//        }
//    }

//    void inOrder(Node *node){
//        if(!node)
//            return;

//        inOrder(node->left);
//        cout<<node->key <<" ";
//        inOrder(node->right);
//    }
//public:
//    RBT(){
//        root = nullptr;


//    }
//    Node *findKey(Key key) const{
//        Node *temp = root;
//        while(temp){
//            if(temp->key == key)
//                return temp;
//            else if(temp->key > key)
//                temp = temp->left;
//            else
//                temp = temp->right;
//        }
//        return nullptr;
//    }
//    void insert(Key key){
//        Node *newNode = new Node(key);
//        if(root){
//            _insertBST_Style(newNode);
//            if(canRecolor)
//                reColor(newNode);
//        }else{
//            setRoot(newNode);
//        }
//    }
//    void remove_bst(Node *toDelete){
//        if(!toDelete)
//            return;
//        Node *father = toDelete->parent;

//        //case No childs.
//        if(hasNoChilds(toDelete)){
//            if(father){
//                father->key > toDelete->key ? father->left = nullptr : father->right = nullptr;
//            }else{
//                root = nullptr;
//            }
//            //delete toDelete;

//        }
//        //case oneChild
//        else if(hasOneChild(toDelete)){
//            Node *child = getExisingChild(toDelete);

//            if(father){
//                father->key > toDelete->key ? father->left = child : father->right = child;
//                child->parent = father;
//            }
//            if(toDelete == root){
//                root = child;
//                root->parent = nullptr;
//            }
//            //delete toDelete;
//        }
//        //case two childs
//        else{
//            Node * succesor = getSuccessor(toDelete);
//            toDelete->key = succesor->key;
//            remove_bst(succesor);
//        }

//    }

//};



int main()
{

    Test test;
    test.insertTest();
    return 0;
}



