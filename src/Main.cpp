#include <arpa/inet.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <vector>

#include "Networking.hpp"

static constexpr inline void outputHelp()
{
  std::cout << "./trashirc2025 [OPTIONS]\n";
  std::cout << "Short options:\n";
  std::cout << "-s | Specify the server to connect to | (required)\n";
  std::cout << "-p | Specify the port to connect to | (optional)\n";
  std::cout << "-n | Specify the nick to be used | (required)\n";
  std::cout << "-rn | Specify your real name | (optional)\n";
  std::cout << "(default to John Doe if not given)\n";
  std::cout << "Long options:\n";
  std::cout << "--help | Invoke this help message\n";
}
int main()
{

  Networking networkingObj("127.0.0.1", 6697);
  
  return EXIT_SUCCESS;
}
