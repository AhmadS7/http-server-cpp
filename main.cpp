// Including required headers
#include <iostream>
#include <boost/asio.hpp>

int main() {
    // Create an I/O service
    // setting up the Boost.Asio I/O service, this manages asynchronous operations.
    boost::asio::io_service io_service;

    // Create an acceptor
    // an acceptor to listen to incoming connections, 8080 is the port number
    boost::asio::ip::tcp::acceptor acceptor(io_service,
                                            boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8080));

    // Handle connections
    // accept incoming connections and handle them asynchronously
    boost::asio::ip::tcp::socket socket(io_service);
    acceptor.accept(socket);

    // Implement HTTP server logic
    // define your HTTP server logic inside the asynchronous handler, parse incoming requests
    // generate responses, and handle various HTTP methods
    std::string message = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
    boost::asio::write(socket, boost::asio::buffer(message));

    // Run I/O service
    io_service.run();
}
