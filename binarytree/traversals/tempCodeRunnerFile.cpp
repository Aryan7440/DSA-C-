Node *root = new Node(12);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->left->left = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->left->left = new Node(9);
    root->left->right->left->left->right = new Node(89);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(10);
    root->left->right->right->right->left = new Node(11);
    root->left->right->right->right->left->right = new Node(12);