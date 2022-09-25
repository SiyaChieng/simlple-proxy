#include <string>
#include <iostream>

#include <boost/asio.hpp>

class ProxyServer {

public:
    ProxyServer(boost::asio::io_context& context, std::string& config_path, std::string ip, uint16_t port) {
        
    }

private:
    boost::asio::ip::tcp::acceptor acceptor_;
};

int main(int argc, char** argv) {
    if(argc < 3) {
        std::cerr << "usage: " << argv[0] << " CONFIG_PATH IP:PORT\n";
        exit(EXIT_FAILURE);
    }

    std::string str_config_path(argv[1]);
    std::string str_ip_port(argv[2]);

    auto loc = str_ip_port.find(':');
    if(loc == std::string::npos) {
        std::cerr << "IP:PORT invalid\n";
        exit(EXIT_FAILURE);
    }
    std::string str_ip = str_ip_port.substr(0, loc);
    std::string str_port = str_ip_port.substr(loc+1);

    std::cout << "config_path[" << str_config_path << "] ip[" 
        << str_ip << "] port[" << str_port << "]\n";

    return 0;
}
