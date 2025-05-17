#include <arpa/inet.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <memory>

#include "Networking.hpp"

namespace TrashIRC2025
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
      Networking(const std::string serverAddressName, const uint16_t serverPort = 6697)
      {
	  serverAddress.sin_family = AF_INET;
	  serverAddress.sin_port = htons(serverPort);
	  if(inet_pton(AF_INET, serverAddressName.c_str(), &serverAddress.sin_addr) <= 0)
	  {
	    throw std::runtime_error("ERROR: Invalid Address.\n");
	  }
	  /*if(connect(getSocket(), (static_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress))) < 0)
	   */
	  if(connect(
	       this->socketFileDescriptor,
	       reinterpret_cast<struct sockaddr*>(&this->serverAddress),
	       sizeof(serverAddress)
	       ) < 0)
	  {
	    throw std::runtime_error("ERROR: Couldn't connect to the server.\n");
	  }
      }
      ~Networking()
      {
	if(shutdown(socketFileDescriptor, SHUT_RDWR) < 0)
	{
	  std::cerr << "ERROR: Couldn't shut down the socket" << std::endl;;
	}
	if(close(socketFileDescriptor) < 0)
	{
	  std::cerr << "ERROR: Couldn't close the socket" << std::endl;
	}
      }
      /*
	This method is supposed to send a message over the socket.
	In case it fails, the method returns false.
       */
      bool sendMessage(const std::string message)
      {
	if(send(this->socketFileDescriptor, message.c_str(), message.length(), 0) < 0) return false;
	else return true;
      }
      void sendInitMessageToServer()
      {
	const std::string initMessage = "NICK" + \
	  this->nick + \
	  "\r\n USER guest 0 * :" + \
	  this->realName;
	if(!sendMessage(initMessage))
	{
	  throw std::runtime_error("ERROR: Could not send Init Message\n");
	}
      }
    };
}
