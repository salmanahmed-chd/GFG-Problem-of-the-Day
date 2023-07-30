/*

Inorder Successor in BST

https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    
    void inorder(Node *root, Node *x, Node *&result, bool &visit){
        if(!root) return;
        
        inorder(root -> left, x, result, visit);
        
        if(visit){
            if(root -> data < result -> data && root -> data > x -> data){
                result = root;
            }
        }
        
        else{
            if(root -> data > x -> data){
                result = root;
                visit = true;
            }
        }
        
        inorder(root -> right, x, result, visit);
    }
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node *result = NULL;
        
        bool visit = false;
        
        inorder(root, x, result, visit);
        
        return result;
    }
};
