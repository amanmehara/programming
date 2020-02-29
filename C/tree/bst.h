typedef struct node_t {
    int key;
    struct node_t* parent;
    struct node_t* left;
    struct node_t* right;
    void* data;
} node_t;

typedef struct bst_t {
    node_t* root;
} bst_t;

node_t* create_node(int key, void* data);

void inorder_bst_walk(bst_t* bst);
node_t* bst_search(node_t* node, int key);
node_t* bst_maximum(node_t* node);
node_t* bst_minimum(node_t* node);
node_t* bst_predecessor(node_t* node);
node_t* bst_successor(node_t* node);
void bst_insert(bst_t* bst, node_t* node);