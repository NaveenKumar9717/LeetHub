/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
//           cloneGraphH(Node* node,Node* head){
//               if(head == NULL){
                  
//               }
//               Node* newnode = new Node(node->val);
//               for(int i =  ;i < node->neighbours.size();i++){
//                   newnode->neighbours.push_back(node->node->neighbours[i]);
//               }
//               last_node->neighbours.push_back(newnode);
//                 for(int i =  ;i < newnode->neighbours.size();i++){
//                     if(visited[neighbours[i]->val] == 0){
//                       cloneGraphH(newnode->neighbours[i],newnode);
//                                           }
                
//           }
                                          
//     }
//                                           }
    Node* cloneGraph(Node* node) {
       if (!node) {
            return NULL;
        }
        Node* copy = new Node(node -> val, {});
        copies[node] = copy;
        queue<Node*> todo;
        todo.push(node);
        while (!todo.empty()) {
            Node* cur = todo.front();
            todo.pop();
            for (Node* neighbor : cur -> neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor -> val, {});
                    todo.push(neighbor);
                }
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
    private:
    unordered_map<Node*, Node*> copies;
};