#include <StringBuilder.h>

int main() {
    char str[] = "asdfasd";
    StringBuilder a(str);
    StringBuilder b;
    std::cin >> b;
    std::cout << a[1] << " " << !b << std::endl;
    std::cout << a(1, 4) << std::endl;
    std::cout << a << '\n' << b << std::endl;
}