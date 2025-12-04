#ifndef DEQUE_TPP
#define DEQUE_TPP

#include "Deque.h"

template <typename T>
T& Deque<T>::peekFirst() const
{
    if (this->isEmpty())
        throw ContainerException(103, "очередь пуста");
    return this->first->value;
}

template <typename T>
T& Deque<T>::peekLast() const
{
    if (this->isEmpty())
        throw ContainerException(103, "очередь пуста");
    return this->last->value;
}

template <typename T>
T Deque<T>::takeFirst()
{
    if (this->isEmpty())
        throw ContainerException(103, "очередь пуста");

    T firstValue = this->first->value;
    Node<T> *oldFirst = this->first;
    this->first = this->first->next;
    delete oldFirst;
    return firstValue;
}

template <typename T>
T Deque<T>::takeLast()
{
    if (this->isEmpty())
        throw ContainerException(103, "очередь пуста");

    T lastValue = this->last->value;
    Node<T> *oldLast = this->last;
    this->last = this->last->next;
    delete oldLast;
    return lastValue;
}


template <typename T>
void Deque<T>::addFirst(T &value)
{
    Node<T> *newFirst = new Node<T>(value, this->first, nullptr);
    this->first = newFirst;
    if (this->last == nullptr)
        this->last = this->first;
}

template <typename T>
void Deque<T>::addLast(T &value)
{
    Node<T> *newLast = new Node<T>(value, nullptr, this->last);
    this->last = newLast;
    if (this->first == nullptr)
        this->first = this->last;
}

template <typename T>
void Deque<T>::sort(const std::function<bool(const T &, const T &)> &compare)
{
    for (Node<T> *pos = this->first; pos->next != nullptr; pos = pos->next)
    {
        Node<T> *maxNode = pos;
        for (Node<T> *correctVal = pos->next; correctVal != nullptr; correctVal = correctVal->next)
            if (compare(maxNode->value, correctVal->value))
                maxNode = correctVal;
        T temp = pos->value;
        pos->value = maxNode->value;
        maxNode->value = temp;
    }
}

template <typename T>
bool Deque<T>::isEmpty() const
{
    return this->first == nullptr;
}

template <typename T>
Deque<T> Deque<T>::find(const std::function<bool(const T &)> &searchTerm) const
{
    Deque resultDeque;

    for (Node<T> *current = this->first; current != nullptr; current = current->next)
        if (searchTerm(current->value))
            resultDeque.addLast(current->value);

    return resultDeque;
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T> &other)
{
    if (this != &other)
    {
        while (!this->isEmpty())
            this->takeFirst();

        this->first = new Node<T>(other.first->value, nullptr, nullptr);
        this->last = this->first;

        for (Node<T> *current = other.first->next; current != nullptr; current = current->next)
        {
            Node<T> *newLast = new Node<T>(current->value, nullptr, this->last);
            this->last = newLast;
        }
    }

    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Deque<T> &d)
{
    if (d.isEmpty())
    {
        os << "Очередь пуста." << std::endl;
        return os;
    }

    for (typename Deque<T>::Node<T>* current = d.first; current != nullptr; current = current->getNext())
    {
        if constexpr (std::is_pointer_v<T>)
        {
            os << *current->getValue() << std::endl;
        }
        else
            os << current->getValue() << std::endl;
    }
    return os;
}

#endif


































// template <typename T>
// std::istream &operator>>(std::istream &is, Deque<T> &d)
// {
//     for (typename Deque<T>::Node<T>* current = d.first; current != nullptr; current = current->getNext())
//     {
//         T value;
//         is >> value;
//         if constexpr (std::is_pointer_v<T>)
//         {
//             current->setValue(new T(value));
//         } else
//             current->setValue(value);
//     }

//     return is;
// }
