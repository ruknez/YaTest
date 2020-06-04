#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

/*
    Данный пример демонстрирует использование лямбда-функции
    в качестве некого принтера для вектора. Что бы не копипастить 
    код вывода на экран он помещен в лямбда-функцию. Нет смысла создавать
    отделюную функцию потому-что она используется только в этом участке кода
    только в этой области видимости. В другом месте надо будет выводить по другому.
*/
void example_1()
{
    constexpr size_t size = 20;

    std::vector<int> v;
    v.resize(size);

    for (size_t i = 0; i < size; i++)
        v.push_back(std::rand() % 100 - 50);

    auto printer = [&v]() {
        for (auto val : v)
            std::cout << "val = " << val << " ";
        std::cout << std::endl
                  << std::endl;
    };
    printer();
    //for (auto val:v)
    //    std::cout << "val = " << val  << " ";
    //std::cout << std::endl;

    std::sort(begin(v), end(v));
    printer();
    //for (auto val:v)
    //    std::cout << "val = " << val  << " ";
    //std::cout << std::endl;
}

/*
    Данный пример показывет что можно какой-то алгоритм свернуть 
    в функцию и получить сразу результат его работы.
*/

void example_2()
{
    std::array<int, 10> mass{1, 2, 3, 4, 33, 6, 7, 8, 9, 10};

    int max = [&mass]() {
        int maxi = mass[0];
        for (size_t i = 1; i < mass.size(); i++)
        {
            if (maxi < mass[i])
                maxi = mass[i];
        }
        return maxi;
    }();

    std::cout << "max = " << max << std::endl;
}

/*
    Данный пример показывает что лямбда-функции необходимы
    при использовании алгоритмов. С их помощью можно задавать различные 
    условия в данном случае сортировка по модулю, а также присутствует
    дополнительная логика по подсчету сравнений.

    Лямбда-функции упрощают синтаксис по сравнению с обычними сишными указателями
    на функцию.
*/
void example_3()
{
    constexpr size_t size = 20;

    std::vector<int> vec;
    vec.resize(size);

    for (size_t i = 0; i < size; i++)
        vec.push_back(std::rand() % 100 - 50);

    size_t count = 0;
    std::sort(begin(vec), end(vec), [&count](int &a, int &b) {
        ++count;
        return abs(a) < abs(b);
    });
    std::cout << "size = " << vec.size() << std::endl;
    std::cout << "count = " << count << std::endl;
}

int main()
{
    example_1();
    example_2();
    example_3();
}