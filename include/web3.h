#pragma once

#include "web3cpp_interfaces.h"

#include <string>
#include <cstdint>

namespace web3 {

class Web3Imp;

class Web3 {
public:
    Web3();
    ~Web3();

    //! Sets the path to the ethereum node.
    //! \param path Absolute file path.
    void SetProvider(const std::string& provider);

    //! The EthInterface is used to query the ethereum provider.
    const EthInterface* Eth() const;

    void Launch();

private:
    Web3Imp* imp_;
};

}
