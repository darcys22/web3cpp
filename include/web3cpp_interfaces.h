#pragma once

#include <cstdint>

//! The EthInterface allows us to interact with ethereum
class EthInterface {
public:
    virtual ~EthInterface() = default;

    virtual uint8_t GetProtocolVersion() const = 0;

    virtual uint64_t GetGasPrice() const = 0;

    virtual uint64_t GetBlockNumber() const = 0;

};
