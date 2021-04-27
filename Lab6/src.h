#pragma once
#include <iostream>

using namespace std;

template<typename T, typename keyType>
class Map
{
    struct Node
    {
        Node* left;
        Node* right;
        Node* parent;
        Node* prev = NULL;
        Node* next = NULL;
        int amount = 1;
        pair<keyType, T> info;
        Node(T i, const keyType k, Node* par = NULL, Node* lf = NULL, Node* rg = NULL)
        {
            info.first = k;
            info.second = i;
            parent = par;
            left = lf;
            right = rg;
        }
    };

    Node* root;

public:
    Map()
    {
        root = NULL;
    }

    Map(keyType key, T value)
    {
        root = new Node(value, key);
        size = 1;
    }

    ~Map()
    {
        DeleteTree(root);
    }

    int GetWeight()
    {
        return GetWeight(root);
    }

    void insert(const keyType k, const T& value)
    {
        insert(root, value, k, NULL);
        size++;
    }

    bool empty()
    {
        if (size)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int Size()
    {
        return size;
    }

    void clear()
    {
        DeleteTree(root);
        size = 0;
    }

    bool find(const keyType k)
    {
        return find(root, k);
    }

    void erase(const keyType k)
    {
        Node* node = findNode(k);
        if (node->parent != NULL && (node->parent)->right == node)
        {
            if (node->left == NULL && node->right == NULL)
            {
                Node* ners = node->parent;
                while (ners->parent != NULL && (ners->parent)->right == ners)
                {
                    ners = ners->parent;
                }
                if (ners->parent != NULL)
                {
                    ners = ners->parent;
                    ners->prev = node->prev;
                    (node->prev)->next = node->next;//node->next == ners
                }
                else
                {
                    (node->prev)->next = NULL;
                }
            }
            else if (node->left == NULL)
            {
                (node->prev)->next = node->next;
                (node->next)->prev = node->prev;
            }
            else if (node->right == NULL)
            {
                (node->prev)->next = node->next;
                if (node->next != NULL)
                {
                    (node->next)->prev = node->prev;
                }
            }
            else
            {
                Node* ners = node->left;
                while (ners->right != NULL)
                {
                    ners = ners->right;
                }
                if (ners == node->left)
                {
                    ners->next = node->next;
                    (node->next)->prev = ners;
                }
                else
                {
                    if (ners->left != NULL)
                    {
                        (ners->next)->prev = ners->prev;
                    }
                    (ners->prev)->next = ners->next;
                }
            }
        }
        else if (node->parent != NULL && (node->parent)->left == node)
        {
            if (node->left == NULL && node->right == NULL)
            {
                Node* ners = node->parent;
                while (ners->parent != NULL && (ners->parent)->left == ners)
                {
                    ners = ners->parent;
                }
                if (ners->parent != NULL)
                {
                    ners = ners->parent;
                    ners->next = node->next;
                    (node->next)->prev = node->prev;//node->next == ners
                }
                else
                {
                    (node->next)->prev = NULL;
                }
            }
            else if (node->left == NULL)
            {
                (node->next)->prev = node->prev;
                if (node->prev != NULL)
                {
                    (node->prev)->next = node->next;
                }
            }
            else if (node->right == NULL)
            {
                (node->next)->prev = node->prev;
                (node->prev)->next = node->next;
            }
            else
            {
                Node* ners = node->left;
                while (ners->right != NULL)
                {
                    ners = ners->right;
                }
                if (ners == node->left)
                {
                    ners->next = node->next;
                    (node->next)->prev = ners;
                }
                else
                {
                    if (ners->left != NULL)
                    {
                        (ners->next)->prev = ners->prev;
                    }
                    (ners->prev)->next = ners->next;
                }
            }
        }
        else
        {
            if (node->left == NULL && node->right != NULL)
            {
                (node->next)->prev = NULL;
            }
            else if (node->right == NULL && node->left != NULL)
            {
                (node->prev)->next = NULL;
            }
            else if (node->right != NULL && node->left != NULL)
            {
                Node* ners = node->left;
                while (ners->right != NULL)
                {
                    ners = ners->right;
                }
                if (ners == node->left)
                {
                    ners->next = node->next;
                    (node->next)->prev = ners;
                }
                else
                {
                    if (ners->left != NULL)
                    {
                        (ners->next)->prev = ners->prev;
                    }
                    (ners->prev)->next = ners->next;
                }
            }
        }






        if (node->left == NULL && node->right == NULL)
        {
            if (node->parent != NULL && node == (node->parent)->right)
            {
                (node->parent)->right = NULL;
            }
            else if (node->parent != NULL)
            {
                (node->parent)->left = NULL;
            }
            node = NULL;
        }
        else if (node->left == NULL)
        {
            if (node->parent != NULL && node == (node->parent)->right)
            {
                (node->parent)->right = node->right;
                (node->right)->parent = node->parent;
            }
            else if (node->parent != NULL)
            {
                (node->parent)->left = node->right;
                (node->right)->parent = node->parent;
            }
            else
            {
                root = node->right;
                root->parent = NULL;
            }
        }
        else if (node->right == NULL)
        {
            if (node->parent != NULL && node == (node->parent)->right)
            {
                (node->parent)->right = node->left;
                (node->left)->parent = node->parent;
            }
            else if (node->parent != NULL)
            {
                (node->parent)->left = node->left;
                (node->left)->parent = node->parent;
            }
            else
            {
                root = node->left;
                root->parent = NULL;
            }
        }
        else
        {
            Node* ny = node->left;
            while (ny->right != NULL)
            {
                ny = ny->right;
            }
            if (ny == node->left)
            {
                ny->right = node->right;
                (node->right)->parent = ny;
                ny->parent = node->parent;
                if (node->parent != NULL && node == (node->parent)->right)
                {
                    (node->parent)->right = ny;
                }
                else if (node->parent != NULL)
                {
                    (node->parent)->left = ny;
                }
            }
            else
            {
                node->info.first = ny->info.first;
                node->info.second = ny->info.second;
                if (ny->left != NULL)
                {
                    (ny->left)->parent = ny->parent;
                }
                (ny->parent)->right = ny->left;
            }
        }
        size--;
    }

    Node* findNode(const keyType k)//*
    {
        Node* node = root;
        while (node->info.first != k)
        {
            if (k < node->info.first)
            {
                node = node->left;
            }
            else if (k > node->info.first)
            {
                node = node->right;
            }
        }
        return node;
    }

    keyType& lower_bound(const keyType k)
    {
        keyType notExitKey = NULL;
        Node* node = findNode(k);
        if (node->right != NULL)
        {
            return (node->right)->info.first;
        }
        else if (node->parent != NULL && (node->parent)->left == node)
        {
            return (node->parent)->info.first;
        }
        else
        {
            return notExitKey;
        }
    }

    keyType& upper_bound(const keyType k)
    {
        keyType notExitKey = NULL;
        Node* node = findNode(k);
        if (node->left != NULL)
        {
            return (node->left)->info.first;
        }
        else if (node->parent != NULL && (node->parent)->right == node)
        {
            return (node->parent)->info.first;
        }
        else
        {
            return notExitKey;
        }
    }

    T& operator[](keyType k)
    {
        Node* node = findNode(k);
        T* value = &node->info.second;
        return *value;
    }

    class iterator : bidirectional_iterator_tag
    {
        Node* node = nullptr;//Node<T>* node = nullptr;
    public:
        iterator() {} // iterator<T>
        iterator(Node* tmp)//iterator<T>(Node<T>* tmp)
        {
            node = tmp;
        }

        iterator operator++()
        {
            node = node->next;
            return iterator(node);
        }

        iterator operator++(int)
        {
            Node* mem = node;
            node = node->next;
            return iterator(mem);
        }

        iterator operator--()
        {
            node = node->prev;
            return iterator(node);
        }

        iterator operator--(int)
        {
            Node* mem = node;
            node = node->prev;
            return iterator(mem);
        }

        int GetAmount()
        {
            return node->amount;
        }

        bool operator==(iterator& right)
        {
            return node->info.second == (right.node)->info.second;//TODO 
        }

        bool operator!=(iterator& right)
        {
            return !(node->info.second == (right.node)->info.second);//TODO 
        }

        T& operator*()
        {
            return node->info.second;
        }

        T operator*() const
        {
            return node->info.second;
        }
    };

    iterator begin()//iterator<T> begin()
    {
        Node* node = root;
        while (node->left != NULL)
        {
            node = node->left;
        }
        return iterator(node);//iterator<T>(node);
    }
    iterator end()
    {
        Node* node = root;
        while (node->right != NULL)
        {
            node = node->right;
        }
        return iterator(node);
    }

private:
    bool find(Node*& node, const keyType k);
    void DeleteTree(Node* node);
    void insert(Node*& node, const T& value, const keyType k, Node* par);//&
    int GetWeight(Node* node);
    int size = 0;
};

template<typename T, typename keyType>
void Map<T, keyType>::DeleteTree(Node* node)
{
    if (size != 0 && node)
    {
        if (node->left != NULL)
        {
            DeleteTree(node->left);
        }
        if (node->right != NULL)
        {
            DeleteTree(node->right);
        }
        delete node;
    }
}

template<typename T, typename keyType>
int Map<T, keyType>::GetWeight(Node* node)
{
    if (!node)
    {
        return 0;
    }
    int max = 0;
    if (node->left)
    {
        max++;
        GetWeight(node->left);
    }
    if (node->right)
    {
        max++;
        GetWeight(node->right);
    }
    return max + 1;
}

template<typename T, typename keyType>
void Map<T, keyType>::insert(Node*& node, const T& value, const keyType k, Node* par)
{
    if (node == NULL)
    {
        node = new Node(value, k, par);
        if (node->parent != NULL && node == (node->parent)->left)
        {
            node->next = node->parent;
            (node->parent)->prev = node;
            Node* nins = node->parent;
            while (nins->parent != NULL && (nins->parent)->left == nins)
            {
                nins = nins->parent;
            }
            if (nins->parent != NULL)
            {
                nins = nins->parent;
                //(nins->next)->prev = node;
                //node->next = nins->next;
                nins->next = node;
                node->prev = nins;
            }
        }
        else if (node->parent != NULL && node == (node->parent)->right)
        {
            node->prev = node->parent;
            (node->parent)->next = node;
            Node* nins = node->parent;//& TODO
            while (nins->parent != NULL && (nins->parent)->right == nins)//nins->parent != NULL
            {
                nins = nins->parent;
            }
            if (nins->parent != NULL)
            {
                nins = nins->parent;
                nins->prev = node;
                node->next = nins;
            }
        }
    }
    else if (k < node->info.first && value != node->info.second)
    {
        insert(node->left, value, k, node);
    }
    else if (k > node->info.first && value != node->info.second)
    {
        insert(node->right, value, k, node);
    }
    else if (k == node->info.first || value == node->info.second)
    {
        node->amount++;
        size--;
        return;
    }
}

template<typename T, typename keyType>
bool Map<T, keyType>::find(Node*& node, const keyType k)
{
    if (!node)
    {
        return false;
    }
    if (node->info.first == k)
    {
        return true;
    }
    if (k < node->info.first)
    {
        return find(node->left, k);
    }
    else
    {
        return find(node->right, k);
    }
}