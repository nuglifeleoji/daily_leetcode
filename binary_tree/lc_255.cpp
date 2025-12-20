class Solution {
    public:
        int index=0;
        bool verifyPreorder(vector<int>& preorder) {
            return check(preorder, INT_MIN, INT_MAX);
        }
        bool check(vector<int> & preorder,int min, int max){
            if(index==preorder.size()) return true;
            int rootval=preorder[index];
            if(rootval<=min) return false;
            if(rootval>=max) return true;
            index++;
            return check(preorder, min, rootval) && check(preorder, rootval, max);
        }
    };