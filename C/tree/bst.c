#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

node_t* create_node(int key, void* data)
{
    node_t* node = malloc(sizeof(node_t));
    node->key = key;
    node->data = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void _inorder_bst_walk(node_t* node)
{
    if (node != NULL) {
        _inorder_bst_walk(node->left);
        printf("%d\n", node->key);
        _inorder_bst_walk(node->right);
    }
}

void inorder_bst_walk(bst_t* bst) { _inorder_bst_walk(bst->root); }

node_t* bst_search(node_t* node, int key)
{
    while (node != NULL && key != node->key) {
        if (key < node->key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return node;
}

node_t* bst_maximum(node_t* node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->right != NULL) {
        node = node->right;
    }
    return node->right;
}

node_t* bst_minimum(node_t* node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

node_t* bst_predecessor(node_t* node)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->left != NULL) {
        return bst_maximum(node->left);
    }
    node_t* t = node->parent;
    while (t != NULL && node == t->left) {
        node = t;
        t = t->parent;
    }
    return t;
}

node_t* bst_successor(node_t* node)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->right != NULL) {
        return bst_minimum(node->right);
    }
    node_t* t = node->parent;
    while (t != NULL && node == t->right) {
        node = t;
        t = t->parent;
    }
    return t;
}

void bst_insert(bst_t* bst, node_t* node)
{
    if (node == NULL) {
        return;
    }
    node_t* p = NULL;
    node_t* t = bst->root;
    while (t != NULL) {
        p = t;
        if (node->key < t->key) {
            t = t->left;
        }
        else {
            t = t->right;
        }
    }
    node->parent = p;
    if (p == NULL) {
        bst->root = node;
    }
    else if (node->key < p->key) {
        p->left = node;
    }
    else {
        p->right = node;
    }
}