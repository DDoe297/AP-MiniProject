
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
            std::exit(0);
        }
    }
}

void sendData(boost ::asio::ip::tcp::socket &sock)
{

    std::string sendDataSTR;
    while (true)
    {
        if (getInput(sendDataSTR))
        {

            sendDataSTR += "\n";

            sock.send(boost::asio::buffer(sendDataSTR));
        }
    }
}

void initConnections()
{
    boost::asio::io_service io;
    boost::asio::ip::tcp::socket sock(io);
    sock.connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

    boost::asio::streambuf buff;
    boost::asio::read_until(sock, buff, "\n");
    std::string data = std::string(boost::asio::buffer_cast<const char *>(buff.data()));
    std::istringstream split(data);
    std::string token;
    std::getline(split, token, ':');
    std::getline(split, token, ':');
    player = std::stoi(token);

    if (player == 1)
    {
        char palyerChoice;
        std::cout << "What Type of board do you want?" << std::endl
                  << "1. Small:" << std::endl
                  << "A-B-C\n| | |\nD-E-F\n| | |\nG-H-I\n\n"
                  << "2. Medium:" << std::endl
                  << "A---B---C\n|   |   |\n| D-E-F |\n| |   | |\nG-H   I-J\n| |   | |\n| K-L-M |\n|   |   |\nN---O---P\n\n"
                  << "3. Big:" << std::endl
                  << "A-----B-----C\n|     |     |\n| D---E---F |\n| |   |   | |\n| | G-H-I | |\n| | |   | | |\nJ-K-L   M-N-O\n| | |   | | |\n| | P---Q | |\n| |/     \\| |\n| R-------S |\n| /       \\ |\nT-----------U\n\n";
        std::cin >> palyerChoice;
        palyerChoice = tolower(palyerChoice);
        palyerChoice -= '0';
        data = outputClient(1, palyerChoice) + "\n";
        sock.send(boost::asio::buffer(data));
    }
    // else
    // {
    //     boost::asio::read_until(sock, buff, "\n");
    //     data = std::string(boost::asio::buffer_cast<const char *>(buff.data()));
    //     std::istringstream split(data);
    //     std::string token;
    //     std::getline(split, token, ':');
    //     std::getline(split, token, ':');
    //     gameType = std::stoi(token);

    // }
    std::thread t1(receiveData, std::ref(sock));
    std::thread t2(sendData, std::ref(sock));
    t1.join();
    t2.join();
}
