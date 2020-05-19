#include <variant>
#include <optional>
#include <functional>
#include <string>

// Imagine a networked application where messages are exchanged between clients
// and a server. Your goal is to model the messaged described below in a type
// safe manner, using algebraic data types (`std::variant`, `std::optional`).

// * A client can attempt to connect to a server. The server will reply with
//   either success or failure.

// * A client can attempt to create a new key on the server. Handle possible
//   failure cases.

// * A client can attempt to set a value for a key-value pair on the server.
//   Handle possible failure cases.

// * A client can attempt to read a value from a key-value pair on the server.

// clang-format off
namespace clientmsg
{
    struct connect    { };
    struct create_key { std::string _key; std::optional<std::string> _value; };
    struct set_value  { std::string _key; std::string _value; };
    struct get_value  { std::string _key; };
}

namespace servermsg
{
    // Responses to client messages which attempt a connection.
    struct client_connect_success { };
    struct client_connect_failure { int _error_code; };

    // Responses to client messages which access key-value pairs.
    struct key_already_present    { };
    struct key_non_existent       { };
    struct key_action_success     { };
    struct value                  { std::string _value; };
}

struct client_message
{
    std::variant<
        clientmsg::connect,
        clientmsg::create_key,
        clientmsg::set_value,
        clientmsg::get_value
    > _payload;
};

struct server_message
{
    std::variant<
        servermsg::client_connect_success,
        servermsg::client_connect_failure,
        servermsg::key_already_present,
        servermsg::key_non_existent,
        servermsg::key_action_success,
        servermsg::value
    > _payload;
};
// clang-format on

struct client
{
    void send(const client_message& message, const char* server_ip)
    {
        // DO NOT IMPLEMENT. This is just to help you understand how the client
        // and the server communicate.

        (void)message;
        (void)server_ip;
    }

    std::function<void(const server_message&)> _on_server_message;
    // DO NOT IMPLEMENT. This is just to help you understand how the client
    // and the server communicate.
};

int main()
{
}
