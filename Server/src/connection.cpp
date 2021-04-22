#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <boost/asio.hpp>
#include <chrono>
#include <thread>
#include "../include/connection.hpp"
#include "../include/logger.hpp"
#include "../include/game.hpp"
#include "../include/data_parser.hpp"

void playerOneReceive(boost::asio::ip::tcp::socket &sock, XnO::Game &game)
{
    while (true)
    {
        boost::asio::streambuf buff;
        boost::asio::read_until(sock, buff, "\n");
        int place = inputServer(std::string(boost::asio::buffer_cast<const char *>(buff.data())));
        game.play(place);
    }
}

void playerOneSend(boost ::asio::ip::tcp::socket &sock, XnO::Game &game)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int winner = game.board->checkWinner();
        if (winner != 1)
        {
            std::string msg = outputServer(3, winner);
            msg += "\n";
            sock.send(boost::asio::buffer(msg));
            break;
        }
        int gameType = 0;
        if (game.board->getType() == XnO::small)
        {
            gameType = 1;
        }
        else if (game.board->getType() == XnO::medium)
        {
            gameType = 2;
        }
        else if (game.board->getType() == XnO::big)
        {
            gameType = 3;
        }
        std::string msg = outputServer(gameType, game.board->getTiles(), (game.getTurn() == XnO::Player1) ? 1 : 2, game.player1->getRemainTime());
        //std::cin >> msg;
        game.player1->setRemainTime(game.player1->getRemainTime() - 1);
        msg += "\n";
        sock.send(boost::asio::buffer(msg));
    }
}

void playerTwoReceive(boost::asio::ip::tcp::socket &sock, XnO::Game &game)
{
    while (true)
    {
        boost::asio::streambuf buff;
        boost::asio::read_until(sock, buff, "\n");
        int place = inputServer(std::string(boost::asio::buffer_cast<const char *>(buff.data())));
        game.play(place);
    }
}

void playerTwoSend(boost ::asio::ip::tcp::socket &sock, XnO::Game &game)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int winner = game.board->checkWinner();
        if (winner != 1)
        {
            std::string msg = outputServer(3, winner);
            msg += "\n";
            sock.send(boost::asio::buffer(msg));
            break;
        }
        int gameType = 0;
        if (game.board->getType() == XnO::small)
        {
            gameType = 1;
        }
        else if (game.board->getType() == XnO::medium)
        {
            gameType = 2;
        }
        else if (game.board->getType() == XnO::big)
        {
            gameType = 3;
        }
        std::string msg = outputServer(gameType, game.board->getTiles(), (game.getTurn() == XnO::Player1) ? 1 : 2, game.player2->getRemainTime());
        //std::cin >> msg;
        game.player2->setRemainTime(game.player2->getRemainTime() - 1);
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
    playerOneSock.send(boost::asio::buffer(outputServer(1, 1) + "\n"));
    boost::asio::streambuf buff;
    boost::asio::read_until(playerOneSock, buff, "\n");
    int gameType = inputServer(std::string(boost::asio::buffer_cast<const char *>(buff.data())));

    XnO::Game game((gameType == 1) ? XnO::small : (gameType == 2) ? XnO::medium
                                                                  : XnO::big);

    acc.accept(playerTwoSock);

    std::thread playerOneR(playerOneReceive, std::ref(playerOneSock), std::ref(game));

    std::thread playerOneS(playerOneSend, std::ref(playerOneSock), std::ref(game));

    std::thread playerTwoR(playerTwoReceive, std::ref(playerTwoSock), std::ref(game));
    std::thread playerTwoS(playerTwoSend, std::ref(playerTwoSock), std::ref(game));
    playerTwoR.join();
    playerTwoS.join();
    playerOneR.join();
    playerOneS.join();
}

#endif