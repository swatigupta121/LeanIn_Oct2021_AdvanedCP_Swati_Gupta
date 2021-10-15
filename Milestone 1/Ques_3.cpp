class Solution
{
private:

public:
void down(Node* root,int k,vector<int> &ans){
        if(root==nullptr)
            return ;
        if(k==0){
            ans.push_back(root->data);
            return;
        }
        down(root->left,k-1,ans);
        down(root->right,k-1,ans);
    }
    int solve(Node* root,int tar,int k,vector<int> &ans){
        if(root==nullptr)
            return -1;
        if(root->data==tar){
            down(root,k,ans);
            return 0;
        }
        int l = solve(root->left,tar,k,ans);
        if(l!=-1){
            if(l+1==k){
                ans.push_back(root->data);
            }else{
                down(root->right,k-l-2,ans);
            }
            return l+1;
        }
        
        int r = solve(root->right,tar,k,ans);
        if(r!=-1){
            if(r+1==k){
                ans.push_back(root->data);
            }else{
                down(root->left,k-r-2,ans);
            }
            return r+1;
        }
        return -1;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;
        solve(root,target,k,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
