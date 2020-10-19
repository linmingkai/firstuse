#pragma once
#include<iostream>
using namespace std;
struct tree {
    int data;
    tree* left, * right;
};
class Btree
{
    static int n;
    static int m;
public: tree* root;
      Btree()
      {
          root = NULL;
      }
      void create_Btree(int);
      void preOrder(tree*);//先序遍历
      void inOrder(tree*);//中序遍历
      void postOrder(tree*);//后序遍历
      int count(tree*);//计算二叉树的个数
      int findLeaf(tree*);//求二叉树叶子的个数
      int findNode(tree*);//求二叉树中度数为1的结点数量
};

int Btree::n = 0;
int Btree::m = 0;
void Btree::create_Btree(int x) {
    tree* newNode = new tree;
    newNode->data = x;
    newNode->right = newNode->left = NULL;
    if (root == NULL)
        root = newNode;
    else {
        tree* back;
        tree* current = root;
        while (current != NULL) {
            back = current;
            if (current->data > x)
                current = current->left;
            else
                current = current->right;
        }
        if (back->data > x)
            back->left = newNode;
        else
            back->right = newNode;
    }
}
//计算二叉树的个数
int Btree::count(tree* p)
{
    if (p == NULL)
        return 0;
    else
        return count(p->left) + count(p->right) + 1;
}
//先序遍历二叉树
void Btree::preOrder(tree* temp) {
    if (temp != NULL) {
        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}
//中序遍历二叉树
void Btree::inOrder(tree* temp) {
    if (temp != NULL) {
        inOrder(temp->left);
        cout << temp->data << " ";
        inOrder(temp->right);
    }
}
//后序遍历二叉树
void Btree::postOrder(tree* temp) {
    if (temp != NULL) {
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << " ";
    }
}
//统计叶子的数量
int Btree::findLeaf(tree* temp) {
    if (temp == NULL)
        return 0;
    else {
        if (temp->left == NULL && temp->right == NULL)
            return n += 1;
        else {
            findLeaf(temp->left);
            findLeaf(temp->right);
        }
    }
}
//二叉树中度数为1的结点数量
int Btree::findNode(tree* temp) {
    if (temp == NULL)
        return 0;
    else {
        if (temp->left != NULL && temp->right != NULL)
        {
            findNode(temp->left);
            findNode(temp->right);
        }
        if (temp->left != NULL && temp->right == NULL)
        {
            m += 1;
            findNode(temp->left);
        }
        if (temp->left == NULL && temp->right != NULL)
        {
            m += 1;
            findNode(temp->right);
        }
    }
    return m;
}
int main()
{
    Btree bin;
    int array[] = { 7,4,2,3,15,35,6,45,55,20,1,14,56,57,58 };
    int k;
    k = sizeof(array) / sizeof(array[0]);
    cout << "建立排序二叉树顺序：" << endl;
    for (int i = 0;i < k;i++) {
        cout << array[i] << " ";
        bin.create_Btree(array[i]);
    }
    cout << endl;
    cout << "二叉树节点个数： " << bin.count(bin.root) << endl;
    cout << "二叉树叶子个数：" << bin.findLeaf(bin.root) << endl;
    cout << "二叉树中度数为1的结点的数量为：" << bin.findNode(bin.root) << endl;
    cout << endl << "先序遍历序列: " << endl;
    bin.preOrder(bin.root);
    cout << endl;
    cout << endl << "中序遍历序列: " << endl;
    bin.inOrder(bin.root);
    cout << endl << "后序遍历序列: " << endl;
    bin.postOrder(bin.root);
}
