/*
 * @title BinaryTrie
 * @docs md/12-binary-search-tree/SimpleBinaryTrie.md
 */
template<size_t bit_length=20> class SimpleBinaryTrie {
    using u32 = unsigned int;
    struct Node {
        Node *left, *right;
        u32 size;
        Node(): size(0) {left=right=nullptr;}
    };
    Node* root;
    u32 size(Node* node) const {return (node==nullptr ? 0 : node->size);}
    u32 empty(Node* node) const {return size(node) == 0;}
public:
    SimpleBinaryTrie(): root(new Node) {}
    void insert(const u32 val) {
        Node* curr = root;
        stack<Node*> st;
        for(u32 i=0; i < bit_length; ++i) {
            u32 j = ((val>>(bit_length-1-i)) & 1);
            st.push(curr);
            if(j) {
                if(curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    Node* next = new Node();
                    curr->right = next;
                    curr = next;
                }
            }
            else {
                if(curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    Node* next = new Node();
                    curr->left = next;
                    curr = next;
                }
            }
        }
        curr->size += 1;
        while(st.size()) {
            auto node=st.top(); st.pop();
            node->size = size(node->left) + size(node->right);
        }
    }
    void erase(const u32 val) {
        Node* curr = root;
        stack<Node*> st;
        for(u32 i=0; i < bit_length; ++i) {
            u32 j = ((val>>(bit_length-1-i)) & 1);
            st.push(curr);
            if(j) {
                if(curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    return;
                }
            }
            else {
                if(curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    return;
                }
            }
        }
        if(empty(curr)) return;
        curr->size -= 1;
        while(st.size()) {
            auto node=st.top(); st.pop();
            node->size = size(node->left) + size(node->right);
        }
    }
    u32 size() const {return size(root);}
    u32 kth_smallest(u32 k) {
        Node* curr = root;
        u32 val=0;
        for(u32 i=0; i < bit_length; ++i) {
            u32 j = 1U << (bit_length-1-i);
            u32 sz_l = size(curr->left);
            if(k<sz_l) {
                curr = curr->left;
            }
            else {
                val |= j;
                k -= sz_l;
                curr = curr->right;
            }
        }
        return val;
    }
    u32 lower_bound(const u32 val) {
        Node* curr = root;
        u32 k=0;
        for(u32 i=0; i < bit_length; ++i) {
            u32 j = ((val>>(bit_length-1-i)) & 1);
            if(j) {
                k+=size(curr->left);
                if(curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    return k;
                }
            }
            else {
                if(curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    return k;
                }
            }
        }
        return val;
    }
};