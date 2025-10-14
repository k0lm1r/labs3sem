#include <StringBuilder.h>

int main() {
    int choice;

    do {
        choice = 0;

        StringBuilder str1, str2;
        std::cout << "Введите строки:" << std::endl;
        std::cin >> str1 >> str2;

        if (!str1 || !str2) std::cout << "Одна из строк пуста" << std::endl;
        else {
            int a, b;
            std::cout << "Введите начало и конец подстроки:" << std::endl;
            std::cin >> a >> b;

            std::cout << "Подстрока из первой строки: " << str1(a, b) << std::endl;
            std::cout << "Символ на позиции " << a << " в первой строке " << str1[a] << std::endl;

            char str[] = "opipoi";
            std::cout << str1 + str2 << std::endl;
            std::cout << str1 + str << std::endl;
            std::cout << str + str1 << std::endl;
            std::cout << str1++ << " " << ++str1 << std::endl;
            std::cout << str2-- << " " << --str2 << std::endl;
        }

        std::cout << "Хотите повторить?\n1 - Да\n2 - Нет" << std::endl;
        while (choice < 1 || choice > 2) std::cin >> choice;
    } while (choice != 2);
}