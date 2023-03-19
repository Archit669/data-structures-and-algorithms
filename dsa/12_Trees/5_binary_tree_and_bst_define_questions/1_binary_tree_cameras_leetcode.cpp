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
class Solution
{
    // // function that will count all the cameras and return whether it is covered or not and it has camera or not
    // first bool will tell that node has camera or not
    // second bool will tell that node is covered or not
    pair<bool, bool> dfs(TreeNode *root, int &camera_count)
    {
        // base case when root is null , so we assume that they are covered and they have no camera
        if (root == nullptr)
        {
            return {false, true};
        }

        // now find soln for left subtree and right subtree
        pair<bool, bool> left_subtree = dfs(root->left, camera_count);
        pair<bool, bool> right_subtree = dfs(root->right, camera_count);

        // check whether root should have camera or not
        // logic is that if it's none of child are not covered then it should have camera
        bool has_camera = !left_subtree.second || !right_subtree.second;

        // if there is need to insert camera at root then increment camera count
        if (has_camera == true)
        {
            camera_count++;
        }

        // check whether root is covered or not
        bool is_covered = left_subtree.first || right_subtree.first || has_camera;

        // return that root has camera or not and it is covered or not
        return {has_camera, is_covered};
    }

public:
    int minCameraCover(TreeNode *root)
    {
        // variable for count of no of cameras
        int camera_count = 0;

        // function call that will count all the cameras and return whether it is covered or not and it has camera or not
        auto ans = dfs(root, camera_count);

        // if (root is not covered) as it can be leaf node
        if (ans.second == false)
        {
            // it should has camera
            camera_count++;
        }

        // return ans
        return camera_count;
    }
};