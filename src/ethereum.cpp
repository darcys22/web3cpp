#include "web3cpp_interfaces.h"

namespace web3 {

//-------------------------------------------------------------------------------------------------
// EthImp: An implementation of EthInterface.
//-------------------------------------------------------------------------------------------------

class EthImp : public EthInterface {
public:

    uint8_t GetProtocolVersion() const = final { return 0; }

    uint64_t GetGasPrice() const = final { return 0; }

    uint64_t GetBlockNumber() const = final { return 0; }

}

} // namespace web3
