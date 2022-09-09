    #pragma once
    using namespace std;
    class Tree {
    public:
        struct node {
            int value;
            node* left;
            node* right;
            int height;
        };

        enum type_obj_tree { OBJ_LEFT, OBJ_RIGHT };
        enum type_order_tree { PREORDER, INORDER, POSTORDER };

        node* root = NULL;
        int countObj = 0;
    };

    class BinaryTree : public Tree {
    protected:
        node* insertElement(int element, node* tree) {
            if (tree == NULL) {
                tree = new node;
                tree->value = element;
                tree->left = tree->right = NULL;

                countObj++;
            }
            else if (element < tree->value) tree->left = insertElement(element, tree->left);
            else if (element > tree->value) tree->right = insertElement(element, tree->right);

            if (getHeight() > 6) {
                remove(element);
                return tree;
            } else {
                return tree;
            }
        }


        node* find(node* tree, int element) {
            if (tree == NULL) return NULL;
            else if (element < tree->value) return find(tree->left, element);
            else if (element > tree->value) return find(tree->right, element);
            else {
                return tree;
                //tree->isSelect = true;
                //OutputDebugString((LPCWSTR)tree->height);
                //return tree->height;
            }
        }


        node* removeElement(int element, node* tree) {
            node* temp;
            if (tree == NULL) return NULL;
            else if (element < tree->value) tree->left = removeElement(element, tree->left);
            else if (element > tree->value) tree->right = removeElement(element, tree->right);
            else if (tree->left && tree->right) {
                temp = findMin(tree->right);
                tree->value = temp->value;
                tree->right = removeElement(tree->value, tree->right);
            }
            else {
                temp = tree;
                if (tree->left == NULL) tree = tree->right;
                else if (tree->right == NULL) tree = tree->left;
                delete temp;
                countObj--;
            }
            return tree;
        }


        void printTree(node* tree, int p) {
            if (tree != NULL) {
                printTree(tree->right, p + 3);
                for (int i = 0; i < p; i++)
                {
                    cout << " ";
                }
                printf("%3d\n", tree->value);
                printTree(tree->left, p + 3);
            }
        }



        // Обход дерева
        void preorder(node* tree, std::vector<int>& vector) {
            if (tree == NULL) return;
            vector.push_back(tree->value);
            //cout << tree->value << " ";
            preorder(tree->left, vector);
            preorder(tree->right, vector);
        }

        void inorder(node* tree, std::vector<int>& vector) {
            if (tree == NULL) return;
            inorder(tree->left, vector);
            vector.push_back(tree->value);
            //cout << tree->value << " ";
            inorder(tree->right, vector);
        }

        void postorder(node* tree, std::vector<int>& vector) {
            if (tree == NULL) return;
            postorder(tree->left, vector);
            postorder(tree->right, vector);
            vector.push_back(tree->value);
            //cout << tree->value << " ";
        }



        node* findMin(node* tree) {
            if (tree == NULL) return NULL;
            else if (tree->left == NULL) return tree;
            else return findMin(tree->left);
        }

        node* findMax(node* tree) {
            if (tree == NULL) return NULL;
            else if (tree->right == NULL) return tree;
            else return findMax(tree->right);
        }


        int getHeightTree(node* tree) {
            if (tree == NULL) return 0;

            int left, right;
            if (tree->left != NULL) left = getHeightTree(tree->left);
            else left = -1;
            if (tree->right != NULL) right = getHeightTree(tree->right);
            else right = -1;
            int max = left > right ? left : right;
            return max + 1;
        }

        void getCurrentLevel(node* tree, int level, std::vector<int>& vector, std::vector<int>& vectorIndex, int index) {
            if (tree == NULL) return;

            if (level == 0) {
                vector.push_back(tree->value);
                vectorIndex.push_back(index);
            } else {
                getCurrentLevel(tree->left, level - 1, vector, vectorIndex, index*2);
                getCurrentLevel(tree->right, level - 1, vector, vectorIndex, (index*2)+1);
            }
        }

        bool Symmetry(node* objLeft, node* objRight)
        {
            if (root == NULL) return false;
            if (objLeft == NULL && objRight == NULL) return false;
            if (objLeft == NULL || objRight == NULL) return true;
            if (countObj == 1) return true;

            return((objLeft->value == objRight->value) && Symmetry(objLeft->left, objRight->right) && Symmetry(objLeft->right, objRight->left));
        }



        node* makeEmpty(node* tree) {
            if (tree == NULL) return NULL;

            makeEmpty(tree->left);
            makeEmpty(tree->right);
            delete tree;
            countObj = 0;
            return NULL;
        }

    public:
        // Конструктор бинарного дерева
        BinaryTree() {
            root = NULL;
        }

        // Деструктор бинарного дерева
        ~BinaryTree() {
            root = makeEmpty(root);
        }



        void insert(int element) {
            root = insertElement(element, root);
        }

        void search(int element, std::vector<int>& vector) {
            std::vector<int> currentLevel;
            std::vector<int> vIndex;
            Int16 currentElement;
            Int16 currentIndex;
            currentLevel.push_back(-1);
            vIndex.push_back(0);

            for (int i = 0; i <= 6; i++) { // Levels
                currentLevel.clear();
                vIndex.clear();
                getLevel(i, currentLevel, vIndex);

                for (int j = 0; j <= pow(2, i) - 1; j++) {
                    if (!currentLevel.empty()) {
                        currentElement = *currentLevel.data();
                        currentIndex = *vIndex.data();
                        if (currentElement == element) {
                            vector.push_back(i+1);
                            vector.push_back(j+1);
                        }
                        currentLevel.erase(currentLevel.begin());
                        vIndex.erase(vIndex.begin());
                    }
                }
                currentLevel.clear();
            }
            if(vector.empty()) vector.push_back(0); vector.push_back(0);
            //root = find(root, element);
        }

        void remove(int element) {
            root = removeElement(element, root);
        }

        void print() {
            printTree(root, 0);
            cout << endl;
        }

        void display(type_order_tree order, std::vector<int>& vector) {
            switch (order) {
            case PREORDER: preorder(root, vector); break;
            case INORDER: inorder(root, vector); break;
            case POSTORDER: postorder(root, vector); break;
            }
            cout << endl;
        }

        void empty() {
            root = makeEmpty(root);
        }



        int getCount() { return countObj; }
        void getLevel(int level, std::vector<int>& vector, std::vector<int>& vectorIndex) { getCurrentLevel(root, level, vector, vectorIndex, 0); }

        int getHeight() { return getHeightTree(root) + 1; }
        bool isSymmetry() { return Symmetry(root, root); }
    };

    class AVLTree : public BinaryTree {
    protected:
        node* insertElement(int element, node* tree) {
            if (tree == NULL) {
                tree = new node;
                tree->value = element;
                tree->height = 0;
                tree->left = tree->right = NULL;
                countObj++;
            }
            else if (element < tree->value) {
                tree->left = AVLTree::insertElement(element, tree->left);
                if (height(tree->left) - height(tree->right) == 2) {
                    if (element < tree->left->value)
                        tree = singleRightRotate(tree);
                    else
                        tree = doubleRightRotate(tree);
                }
            }
            else if (element > tree->value) {
                tree->right = AVLTree::insertElement(element, tree->right);
                if (height(tree->right) - height(tree->left) == 2) {
                    if (element > tree->right->value)
                        tree = singleLeftRotate(tree);
                    else
                        tree = doubleLeftRotate(tree);
                }
            }

            tree->height = max(height(tree->left), height(tree->right)) + 1;
            return tree;
            
            if (getHeight() > 6) {
                remove(element);
                return tree;
            } else {
                return tree;
            }
        }

        node* removeElement(int element, node* tree) {
            if (tree == NULL) return NULL;
            if (element < tree->value) {
                tree->left = removeElement(element, tree->left);
            } else if (element > tree->value) {
                tree->right = removeElement(element, tree->right);
            } else {
                node* r = tree->right;
                if (tree->right == NULL) {
                    node* l = tree->left;
                    countObj--;
                    delete(tree);
                    tree = l;
                } else if (tree->left == NULL) {
                    countObj--;
                    delete(tree);
                    tree = r;
                } else {
                    while (r->left != NULL) r = r->left;
                    tree->value = r->value;
                    tree->right = removeElement(r->value, tree->right);
                }
            }
            if (tree == NULL) return tree;
            tree->height = 1 + max(height(tree->left), height(tree->right));
            int bal = height(tree->left) - height(tree->right);
            if (bal > 1) {
                if (height(tree->left) >= height(tree->right)) {
                    return singleRightRotate(tree);
                }
                else {
                    tree->left = singleLeftRotate(tree->left);
                    return singleRightRotate(tree);
                }
            }
            else if (bal < -1) {
                if (height(tree->right) >= height(tree->left)) {
                    return singleLeftRotate(tree);
                }
                else {
                    tree->right = singleRightRotate(tree->right);
                    return singleLeftRotate(tree);
                }
            }
            return tree;
        }



        node* singleRightRotate(node*& tree)
        {
            if (tree->left != NULL) {
                node* u = tree->left;
                tree->left = u->right;
                u->right = tree;
                tree->height = max(height(tree->left), height(tree->right)) + 1;
                u->height = max(height(u->left), tree->height) + 1;
                return u;
            }
            return tree;
        }

        node* singleLeftRotate(node*& tree) {
            if (tree->right != NULL) {
                node* u = tree->right;
                tree->right = u->left;
                u->left = tree;
                tree->height = max(height(tree->left), height(tree->right)) + 1;
                u->height = max(height(tree->right), tree->height) + 1;
                return u;
            }
            return tree;
        }

        node* doubleLeftRotate(node*& tree) {
            tree->right = singleRightRotate(tree->right);
            return singleLeftRotate(tree);
        }

        node* doubleRightRotate(node*& tree) {
            tree->left = singleLeftRotate(tree->left);
            return singleRightRotate(tree);
        }



        int height(node* tree) {
            return (tree == NULL ? -1 : tree->height);
        }

        int getBalance(node* tree) {
            if (tree == NULL) return 0;
            else return height(tree->left) - height(tree->right);
        }
    public:
        // Конструктор AVL дерева
        AVLTree() {
            root = NULL;
        }

        // Деструктор AVL дерева
        ~AVLTree() {
            root = makeEmpty(root);
        }


        void insert(int element) {
            root = AVLTree::insertElement(element, root);
        }

        void remove(int element) {
            root = AVLTree::removeElement(element, root);
        }


        int getHeight() { return getHeightTree(root) + 1; }
    };