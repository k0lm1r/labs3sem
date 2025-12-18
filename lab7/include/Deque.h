#pragma once
#include <iostream>
#include <functional>
#include <iterator>
#include "Exceptions.h"

template<typename T>
class Deque {
    public:
        template<typename N>
        class Node {
            N value;
            Node* next = nullptr;
            Node* prev = nullptr;

            public:
                Node (N& value, Node* next, Node* prev) : value(value), next(next), prev(prev) {
                    if (next != nullptr) next->prev = this;
                    if (prev != nullptr) prev->next = this;
                }
                ~Node() {
                    if (this->next != nullptr)
                        delete this->next;
                    if (this->prev != nullptr)
                        delete this->prev;
                }

                const N& getValue() const { return this->value; }
                N& getValue() {return this->value; }
                Node* getNext() const { return this->next; }
                Node* getPrev() const {return this->prev; }
                
                friend class Deque;
        };
        
        class Iterator {
            Node<T>* current = nullptr;
            public:
                Iterator() = default;
                explicit Iterator(Node<T>* node) : current(node) {}

                T& operator*() const { return current->value; }
                T* operator->() const { return &current->value; }

                Iterator& operator++() { if (current) current = current->next; return *this; }
                Iterator operator++(int) { Iterator tmp(*this); ++(*this); return tmp; }
                Iterator& operator--() { if (current) current = current->prev; return *this; }
                Iterator operator--(int) { Iterator tmp(*this); --(*this); return tmp; }

                bool operator==(const Iterator& other) const { return current == other.current; }
                bool operator!=(const Iterator& other) const { return !(*this == other); }
        };
            
        private:
            Node<T>* first = nullptr;
            Node<T>* last = nullptr;
            
        public:
            Deque() = default;
            Deque(T& firstValue) {
                this->first = new Node<T>(firstValue, nullptr, nullptr);
                this->last = this->first;
            }
        Deque(const Deque& other) : Deque(other.first->value) {
            for (Node<T>* current = other.first->next; current != nullptr; current = current->next) {
                Node<T>* newLast = new Node<T>(current->value, nullptr, this->last);
                this->last = newLast;
            }
        }
        ~Deque() {
            if (this->first != nullptr)
            delete this->first;
        }
        
        
        T& peekFirst() const;
        T& peekLast() const;
        T takeFirst();
        T takeLast();
        void addFirst(T& value);
        void addLast(T& value);
        void sort(const std::function<bool(const T&, const T&)>& compare);
        bool isEmpty() const;
        Deque<T> find(const std::function<bool(const T&)>& searchTerm) const;
        Deque& operator=(const Deque& other);

        Iterator begin() { return Iterator(this->first); }
        Iterator end() { return Iterator(nullptr); }
        Iterator rbegin() { return Iterator(this->last); }
        Iterator rend() { return Iterator(nullptr); }
        
        template <typename F>
        friend std::ostream& operator<<(std::ostream& os, const Deque<F>& d);
        
    };
    
    #include "../src/Deque.tpp"
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // void setValue(N& value) { this->value = value; }
    
    // template <typename F>
    // friend std::istream& operator>>(std::istream& is, Deque<F>& d);
