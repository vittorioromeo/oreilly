#include <cstdio>
#include <typeinfo>

template <typename... Ts, typename F>
void for_types(F&& f)
{
    // TODO: implement this function.
}

int main()
{
    for_types<char, int, float, double>([](auto t)
    {
        using T = typename decltype(t)::type;
        std::printf("sizeof(%s) = %ld\n", typeid(T).name(), sizeof(T));
    });

    // TODO: should print:
    /*
        sizeof(c) = 1
        sizeof(i) = 4
        sizeof(f) = 4
        sizeof(d) = 8
    */
}
