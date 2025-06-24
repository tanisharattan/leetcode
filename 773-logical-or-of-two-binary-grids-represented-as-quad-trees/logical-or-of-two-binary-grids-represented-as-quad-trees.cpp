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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1 -> isLeaf)
        {
            if(quadTree1 -> val == 1) return quadTree1;
            return quadTree2;
        }
        if(quadTree2 -> isLeaf)
        {
            if(quadTree2 -> val == 1) return quadTree2;
            return quadTree1;
        }
        vector<Node*> arr;
        arr.push_back(intersect(quadTree1 -> topLeft, quadTree2 -> topLeft));
        arr.push_back(intersect(quadTree1 -> topRight, quadTree2 -> topRight));
        arr.push_back(intersect(quadTree1 -> bottomLeft, quadTree2 -> bottomLeft));
        arr.push_back(intersect(quadTree1 -> bottomRight, quadTree2 -> bottomRight));
        for(Node* node : arr)
        {
            if(!node -> isLeaf)
            {
                return new Node(
                    true, false,
                    arr[0], arr[1], arr[2], arr[3]
                );
            }
        }
        for(Node *node : arr)
        {
            if(!node -> val) return new Node(
                true, false,
                arr[0], arr[1], arr[2], arr[3]
            );
        }
        return new Node(true, true);
    }
};