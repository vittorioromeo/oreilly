#include <cstdio>
#include <typeinfo>

template <typename T>
struct type_wrapper { using type = T; };

template <typename... Ts, typename F>
void for_types(F&& f)
{
    (f(type_wrapper<Ts>{}), ...);
}

int main()
{
    for_types<char, int, float, double>([](auto t)
    {
        using T = typename decltype(t)::type;
        std::printf("sizeof(%s) = %ld\n", typeid(T).name(), sizeof(T));
    });
}
