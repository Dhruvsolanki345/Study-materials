/*
Write a program for following operations on Binary Search Tree using Doubly Linked List (DLL).
1)	Create empty BST,
2)	Insert a new element on the BST
3)	Search for an element on the BST
4)	Delete an element from the BST
5)	Display all elements of the BST

*/
#include <stdio.h>
#include<stdlib.h>

typedef struct BST {
    int data;
    struct BST *left,*right;
}node;

node *root;

void createBST(){
    root = NULL;
}

void insert(int data){
    node *a, *b = NULL;

    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->left = new->right = NULL;

    a = root;
    while(a != NULL){
        b = a;
        if(data < a->data)
            a = a->left;
        else
            a = a->right;
    }
    if(b == NULL)
        root = new;
    else if(data < b->data)
        b->left = new;
    else
        b->right = new;

    printf("\nNew element inserted");
}

node *search(int data){
    node *a = root;
    while(a != NULL && data != a->data){
        if(data < a->data)
            a = a->left;
        else
            a = a->right;
    }
    return a;
}

int *delete(int data)
{
    node *a = root, *b = root, *old = NULL;
    int result, *ptr = NULL;
    while(a != NULL && data != a->data){
        b = a;
        if(data < a->data)
            a = a->left;
        else
            a = a->right;
    }
    if(data == a->data){
        result = a->data;
        ptr = &result;
        if(a->left != NULL && a->right == NULL){
            if(a == b)
                root=a->left;
            else if(b->left == a)
                b->left=a->left;
            else
                b->right=a->left;
        }
        else if(a->left == NULL && a->right != NULL){
            if(a == b)
                root=a->right;
            else if(b->left == a)
                b->left=a->right;
            else
                b->right=a->right;
        }
        else if(a->left != NULL && a->right != NULL){
            old=a->right;
            while(old->left != NULL)
                old=old->left;

            old->left=a->left;
            if(a == b)
                root=a->right;
            else if(b->left == a)
                b->left=a->right;
            else
                b->right=a->right;
        }
        else if(a->left == NULL && a->right == NULL){
            if(a == b)
                root=NULL;
            else if(b->left == a)
                b->left=NULL;
            else
                b->right=NULL;
        }
        free(a);
    }

    return ptr;
}

node *getParent(int data){
    node *a = root, *b = NULL;
    while(a != NULL && data != a->data){
        b = a;
        if(data < a->data)
            a = a->left;
        else
            a = a->right;
    }
    return b;
}

void DisplayInorder(node *a){
    if(a == NULL)
        return;

    DisplayInorder(a->left);
    printf("%d ",a->data);
    DisplayInorder(a->right);
}

int main()
{
    int data, flag = 0, *ptr;
    node *t;
    createBST();

    while(flag != 6){
        printf("\n1. Insert a new element");
        printf("\n2. Search for a specified element");
        printf("\n3. Delete");
        printf("\n4. Parent element details");
        printf("\n5. Display all elements in Inorder form");
        printf("\n6. Quit");
        printf("\nEnter your choice: ");
        scanf("%d",&flag);

        switch(flag){
            case 1:
                printf("\nInput a number: ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                printf("\nInput a number: ");
                scanf("%d",&data);
                if((t = search(data)) != NULL)
                    printf("\nIn BST, element with value %d is present",t->data);
                else
                    printf("\nNo element present in BST");
                break;
            case 3:
                printf("\nInput a number: ");
                scanf("%d",&data);
                if((ptr = delete(data)) != NULL)
                    printf("\nElement with value %d has been deleted from BST",*ptr);
                else
                    printf("\nNo element present to delete");
                break;
            case 4:
                printf("\nInput a number: ");
                scanf("%d",&data);
                if((t = getParent(data)) != NULL)
                    printf("\nValue of parent element is %d",t->data);
                else
                    printf("\nElement not present");
                break;
            case 5:
                DisplayInorder(root);
                break;
            case 6:
                printf("\n------------------Bye!!-------------------");
                return 0;
            default:
                printf("\nInput is invalid");
        }
    }

    return 0;
}



