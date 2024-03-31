#include "Map.hpp"

template<typename key_type, typename value_type>
Map<key_type, value_type>::Node::Node(const key_type& key, const value_type& value, Node* node) 
{
    this->key = key;
    this->value = value;
    next = node;
}

template<typename key_type, typename value_type>
Map<key_type, value_type>::Map() 
{
    head = nullptr;
}

template<typename key_type, typename value_type>
Map<key_type, value_type>::~Map() 
{
    clear();
}

template<typename key_type, typename value_type>
void Map<key_type, value_type>::add(const key_type& key, const value_type& value) 
{
    Node* new_node = new Node(key, value, head);
    head = new_node;
}

template<typename key_type, typename value_type>
value_type* Map<key_type, value_type>::search(const key_type& key) 
{
    Node* current = head;
    while(current != nullptr) 
    {
        if(current->key == key) 
        {
            return &current->value;
        }
        current = current->next;
    }
    return nullptr;
}

template<typename key_type, typename value_type>
void Map<key_type, value_type>::remove(const key_type& key) 
{
    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr) 
    {
        if(current->key == key) 
        {
            if(prev != nullptr) 
            {
                prev->next = current->next;
            } 
            else 
            {
                head = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template<typename key_type, typename value_type>
void Map<key_type, value_type>::clear() 
{
    while(head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template class Map<int,int>;