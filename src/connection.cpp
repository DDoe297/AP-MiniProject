#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <boost/asio.hpp>
#include <chrono>
#include <thread>
#include "../include/connection.hpp"
#include "../include/logger.hpp"

void playerOneReceive(boost::asio::ip::tcp::socket &sock)
{
    while (true)
    {
        boost::asio::streambuf buff;
        boost::asio::read_until(sock, buff, "\n");
        std::cout << "client1:" << boost::asio::buffer_cast<const char *>(buff.data()) << std::endl;
    }
}

void playerOneSend(boost ::asio::ip::tcp::socket &sock)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::string msg = "player one test messsage";
        //std::cin >> msg;
        msg += "\n";
        sock.send(boost::asio::buffer(msg));
    }
}

void playerTwoReceive(boost::asio::ip::tcp::socket &sock)
{
    while (true)
    {
        boost::asio::streambuf buff;
        boost::asio::read_until(sock, buff, "\n");
        std::cout << "client2:" << boost::asio::buffer_cast<const char *>(buff.data()) << std::endl;
    }
}

void playerTwoSend(boost ::asio::ip::tcp::socket &sock)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::string msg = "player two test messsage";
        // std::cin >> msg;
        msg += "\n";
        sock.send(boost::asio::buffer(msg));
    }
}

void initConnections()
{
    boost::asio::io_service io;
    

    boost::asio::ip::tcp::socket playerOneSock(io);
    boost::asio::ip::tcp::socket playerTwoSock(io);

    // boost::asio::ip::tcp::acceptor acc(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234));
    boost::asio::ip::tcp::acceptor acc(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    DEBUG << "waiting for player one";
    acc.accept(playerOneSock);
    DEBUG << "player one joined";

    std::thread playerOneR(playerOneReceive, std::ref(playerOneSock));
    DEBUG << "thread are constructed";
    std::thread playerOneS(playerOneSend, std::ref(playerOneSock));
    DEBUG << "thread are constructed";

    DEBUG << "player one threads are online ";

    DEBUG << "waiting for player two";

    acc.accept(playerTwoSock);
    DEBUG << "player two joined";

    std::thread playerTwoR(playerTwoReceive, std::ref(playerTwoSock));
    std::thread playerTwoS(playerTwoSend, std::ref(playerTwoSock));
    playerTwoR.join();
    playerTwoS.join();
    playerOneR.join();
    playerOneS.join();
    DEBUG << "player two threads are online ";
}

#endif