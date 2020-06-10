
/**
 * @author : Aditya Kumar Singh
 * Binary tree
 */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// for storing tree node data
template <class NodeType>
struct Node{
    NodeType data;
    Node<NodeType> *left, *right;
    Node(NodeType); // constructor
};

// Binary Search tree class
template <class TreeType>
class BinarySearchTree{
private: // private data
    Node<TreeType> *root_;  //to store root of the tree
private: // private function
    void PreOrder(Node<TreeType> *);
    void InOrder(Node<TreeType> *);
    void PostOrder(Node<TreeType> *);

    void Insert(Node<TreeType> *,TreeType);
    Node<TreeType>* Delete(Node<TreeType> *,TreeType);

    Node<TreeType>* Search(Node<TreeType> *, TreeType) const;
    Node<TreeType> * MinNode(Node<TreeType> *) const;
    Node<TreeType> * MaxNode(Node<TreeType> *) const;
    int  Height(Node<TreeType> *) const;
public: // public function
    BinarySearchTree();
    void LevelOrder();
    void PreOrder();
    void PostOrder();
    void InOrder();

    void Insert(TreeType);
    void Delete(TreeType);

    bool Search(TreeType) const;
    int  Height() const;
};

int main(){
    BinarySearchTree<int> tree;
    tree.LevelOrder();
    tree.Insert(10);
    tree.Insert(11);
    tree.Insert(8);
    tree.Insert(19);
    tree.Insert(7);
    tree.Insert(9);
    tree.Insert(18);
    tree.Insert(20);
    tree.Insert(21);
    tree.LevelOrder();
    tree.PreOrder();
    tree.PostOrder();
    tree.InOrder();
    cout << "is 20 in the tree  : " << boolalpha << tree.Search(20) << "\n";
    cout << "is 200 in the tree : " << boolalpha << tree.Search(200) << "\n";
    cout << "Height of tree : " << tree.Height() << "\n";
    tree.Delete(20);
    tree.Delete(7);
    tree.Delete(10);
    tree.LevelOrder();
    tree.PreOrder();
    tree.PostOrder();
    tree.InOrder();
    cout << "Height of tree : " << tree.Height() << "\n";
}

/**
  *  @brief Node Constructor
  *
  *  @param      el      element to store in node
  */
template <class NodeType>
Node<NodeType> :: Node(NodeType el){
    data = el;
    left = right = nullptr;
}

/**
  *  @brief BinarySearchTree Constructor
  */
template <class TreeType>
BinarySearchTree<TreeType> :: BinarySearchTree(){
    root_ = nullptr;
}

/**
  *  @brief  Process all node at a level in left to right fashion
  */

template <class TreeType>
void BinarySearchTree<TreeType> :: LevelOrder(){
    if(!root_){ // empty tree case
        cout << "Tree is empty.\n" ;
        return;
    }
    queue<Node<TreeType> *> q; // queue that will store pointer of Node type
    q.push(root_);
    while(!q.empty()){
        cout << "\n";
        int size = q.size();
        while(size--){      // Process all node at the same level
            auto ptr = q.front();
            q.pop();
            // Process the node here
            // i'm just printing Node data (it is stupid, isn't it?)
            cout << ptr->data << " ";
            //push ptr child for processing in the next round
            if(ptr->left){
                q.push(ptr->left);
            }
            if(ptr->right){
                q.push(ptr->right);
            }
        }
    }
    cout << "\n";
}

/**
  * @brief   Wrapper for PreOrder(Node<NodeType> *root)
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: PreOrder(){
    cout << "PreOrder:\n";
    PreOrder(root_);
    cout << "\n";
}

/**
  * @brief      Process Node in preorder manner
  * @param      root    root of the tree
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: PreOrder(Node<TreeType> * root){
    if(root){
        cout << root->data << " "; // Process node here
        PreOrder(root->left);  // Process all node in left subtree
        PreOrder(root->right); // Process all node in right subtree
    }
}

/**
  * @brief   Wrapper for PostOrder(Node<NodeType> *root)
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: PostOrder(){
    cout << "PostOrder:\n";
    PostOrder(root_);
    cout << "\n";
}

/**
  * @brief      Process Node in postorder manner
  * @param      root    root of the tree
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: PostOrder(Node<TreeType> * root){
    if(root){
        PostOrder(root->left);  // Process all node in left subtree
        PostOrder(root->right); // Process all node in right subtree
        cout << root->data << " "; // Process node here
    }
}

/**
  * @brief   Wrapper for InOrder(Node<NodeType> *root)
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: InOrder(){
    cout << "InOrder:\n";
    InOrder(root_);
    cout << "\n";
}

/**
  * @brief      Process Node in inorder manner
  * @param      root    root of the tree
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: InOrder(Node<TreeType> * root){
    if(root){
        InOrder(root->left);  // Process all node in left subtree
        cout << root->data << " "; // Process node here
        InOrder(root->right); // Process all node in right subtree
    }
}

/**
  * @brief      Wrapper for Insert(Node<TreeType> *root, TreeType el)
  *
  * @param      el      The element to insert
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: Insert(TreeType el){
    if(!root_){
        root_ = new Node<TreeType>(el);
        return;
    }
    Insert(root_, el);
}

/**
  * @brief   insert new element el in the tree
  *
  * @param      el      The element to insert
  * @param      root    The root of the tree
  */
