Kth Ancestor in a Tree

https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

void solve(Node *root, int node, stack<Node*>& st, stack<Node*>& ans) {
    if (root == NULL) return;

    if (root->data == node) {
        ans = st;
        return;
    }

    st.push(root);
    if (root->left) solve(root->left, node, st, ans);
    if (root->right) solve(root->right, node, st, ans);

    st.pop();
}


int kthAncestor(Node *root, int k, int node)
{
    stack<Node*> st;
    stack<Node*> ans;

    solve(root, node, st, ans);

    if (ans.size() < k) return -1;

    while (k > 1) {
        ans.pop();
        k--;
    }

    return ans.top() -> data;
}
