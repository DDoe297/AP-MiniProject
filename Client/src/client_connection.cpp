#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include "../include/client_connection.hpp"
#include "../include/logger.hpp"

void receiveData(boost::asio::ip::tcp::socket &sock)
{
    while (true)
    {
        boost::asio::streambuf buff;
        boost::asio::read_until(sock, buff, "\n");
        std::cout << "server:" << boost::asio::buffer_cast<const char *>(buff.data()) << std::endl;
    }
}

void sendData(boost ::asio::ip::tcp::socket &sock)
{

    while (true)
    {
        std::string msg;
        std::cin >> msg;
        msg += "\n";
        sock.send(boost::asio::buffer(msg));
    }
}

void initConnections()
{
    boost::asio::io_service io;
    boost::asio::ip::tcp::socket sock(io);
    sock.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    DEBUG << "connected to server";
    std::thread t1(receiveData, std::ref(sock));
    std::thread t2(sendData, std::ref(sock));
    t1.join();
    t2.join();
}
