#include <StringBuilder.h>

int main() {
    int choice;

    do {
        choice = 0;

        StringBuilder strObj1, strObj2;
        std::cout << "Введите строки:" << std::endl;
        std::cin >> strObj1 >> strObj2;
        strObj1 += strObj2 += strObj2;

        if (!strObj1 || !strObj2) std::cout << "Одна из строк пуста" << std::endl;
        else {
            int a, b;
            std::cout << "Введите начало и конец подстроки:" << std::endl;
            std::cin >> a >> b;

            std::cout << "Подстрока из первой строки: " << strObj1(a, b) << std::endl;
            std::cout << "Символ на позиции " << a << " в первой строке: " << strObj1[a] << std::endl;

            char str[] = "test";
            std::cout << strObj1-- + str + --strObj1 + str + strObj2++ + ++strObj2 << std::endl;
        }

        std::cout << "Хотите повторить?\n1 - Да\n2 - Нет" << std::endl;
        while (choice < 1 || choice > 2) std::cin >> choice;
    } while (choice != 2);
}