template <class TreeType>
void BinarySearchTree<TreeType> :: Insert(Node<TreeType> *root, TreeType el){
    // generate warning when user want to Insert
    // duplicate element
    if(root->data == el){
        cout << "Cann't Insert duplicate value\n";
        return;
    } else if (el < root->data){
        // if el is less then root->data, then Insert in left subtree
        if(root->left){    // further go deeper
            Insert(root->left, el);
        } else{ // found the right place to Insert
            root->left = new Node<TreeType>(el);
        }
    } else {
        // otherwise Insert into right subtree
        if(root->right){ // further go deeper
            Insert(root->right, el);
        } else{ // found the right place to Insert
            root->right = new Node<TreeType>(el);
        }
    }
}

/**
  *  @brief     return  True    when found el in tree
  *                     False   otherwise
  *  @param      el      element to Search for
  */
 template <class TreeType>
 bool BinarySearchTree<TreeType> :: Search(TreeType el) const{
    auto ptr = Search(root_, el);
    return  ptr != nullptr;
 }

/**
  * @brief   return pointer to at which el is present
  *          return nullptr  if element el is not present
  *
  * @param      el      element to Search for
  * @param      root    root of the tree
  */
template <class TreeType>
Node<TreeType>* BinarySearchTree<TreeType> :: Search(Node<TreeType> *root,
    TreeType el) const{

    if(!root){ // element el is not present in tree
        return nullptr;
    } else if(root->data < el){ // el may be present in right subtree
        return Search(root->right, el);
    } else if(root->data > el){ // el may be present in left subtree
        return Search(root->left, el);
    }
    //found the element el in the tree
    return root;
}
/**
  *  @brief  Search for node with minimum value
  *
  *  @return    Address of Node with min value
  *             otherwise nullptr
  *  @param     root    root of the tree
  */
template <class TreeType>
Node<TreeType> * BinarySearchTree<TreeType> :: MinNode(Node<TreeType> * root) const{

    if(!root){  // when tree is empty
        return nullptr;
    } else if(root->left){ // when there is left subtree, visit it
        MinNode(root->left);
    } else { // when root has no left subtree means it is MinNode
        return root;
    }
}

/**
  *  @brief  Search for node with maximum value
  *
  *  @return    Address of Node with max value
  *             otherwise nullptr
  *  @param     root    root of the tree
  */
template <class TreeType>
Node<TreeType> * BinarySearchTree<TreeType> :: MaxNode(Node<TreeType> * root) const{
    if(!root){  // when tree is empty
        return nullptr;
    } else if(root->right){ // when there is right subtree, visit it
        MinNode(root->right);
    } else { // when root has no right subtree means it is MaxNode
        return root;
    }
}


/**
  *  @brief     Wrapper for  Height(Node<TreeType> * root) const;
  */
template <class TreeType>
int BinarySearchTree<TreeType> ::  Height() const{
    return Height(root_);
}
/**
  *  @brief  Find the height of the tree
  *
  *  @return    integer value indicating height of the tree
  *  @param     root    root of the tree
  */
template <class TreeType>
int BinarySearchTree<TreeType> :: Height(Node<TreeType> * root) const{
    if(!root){ // when root is nullptr
        return 0;
    }

    // save height of left subtree
    int left_height = Height(root->left);
    // save height of right subtree
    int right_height = Height(root->right);

    // return max of left_height and right_height
    // + 1 for counting current level
    return max(left_height, right_height) + 1;
}

template <class TreeType>
void BinarySearchTree<TreeType> :: Delete(TreeType el){
    Delete(root_,el);
}

template <class TreeType>
Node<TreeType>* BinarySearchTree<TreeType> :: Delete(Node<TreeType> * root,TreeType el){
    if(!root){ // when there is no element el in tree
        return nullptr;
    } else if(root->data < el){ // means el is in right subtree
        root->right = Delete(root->right, el);
    } else if(root->data > el){ // means el is in left subtree
        root->left  = Delete(root->left, el);
    } else{ // found the el, now delete it
        if(root->left && root->right) { // delete node with two children
            auto successor = MinNode(root->right); // find the successor
            root->data = successor->data; // replace data with successor data
            root->right = Delete(root->right, root->data); //delete successor
        } else{
            auto temp = root; // make a copy of root for deleting node
            if(root->left){ // delete node with left child
                root = root->left; // save left child node before deleting node
            } else if(root->right){ // delete node with right child
                root = root->right;// save right child node before deleting node
            } else{ // delete node with no child
                root = nullptr; // return nullptr in this case
            }
        }
    }
    return root;
}
