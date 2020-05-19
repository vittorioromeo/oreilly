#include <cstdio>
#include <tuple>
#include <utility>

template <typename T>
struct vec3
{
private:
    T _x, _y, _z;

public:
    vec3(T x, T y, T z)
        : _x{x}, _y{y}, _z{z}
    {
    }

    T& x()             { return _x; }
    const T& x() const { return _x; }

    T& y()             { return _y; }
    const T& y() const { return _y; }

    T& z()             { return _z; }
    const T& z() const { return _z; }
};

template <std::size_t I, typename T>
const T& get(const vec3<T>& v)
{
    if (I == 0) { return v.x(); }
    if (I == 1) { return v.y(); }
    return v.z();
}

template <std::size_t I, typename T>
T& get(vec3<T>& v)
{
    if (I == 0) { return v.x(); }
    if (I == 1) { return v.y(); }
    return v.z();
}

namespace std
{
    template <typename T>
    struct tuple_size<::vec3<T>>
        : std::integral_constant<std::size_t, 3>
    {
    };

    template <std::size_t I, typename T>
    struct tuple_element<I, ::vec3<T>>
    {
        using type = T;
    };
}

int main()
{
    const vec3<float> point{2.f, 1.f, 4.f};
    const vec3<float> scaling_factors{2.f, 4.f, 10.f};

    const auto& [px, py, pz] = point;
    const auto& [sx, sy, sz] = scaling_factors;

    const vec3<float> result{px * sx, py * sy, pz * sz};

    std::printf("%f %f %f\n",
                result.x(), result.y(), result.z());
}
