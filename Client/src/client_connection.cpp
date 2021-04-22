
#include "../include/client_connection.hpp"

void receiveData(boost::asio::ip::tcp::socket &sock)
{
    std::string receiveDataSTR;
    while (true)
    {
        boost::asio::streambuf buff;
        boost::asio::read_until(sock, buff, "\n");
        receiveDataSTR = std::string(boost::asio::buffer_cast<const char *>(buff.data()));
        showGame(receiveDataSTR);
        if (winner)
        {
            break;
        }
    }
}

void sendData(boost ::asio::ip::tcp::socket &sock)
{
    std::string sendDataSTR;
    while (true)
    {
        getInput(sendDataSTR);
        sendDataSTR += "\n";
        sock.send(boost::asio::buffer(sendDataSTR));
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
