#ifndef CLIENT_CONNECTION_H
#define CLIENT_CONNECTION_H

#include <boost/asio.hpp>
#include <thread>
#include "GlobalVars.hpp"

void receiveData(boost::asio::ip::tcp::socket &sock);

void sendData(boost::asio::ip::tcp::socket &sock);

void initConnections();

#endif