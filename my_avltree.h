#ifndef MYAVLTREE_H
#define MYAVLTREE_H

#include <iostream>

using namespace std;

struct avlTreeNode{
    int data;
    int deepin = 1;
    avlTreeNode* left;
    avlTreeNode* right;
};

class MyAVLTree{
public:
    MyAVLTree(){
        m_head = new avlTreeNode;
        m_head->data = -1;
        m_head->deepin = 1;
        m_head->left = m_head->right = nullptr;
    }

public:
    avlTreeNode* getHead(){
        return m_head;
    }

    int getDeepin(avlTreeNode* node){
        return node ? node->deepin : 0;
    }

    int getNodeBalanceFactor(avlTreeNode* node){
        return node ? getDeepin(node->left) - getDeepin(node->right) : 0;
    }

    void updateDeepin(avlTreeNode* node){
        node->deepin = max(getDeepin(node->left), getDeepin(node->right)) + 1;
    }

    avlTreeNode* rightRotate(avlTreeNode* node){
        node->left->right = node;
        node->left = nullptr;
        updateDeepin(node);
        updateDeepin(node->left);
        return node->left;
    }

    avlTreeNode* leftRotate(avlTreeNode* node){
        node->right->left = node;
        node->right = nullptr;
        updateDeepin(node);
        updateDeepin(node->right);
        return node->right;
    }

    avlTreeNode* left_rightRotate(avlTreeNode* node){
        node->left->right->left = node->left;
        node->left = node->left->right;
        node->left->left->right = nullptr;
        updateDeepin(node->left);
        updateDeepin(node->left->left);
        node = leftRotate(node);
        return node;
    }

    avlTreeNode* right_leftRotate(avlTreeNode* node){
        node->right->left->right = node->right;
        node->right = node->right->left;
        node->right->right->left = nullptr;
        updateDeepin(node->right);
        updateDeepin(node->right->right);
        node = leftRotate(node);
        return node;
    }

    avlTreeNode* add(int val, avlTreeNode* node){
        if(!node){
            avlTreeNode* temp = new avlTreeNode;
            temp->data = val;
            temp->left = temp->right = nullptr;
            return temp;
        }
        if(val < node->data){
            node->left = add(val, node->left);
            updateDeepin(node);
            int balance = getNodeBalanceFactor(node);
            if(balance > 1){
                if(val < node->left->data){
                    node = rightRotate(node);
                }else{
                    node = left_rightRotate(node);
                }
            }
        }else if(val > node->data){
            node->right = add(val, node->right);
            updateDeepin(node);
            int balance = getNodeBalanceFactor(node);
            if(balance > 1){
                if(val > node->right->data){
                    node = leftRotate(node);
                }else{
                    node = right_leftRotate(node);
                }
            }
        }else{
            cout << "不可插入相同数据！" << endl;
        }
        updateDeepin(node);
        return node;
    }



private:
    avlTreeNode* m_head;

};

#endif //MYAVLTREE_H