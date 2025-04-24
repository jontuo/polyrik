
#ifndef __SETTING_HPP_INCLUDED__
#define __SETTING_HPP_INCLUDED__

#include <cstdint>
#include <string>

const std::string SERVER_HOST = "127.0.0.1";
const std::uint16_t SERVER_PORT = 1234;
const std::size_t PEER_LIMIT = 1;
const std::size_t CHANNEL_LIMIT = 2;
const std::uint32_t INCOMING_BANDWIDTH_LIMIT = 0;
const std::uint32_t OUTGOING_BANDWIDTH_LIMIT = 0;

const unsigned int CHUNK_SIZE = 100;

#endif
