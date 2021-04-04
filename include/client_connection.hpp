#ifndef CLIENT_CONNECTION_H
#define CLIENT_CONNECTION_H

#include <boost/asio.hpp>
#include <thread>




void receive(boost::asio::ip::tcp::socket &sock);

void send(boost ::asio::ip::tcp::socket &sock);

void initConnections();

#endif