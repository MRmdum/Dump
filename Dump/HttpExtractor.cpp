#include "HttpExtractor.h"
#include "Database.h"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>


#include <boost/asio/strand.hpp>
#include <boost/lexical_cast.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <cstdlib>
#include <iostream>
#include <string>
#include <functional>
#include <memory>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

void HttpExtractor::extract(Database& database,map<string,string> parameters) {

    //might want to replace argv by parameters value
    int argc = 4;
    char* argv[] = {(char*)"./Dump",(char*)"localhost",(char*)"8000",(char*)"/",(char*)"aaaa"};

    try
    {
        // Check command line arguments.
        if (argc != 4 && argc != 5)
        {
            std::cerr <<
                "Usage: http-client-sync <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
                "Example:\n" <<
                "    http-client-sync www.example.com 80 /\n" <<
                "    http-client-sync www.example.com 80 / 1.0\n";
        }

        //value to replace by parameters
        auto const host = "localhost";//argv[1];
        auto const port = "8000";//argv[2];
        auto const target = "db.sqlite3";//argv[3];
        int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;


        // The io_context is required for all I/O
        boost::asio::io_context ioc;

        // These objects perform our I/O
        tcp::resolver resolver{ ioc };
        tcp::socket socket{ ioc };

        // Look up the domain name
        auto const results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
        boost::asio::connect(socket, results.begin(), results.end());

        // Set up an HTTP request message 
        // and type of the request
        http::request<http::string_body> req{  };
        req.version(version);
        req.target(target);
        req.method(http::verb::post);
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        //Writing the body field
        string dbStrTest = database.displayDatabase();
        const char* body = dbStrTest.c_str();        
        req.body() = body;

        //Set up the length field
        req.set(http::field::content_length, boost::lexical_cast<std::string>(strlen(body)));

        req.prepare_payload();

        // Send the HTTP request to the remote host
        http::write(socket, req);

        // This buffer is used for reading and must be persisted
        boost::beast::flat_buffer buffer;

        // Declare a container to hold the response
        http::response<http::dynamic_body> res;

        // Receive the HTTP response
        http::read(socket, buffer, res);

        // Write the message to standard out
        std::cout << res << std::endl;

        // Gracefully close the socket
        boost::system::error_code ec;
        socket.shutdown(tcp::socket::shutdown_both, ec);

        // not_connected happens sometimes

        if (ec && ec != boost::system::errc::not_connected)
            throw boost::system::system_error{ ec };

        // If we get here then the connection is closed gracefully
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}