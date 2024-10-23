/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(int n,int r,int c,vector<vector<int>>& grid){
        bool allsame=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[r][c]!=grid[r+i][c+j]) {
                    allsame=0;
                    break;
                }
            }
        }
        if(allsame){ //we have a leaf node now , BASE CASE
            return new Node(grid[r][c],1,NULL,NULL,NULL,NULL);
        }
        n/=2;
        Node* topleft = dfs(n,r,c,grid);
        Node* topright = dfs(n,r,c+n,grid);
        Node* bottomleft = dfs(n,r+n,c,grid);
        Node* bottomright = dfs(n,r+n,c+n,grid);
        return new Node(1,0,topleft,topright,bottomleft,bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid.size(),0,0,grid);
    }
};