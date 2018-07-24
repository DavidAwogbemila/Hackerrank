#include <iostream>
#include <string>

using namespace std;

int maxval(Node* root) {
        int ans;
        if (root->left == NULL && root->right == NULL) {
            return root->data;
        }
        if (root->left != NULL && root->right != NULL) {
            int lmax = maxval(root->left);
            int rmax = maxval(root->right);
            ans = lmax > rmax ? lmax : rmax;
            ans = ans > root->data ? ans : root->data;
        } else if (root->left != NULL) {
            int val = maxval(root->left);
            ans = val > root->data ? val : root->data ;
        } else if (root->right != NULL) {
            int val = maxval(root->right);
            ans =  val > root->data ? val : root->data ;
        }
        //cout << "returning" << ans << "as the max value" << endl;
        return ans;
    }

int minval(Node* root) {
       int ans;
        if (root->left == NULL && root->right == NULL) {
            return root->data;
        }
        if (root->left != NULL && root->right != NULL) {
            int lmin = minval(root->left);
            int rmin = minval(root->right);
            ans = lmin < rmin ? lmin : rmin;
            ans = ans < root->data ? ans : root->data;
        } else if (root->left != NULL) {
            int val = minval(root->left);
            ans = val < root->data ? val : root->data ;
        } else if (root->right == NULL) {
            int val = minval(root->right);
            ans =  val < root->data ? val : root->data ;
        }
        //cout << "returning" << ans << "as the min value" << endl;
        return ans;
    }

	bool checkBST(Node* root) {
        bool leftOk= false, rightOk = false;
		if (root == NULL) return true;
        if (root->left && root->data > maxval(root->left)) {
            //cout << "checking left.." << endl;
            leftOk = checkBST(root->left);
        } else if (!root->left) {
            leftOk = true;
        }
        if (root->right && root->data < minval(root->right)) {
            rightOk = checkBST(root->right);
        } else if (!root->right) {
            rightOk = true;
        }
        return leftOk && rightOk;   
	}
