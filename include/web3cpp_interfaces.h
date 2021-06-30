#pragma once

#include <cstdint>
#include <optional>

//! The EthInterface allows us to interact with ethereum
class EthInterface {
public:
    virtual ~EthInterface() = default;

    virtual uint8_t GetProtocolVersion() const = 0;

    virtual uint64_t GetGasPrice() const = 0;

    virtual uint64_t GetBlockNumber() const = 0;

    virtual std::optional<std::string> Call(std::string name, std::string args...) const = 0;

};
