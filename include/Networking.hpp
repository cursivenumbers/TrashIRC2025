#ifndef NETWORKING_HPP
#define NETWORKING_HPP

#include <arpa/inet.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <vector>


namespace TrashIRC2005
{
  class Networking
  {
  private:
    struct sockaddr_in serverAddress;
    int32_t socketFileDescriptor;
    std::string receivedMessage;
  public:
     /* Default values for IRC, in case none were set. */
    std::string nick {"nobody"};
    std::string realName {"John Doe"};
    std::string substituteNick {"nobody_"};
    Networking(const std::string serverAddressName, const uint16_t serverPort = 6697);
    ~Networking();
    bool sendMessage(const std::string message);
    void sendInitMessageToServer();
  };
}

#endif // NETWORKING_HPP
