#include "main.h"

Arbore* newNode(Node data){
    Arbore* node = (Arbore*)malloc(sizeof(Arbore));
    if(node == NULL)
        eroare_la_alocare();
    
    node->val = data.val;
    node->left = node->right = NULL;
    return node;
}

Arbore* insert(Arbore* node, Node key){
    if(node == NULL)
        return newNode(key);
    
    if(key.val.punctajTotal < node->val.punctajTotal)
        node->left = insert(node->left, key);
    else 
        if(key.val.punctajTotal > node->val.punctajTotal)
            node->right = insert(node->right, key);
    else 
        if(strcmp(key.val.Nume_echipa, node->val.Nume_echipa) < 0)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

    return node;
}