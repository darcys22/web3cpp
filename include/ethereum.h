#pragma once

#include "web3cpp_interfaces.h"

namespace web3 {

class EthImp : public EthInterface {

    uint8_t GetProtocolVersion();
    uint64_t GetGasPrice();
    uint64_t GetBlockNumber();
};

} // namespace web3
