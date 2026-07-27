#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return create(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void search(struct Node* root, int val) {
    if (root == NULL) {
        printf(" -> NULL (Not Found)\n");
        return;
    }
    printf(" -> Checking %d", root->data);
    if (root->data == val) {
        printf(" (FOUND!)\n");
        return;
    }
    if (val < root->data) {
        printf(" [Go Left]");
        search(root->left, val);
    } else {
        printf(" [Go Right]");
        search(root->right, val);
    }
}

void display(struct Node* root) {
    if (root == NULL) return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n1.Insert  2.Search  3.Display  4.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            root = insert(root, val);
        } else if (choice == 2) {
            printf("Search for: ");
            scanf("%d", &val);
            printf("Path:");
            search(root, val);
        } else if (choice == 3) {
            printf("Tree elements: ");
            display(root);
            printf("\n");
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

