#pragma once
#include <iostream>
#include <functional>
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
        
        template <typename F>
        friend std::ostream& operator<<(std::ostream& os, const Deque<F>& d);
        
    };
    
    #include "../src/Deque.tpp"
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // void setValue(N& value) { this->value = value; }
    
    // template <typename F>
    // friend std::istream& operator>>(std::istream& is, Deque<F>& d);