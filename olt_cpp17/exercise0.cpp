#include <array>
#include <cmath>
#include <cstdio>
#include <string>

namespace vittorioromeo
{
    namespace draw
    {
        template <int Radius>
        constexpr char* make_circle_pattern(char* output)
        {
            static_assert(Radius > 0, "Radius must be positive");

            for(int x = 0; x <= 2 * Radius; x++)
            {
                for(int y = 0; y <= 2 * Radius; y++)
                {
                    const float dist = std::sqrt((x - Radius) * (x - Radius) +
                                                 (y - Radius) * (y - Radius));

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

            char* last = make_circle_pattern<Radius>(result.data());
            *last++ = '\0';

            return result;
        }

    } // namespace draw

    namespace util
    {
        int read_int()
        {
            int buffer;
            std::scanf("%d", &buffer);
            return buffer;
        }

    } // namespace util

} // namespace vittorioromeo

int main()
{
    std::printf(
        "Please enter 0 to draw a small circle, or 1 to draw a big circle.\n");

    const int input = vittorioromeo::util::read_int();
    if(input == 0)
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
