#include <iostream>
#include <map>
#include "Deque.h"
#include "Algorithms.h"

int main() {
    std::cout << "=== Демонстрация Deque и алгоритмов ===\n";

    Deque<int> dq;
    int a = 5, b = 1, c = 3;
    dq.addLast(a);
    dq.addLast(b);
    dq.addLast(c);

    std::cout << "Исходный дек: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\nПервый элемент через begin(): " << *dq.begin();
    std::cout << "\nПоследний элемент через rbegin(): " << *dq.rbegin() << "\n";

    dq.sort([](const int& lhs, const int& rhs) { return lhs > rhs; });
    std::cout << "Отсортированный дек: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    auto onlyEven = DequeAlgorithms::collectIf(dq.begin(), dq.end(), [](int v) { return v % 2 == 0; });
    std::cout << "Четные элементы: ";
    for (auto it = onlyEven.begin(); it != onlyEven.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << "\n\n=== Демонстрация MapAlgorithms ===\n";

    std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::cout << "Содержит ключ 2? " << (MapAlgorithms::containsKey(m, 2) ? "да" : "нет") << '\n';
    auto longEntries = MapAlgorithms::collectIf(m, [](const std::pair<const int, std::string>& p) { return p.second.size() > 3; });
    std::cout << "Элементы со строкой >3 символов: ";
    for (const auto& p : longEntries) {
        std::cout << '{' << p.first << ':' << p.second << "} ";
    }
    std::cout << '\n';

    auto upperValues = MapAlgorithms::transformValues(m, [](const std::string& v) {
        std::string copy = v;
        for (char& ch : copy) ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
        return copy;
    });
    std::cout << "Преобразованные значения: ";
    for (const auto& v : upperValues) {
        std::cout << v << ' ';
    }
    std::cout << '\n';

    return 0;
}
