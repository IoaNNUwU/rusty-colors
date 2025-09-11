#include <iostream>
#include <string>
#include <vector>

template<typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

int main()
{
    std::string s = "Hello, generics!";
    print(s);

    std::vector<std::string> v = {"one", "two", "three"};
    for (const auto& x : v)
        print(x);

    return 0;
}
