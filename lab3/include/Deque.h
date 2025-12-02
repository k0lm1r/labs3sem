#pragma once
#include <iostream>
#include <functional>
#include "Exceptions.h"

template<typename T>
class Deque {

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
            ~Node() = default;

            friend class Deque;
    };

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
        ~Deque() = default;

        Node<T>* getFrist() {
            return this->first;
        }

        Node<T>* getLast() {
            return this->last;
        }

        T& peekFirst() const {
            if (this->isEmpty())
                throw ContainerException(103, "очередь пуста");
            return this->first->value;
        }

        T& peekLast() const {
            if (this->isEmpty())
                throw ContainerException(103, "очередь пуста");
            return this->last->value;
        }

        T takeFirst() {
            if (this->isEmpty())
                throw ContainerException(103, "очередь пуста");

            T firstValue = this->first->value;
            Node<T> *oldFirst = this->first;
            this->first = this->first->next;
            delete oldFirst;
            return firstValue;
        }

        T takeLast() {
            if (this->isEmpty())
                throw ContainerException(103, "очередь пуста");

            T lastValue = this->last->value;
            Node<T> *oldLast = this->last;
            this->last = this->last->next;
            delete oldLast;
            return lastValue;
        }

        void addFirst(T& value) {
            Node<T> *newFirst = new Node<T>(value, this->first, nullptr);
            this->first = newFirst;
            if (this->last == nullptr) this->last = this->first;
        }

        void addLast(T& value) {
            Node<T> *newLast = new Node<T>(value, nullptr, this->last);
            this->last = newLast;
            if (this->first == nullptr) this->first = this->last;
        }

        void sort(const std::function<bool(const T&, const T&)>& compare) {
            for (Node<T>* pos = this->first; pos->next != nullptr; pos = pos->next) {
                Node<T>* maxNode = pos;
                for (Node<T>* correctVal = pos->next; correctVal != nullptr; correctVal = correctVal->next) 
                    if (compare(maxNode->value, correctVal->value))
                        maxNode = correctVal;
                T temp = pos->value;
                pos->value = maxNode->value;
                maxNode->value = temp;
            }
        }

        bool isEmpty() const {
            return this->first == nullptr;
        }

        Deque<T> find(const std::function<bool(const T&)>& searchTerm) const {
            Deque resultDeque;

            for (Node<T> *current = this->first; current != nullptr; current = current->next)
                if (searchTerm(current->value)) 
                    resultDeque.addLast(current->value);
            
            return resultDeque;
        }

        Deque& operator=(const Deque& other) {
            if (this != &other) {
                while (!this->isEmpty())
                    this->takeFirst();
                
                this->first = new Node<T>(other->first->value, nullptr, nullptr);
                this->last = this->first;

                for (Node<T>* current = other.first->next; current != nullptr; current = current->next) {
                    Node<T>* newLast = new Node<T>(current->value, nullptr, this->last);
                    this->last = newLast;
                }
            }

            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Deque& d) {
            if (d.isEmpty()) {
                os << "Очередь пуста." << std::endl;
                return os;
            }

            for (Node<T>* current = d.first; current != nullptr; current = current->next) {
                if constexpr (std::is_pointer_v<T>) {
                    os << *current->value << std::endl;
                } else {
                    os << current->value << std::endl;
                }
            }
            return os;
        }
};