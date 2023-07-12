#pragma once
#include <string>
#include <vector>
#include <functional>
#include <memory>

namespace Sasha
{
class Comm
{
    public: 
    /*
    * @brief creates a socket
    * @param url string
    * @param is server or client
    * @return pointer to a newly created server
    */
    static Comm *create(const std::string & url, bool isServer);
    
    /*
    * @brief sends and receives data in a form of a vector
    * @param send vector
    * @return receive vector
    */
    std::vector<uint8_t> send_recv(const std::vector<uint8_t> & dataToSend);
    
    /*
    * @brief automatic receive/send function for server-client applications
    * @param function that operates on a received data and produces outbound data
    * @return true if succeeded, false oterwise
    * @todo possibly change bool to status type
    */
    bool recv_send(std::function<std::vector<uint8_t>(std::vector<uint8_t>)>);
    private: 
    Comm();  
    struct Imp;
    std::unique_ptr<Imp> imp_;
};
} // Sasha