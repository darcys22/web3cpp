#include "web3cpp_interfaces.h"

#include <cstdarg>

namespace web3 {

//-------------------------------------------------------------------------------------------------
// EthImp: An implementation of EthInterface.
//-------------------------------------------------------------------------------------------------

class EthImp : public EthInterface {
public:

    uint8_t GetProtocolVersion() const = final { return 0; }

    uint64_t GetGasPrice() const = final { return 0; }

    uint64_t GetBlockNumber() const = final { return 0; }

    std::optional<std::string> Call(std::string name, ...) = final {

      method = methods["getProtocolVersion"];

      int i,val;
      va_list args;

      std::cout << "finished" << "\n";
      va_start(args, method.param_count);

      std::cout << va_arg(va, int) << "\n";

      va_end(args);

      std::cout << "finished" << "\n";

      return std::nullopt; 

    } // Call()

} // class EthImp

} // namespace web3
