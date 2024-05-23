#include "main.h"

Arbore* newNode(Echipa data){
    Arbore* node = (Arbore*)malloc(sizeof(Arbore));
    if(node == NULL)
        eroare_la_alocare();
    
    node->val = data;
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

Arbore* insertBST(Arbore* node, Echipa key){
    if(node == NULL)
        return newNode(key);
    
    if(key.punctajTotal < node->val.punctajTotal)
        node->left = insertBST(node->left, key);
    else 
        if(key.punctajTotal > node->val.punctajTotal)
            node->right = insertBST(node->right, key);
    else 
        if(strcmp(key.Nume_echipa, node->val.Nume_echipa) < 0)
            node->left = insertBST(node->left, key);
        else
            node->right = insertBST(node->right, key);

    return node;
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int nodeHeight(Arbore *root){
    if(root == NULL)
        return -1;
    else
        return root->height;
}

Arbore* RightRotation(Arbore *z){
    Arbore *y = z->left;
    Arbore *T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right))+1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right))+1;

    return y;
}

Arbore* LeftRotation(Arbore *z){
    Arbore *y = z->right;
    Arbore *T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = max(nodeHeight(z->left), nodeHeight(z->right))+1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right))+1;

    return y;
}

Arbore* LRRotation(Arbore *Z){
    Z->left = LeftRotation(Z->left);
    return RightRotation(Z);
}

Arbore* RLRotation(Arbore *Z){
    Z->right = RightRotation(Z->right);
    return LeftRotation(Z);
}

Arbore* insertAVL(Arbore* node, Echipa key){
    if(node == NULL)
        return newNode(key);
    
    if(key.punctajTotal < node->val.punctajTotal)
        node->left = insertAVL(node->left, key);
    else 
        if(key.punctajTotal > node->val.punctajTotal)
            node->right = insertAVL(node->right, key);
    else 
        if(strcmp(key.Nume_echipa, node->val.Nume_echipa) < 0)
            node->left = insertAVL(node->left, key);
        else
            node->right = insertAVL(node->right, key);

    node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));

    int k = (nodeHeight(node->left) - nodeHeight(node->right));

    if(k > 1){
        if(key.punctajTotal < node->left->val.punctajTotal)
            return RightRotation(node);
        else if(key.punctajTotal == node->left->val.punctajTotal)
            if(strcmp(key.Nume_echipa, node->left->val.Nume_echipa) < 0)
                return RightRotation(node);
            else
                return LeftRotation(node);
    }

    if(k < -1){
        if(key.punctajTotal > node->right->val.punctajTotal)
            return LeftRotation(node);
        else if(key.punctajTotal == node->right->val.punctajTotal)
            if(strcmp(key.Nume_echipa, node->right->val.Nume_echipa) > 0)
                return LeftRotation(node);
            else
                return RightRotation(node);
    }

    if(k > 1 && key.punctajTotal > node->left->val.punctajTotal)
        return LRRotation(node);
    if(k < -1 && key.punctajTotal < node->right->val.punctajTotal)
        return RLRotation(node);

    return node;
}