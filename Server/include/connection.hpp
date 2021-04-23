#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio.hpp>
#include <thread>

extern int timeWinner;

void playerOneReceive(boost::asio::ip::tcp::socket &sock);

void playerOneSend(boost ::asio::ip::tcp::socket &sock);

void playerTwoReceive(boost::asio::ip::tcp::socket &sock);

void playerTwoSend(boost ::asio::ip::tcp::socket &sock);

void initConnections();

#endif