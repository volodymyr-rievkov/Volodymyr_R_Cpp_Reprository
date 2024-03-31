#pragma once
#include<iostream>

template<typename key_type, typename value_type>
class Map 
{
private:
    struct Node 
    {
        key_type key;
        value_type value;
        Node* next;
        Node(const key_type& key, const value_type& value, Node* next);
    };
    Node* head;
public:
    class Iterator 
    {
    private:
        Node* current;
    public:
        Iterator(Node* node)
        {
            current = node;
        }

        Iterator& operator++() 
        {
            if (current) 
            {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const 
        {
            return current != other.current;
        }

        value_type operator*() const 
        {
            return current->value;
        }
    };
    Map();
    ~Map();
    void add(const key_type& key, const value_type& value);
    value_type* search(const key_type& key);
    void remove(const key_type& key);
    void clear();
    Iterator begin() { return Iterator(head); };
    Iterator end() { return Iterator(nullptr); }
};