#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
}*HEADER;
int deleteAll() {
	struct node *ptr = HEADER, *prevPtr;
	while (ptr != NULL) {
		prevPtr = ptr;
		ptr = ptr->next;
		free(prevPtr);
	}
	HEADER->next = NULL;
	return (0);
}
struct node *newNode() {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow");
		deleteAll();
		exit(0);
	}
	return (newptr);
}
void inorder(struct node *root) {
  if (root->left != NULL) {
    inorder(root->left);
  }
  printf(" %d", root->data);
  if (root->right != NULL) {
    inorder(root->right);
  }
}
int search(struct node *root, int key) {
  int index;
  if (root->data == key) return root;
  if (root->left != NULL) {
    index = search(root->left, key);
    if (index != NULL) {
      return index;
    }
  }
  if (root->right != NULL) {
    index = search(root->right, key);
    if (index != NULL) {
      return index;
    }
  }
  return NULL;
}
struct node* createNode(int data) {
  struct node newNode = malloc(sizeof(struct node));
  if (newNode == NULL) {
    printf("Memory overflow");
    deleteAll();
    exit();
  }
  newNode->right = NULL;
  newNode->left = NULL;
  newNode->data = data;
  return newNode;
}
void insert() {
  int data, key;
  struct node *parent, newNode;
  char choice;
  struct node parent=search(ROOT, key);
  if (ROOT = NULL) {
    printf("Enter data to be inserted : ");
    scanf("%d", &data);
    ROOT = createNode(data);
    printf("Successfully inserted\n")
  } else {
    printf("Enter data of the parent node : ");
    scanf("%d", &key);
    parent = search(key);
    if (parent == NULL) {
      printf("Parent node not found. Deletion failed\n");
    } else {
      printf("Enter data to be inserted : ");
      scanf("%d", &data);
      printf("Enter which child to be inserted at (L/R) : ");
      scanf("%d", &choice);
      switch(choice) {
        case 'l':
        case 'L':
          newNode = createNode(data);
          parent->left = newNode;
          printf("Succesfully inserted\n");
          break;
        case 'r':
        case 'R':
          newNode = createNode(data);
          parent->right = newNode;
          printf("Succesfully inserted\n");
          break;
        default:
          printf("Invalid choice\n");
      }
    }
  }
}
void delete() {
  int key;
  struct node *toMove, *toDelete;
  printf("Enter data of the node to be deleted : ");
  scanf("%d", &key);
  toDelete = search(key);
  if (toDelete == NULL) {
    printf("Node not found\n");
  } else {

  }
}