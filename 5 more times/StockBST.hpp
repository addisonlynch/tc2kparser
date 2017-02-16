//
//  StockBST.hpp
//  5 more times
//
//  Created by Addison Lynch on 8/24/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef StockBST_hpp
#define StockBST_hpp

//
//  BST2.hpp
//  o test
//
//  Created by Addison Lynch on 8/26/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef BST2_hpp
#define BST2_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>


using namespace std;


class BST
{
    struct node
    {
        std::string data;
        node* left;
        node* right;
    };
    
    node* root;
    

    node* makeEmpty(node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    
    node* add(std::string x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = add(x, t->left);
        else if(x > t->data)
            t->right = add(x, t->right);
        return t;
    }
    
    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    
    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    
    node* remove(std::string x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        
        return t;
    }
    
    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
    
    
    void inorderFile(node* t, ofstream& outFile)
    {
        if (t == NULL)
            return;
        {
            inorderFile(t->left, outFile);
            outFile << t->data << endl;
            inorderFile(t->right, outFile);
        }
        
    }
    
    
    node* find(node* t, std::string x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }
    
    void convert(node* t, std::queue<string>& q)
    {
        if(t == NULL)
            return;
        
        convert(t->left, q);
        q.push(t->data);
        convert(t->right, q);
    }


public:

    
    BST()
    {
        root = NULL;
    }
    
    BST& operator=(BST rhs)
    {
        this->root = rhs.root;
        return *this;
    }
    ~BST()
    {

    }
    
    void add(std::string x)
    {
        root = add(x, root);
    }
    
    void remove(std::string x)
    {
        root = remove(x, root);
    }
    
    void display()
    {
        inorder(root);
        cout << endl;
    }
    
    bool search(std::string x)
    {
        if(find(root, x) == NULL)
            return false;
        else
            return false;
    }
    
    void printToFile(ofstream& file)
    {
        inorderFile(this->root, file);
        return;
    }
    
    std::queue<string> convertToQueue()
    {
        std::queue<string> temp;
        convert(root, temp);
        return temp;
    }
    node* getRoot(){return root;};
    
};


#endif /* BST2_hpp */


#endif /* StockBST_hpp */
