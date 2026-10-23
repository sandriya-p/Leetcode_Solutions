/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * Balances a Binary Search Tree (BST) to minimize its height
     * @param root The root node of the unbalanced BST
     * @return The root node of the balanced BST
     */
    TreeNode* balanceBST(TreeNode* root) {
        // Step 1: Perform in-order traversal to get sorted values
        inorderTraversal(root);
      
        // Step 2: Build a balanced BST from the sorted array
        return buildBalancedBST(0, sortedValues.size() - 1);
    }

private:
    // Vector to store node values in sorted order
    vector<int> sortedValues;

    /**
     * Performs in-order traversal of the BST to collect values in sorted order
     * @param node Current node being visited
     */
    void inorderTraversal(TreeNode* node) {
        // Base case: if node is null, return
        if (!node) {
            return;
        }
      
        // Traverse left subtree
        inorderTraversal(node->left);
      
        // Process current node - add value to sorted array
        sortedValues.push_back(node->val);
      
        // Traverse right subtree
        inorderTraversal(node->right);
    }

    /**
     * Builds a balanced BST from sorted array using divide-and-conquer approach
     * @param left Left boundary index of the current subarray
     * @param right Right boundary index of the current subarray
     * @return Root node of the balanced subtree
     */
    TreeNode* buildBalancedBST(int left, int right) {
        // Base case: invalid range
        if (left > right) {
            return nullptr;
        }
      
        // Find middle element to ensure balance
        int mid = left + (right - left) / 2;
      
        // Recursively build left subtree from left half
        TreeNode* leftSubtree = buildBalancedBST(left, mid - 1);
      
        // Recursively build right subtree from right half
        TreeNode* rightSubtree = buildBalancedBST(mid + 1, right);
      
        // Create root node with middle value and attach subtrees
        return new TreeNode(sortedValues[mid], leftSubtree, rightSubtree);
    }
};