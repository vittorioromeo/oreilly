#include <cstdio>
#include <random>

namespace vittorioromeo::util
{
    // CHANGE: add `[[nodiscard]]` attribute.
    [[nodiscard]] int rnd_int(const int min, const int max)
    {
        static std::random_device rd;
        static std::mt19937 mt(rd());

        return std::uniform_int_distribution<int>{min, max - 1}(mt);
    }
} // namespace vittorioromeo::util

namespace vittorioromeo::database
{
    enum class outcome : int
    {
        success = 0,
        connection_failure = 1,
        unexpected_failure = 2
    };

    enum class record_type : int
    {
        invalid = -1,
        binary = 0,
        number = 1,
        string = 2,
    };

    struct handle
    {
        bool _valid_state;

        // 0 and 1 are both `binary`.
        // 2 is `number`
        // 3 is `string`.
        // Any other input is `invalid`.

        // CHANGE: add `[[nodiscard]]` attribute.
        [[nodiscard]] record_type get_record_type(const int key)
        {
            if(!_valid_state)
            {
                // This is a tongue in cheek example of how failure to check
                // preconditions can result in "undefined behavior".
                return static_cast<record_type>(1 / 0);
            }

            switch(key)
            {
                // CHANGE: add `[[fallthrough]]` attribute. You should compile
                //         your code with `-Wfallthrough` to detect possible
                //         problems.
                case 0: [[fallthrough]];
                case 1: return record_type::binary;
                case 2: return record_type::number;
                case 3: return record_type::string;
            }

            return record_type::invalid;
        }
    };

    // CHANGE: add `[[nodiscard]]` attribute. This is the important one! As an
    //         alternative, it can also be applied to the `outcome` type.
    [[nodiscard]] outcome get_handle(handle& out)
    {
        // Simulate real database connection...
        if(util::rnd_int(0, 100) < 95)
        {
            out = handle{true};
            return outcome::success;
        }
        else
        {
            if(util::rnd_int(0, 100) < 50)
            {
                out = handle{false};
                return outcome::connection_failure;
            }
            else
            {
                out = handle{false};
                return outcome::unexpected_failure;
            }
        }
    }

} // namespace vittorioromeo::database

int main()
{
    vittorioromeo::database::handle h;

    // CHANGE: inspect the result of `get_handle`. The compiler will warn you
    //         after adding `[[nodiscard]]`!
    if(const auto rc = vittorioromeo::database::get_handle(h);
       rc != vittorioromeo::database::outcome::success)
    {
        std::printf("Database connection failed\n");
        return 1;
    }

    const auto record_type = h.get_record_type(2);
    std::printf("Record type is %d\n", static_cast<int>(record_type));
}
