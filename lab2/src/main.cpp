#include <StringBuilder.h>

int main() {
    int choice;
    
    do {
        choice = 0;

        StringBuilder str;
        std::cout << "Введите строку:" << std::endl;
        std::cin >> str;

        if (!str) std::cout << "Строка пуста" << std::endl;
        else {
            int a, b;
            std::cout << "Введите начало и конец подстроки:" << std::endl;
            std::cin >> a >> b;
            std::cout << "Подстрока: " << str(a, b) << std::endl;
            std::cout << "Символ на позиции " << a << " " << str[a] << std::endl;
        }

        std::cout << "Хотите повторить?\n 1 - Да\n2 - Нет" << std::endl;
        while (choice < 1 || choice > 2) std::cin >> choice;
    } while (choice != 2);
}