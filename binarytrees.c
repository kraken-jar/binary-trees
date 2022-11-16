int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
  
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


int identicalTrees(struct node* a, struct node* b)
{
    /*1. both empty */
    if (a == NULL && b == NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL) {
        return (a->data == b->data
                && identicalTrees(a->left, b->left)
                && identicalTrees(a->right, b->right));
    }
 
    /* 3. one empty, one not -> false */
    return 0;
}


void mirror(struct Node* node)
{
    if (node == NULL)
        return;
    else {
        struct Node* temp;
 
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
 
        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}


bool isMirror(Node* root1, Node* root2)
{
    // If both trees are empty, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 && root2 && root1->key == root2->key)
        return isMirror(root1->left, root2->right)
               && isMirror(root1->right, root2->left);
    return false;
}
