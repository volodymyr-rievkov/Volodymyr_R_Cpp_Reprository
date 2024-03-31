#pragma once
#include <iostream>

template<typename key_type, typename value_type>
class Map 
{
private:
    struct Node 
    {
        key_type key;
        value_type value;
        Node* next;
        
        Node(const key_type& key, const value_type& value);
    };
    Node* head;
public:
    Map();
    ~Map();
    void add(const key_type& key, const value_type& value);
    value_type* search(const key_type& key);
    void remove(const key_type& key);
    void clear();
    void print();
};
