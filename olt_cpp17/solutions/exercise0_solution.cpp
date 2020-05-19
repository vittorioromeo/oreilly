#include <array>
#include <cmath>
#include <cstdio>
#include <string>

// CHANGE: Use nested `namespace` definitions.
namespace vittorioromeo::draw
{
    template <int Radius>
    constexpr char* make_circle_pattern(char* output)
    {
        // CHANGE: Remove redundant static assert message.
        static_assert(Radius > 0);

        for(int x{0}; x <= 2 * Radius; x++)
        {
            for(int y{0}; y <= 2 * Radius; y++)
            {
                // CHANGE: Use uniform initialization, discover double to float
                //         narrowing conversion issue.
                const auto dist{std::sqrt(
                    (x - Radius) * (x - Radius) + (y - Radius) * (y - Radius))};

                if(dist > Radius - 0.5 && dist < Radius + 0.5)
                {
                    *output++ = '*';
                }
                else
                {
                    *output++ = ' ';
                }
            }

            *output++ = '\n';
        }

        return output;
    }

    template <int BufferSize, int Radius>
    constexpr std::array<char, BufferSize> get_circle_pattern()
    {
        std::array<char, BufferSize> result{};

        char* last{make_circle_pattern<Radius>(result.data())};
        *last++ = '\0';

        return result;
    }

} // namespace vittorioromeo::draw

namespace vittorioromeo::util
{
    int read_int()
    {
        int buffer;
        std::scanf("%d", &buffer);
        return buffer;
    }

} // namespace vittorioromeo::util

int main()
{
    std::printf(
        "Please enter 0 to draw a small circle, or 1 to draw a big circle.\n");

    // CHANGE: Use initializer in `if` statement. Notice how `input` is usable
    //         in all the branches.
    if(const auto input{vittorioromeo::util::read_int()}; input == 0)
    {
        std::printf(
            "%s\n", vittorioromeo::draw::get_circle_pattern<1024, 4>().data());
    }
    else if(input == 1)
    {
        std::printf(
            "%s\n", vittorioromeo::draw::get_circle_pattern<1024, 9>().data());
    }
    else
    {
        std::printf("Invalid input %d.\n", input);
        return 1;
    }
}
