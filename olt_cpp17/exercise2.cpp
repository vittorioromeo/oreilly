#include <variant>
#include <optional>
#include <functional>

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

struct client_message
{
    // TODO: define your data members here.
};

struct server_message
{
    // TODO: define your data members here.
};

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
