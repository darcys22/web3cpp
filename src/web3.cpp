#include "web3.h"
#include "web3cpp_interfaces.h"
#include "ethereum.h"

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <iostream>
#include <cstdint>

// for convenience
using json = nlohmann::json;

namespace web3 {

// Implementation.
class Web3Imp {
public:
    Web3Imp();
    ~Web3Imp();

    std::unique_ptr<EthImp> Eth_imp_;

    std::string provider_path_ = "";
    int last_port_ = 0;
};

Web3Imp::Web3Imp() {}
Web3Imp::~Web3Imp() { }

// Web3.
Web3::Web3() {
    imp_ = new Web3Imp();
}

Web3::~Web3() {
    delete imp_;
}

void Web3::SetProvider(const std::string& provider) {
    imp_->provider_path_ = provider;
}

const EthInterface* Web3::Eth() const {
    return imp_->Eth_imp_.get();
}

void Web3::Launch() {

    int port_start = 22023;

    json empty_array_explicit = json::array();
    json payload = {
      {"method", "getheight"},
      {"params", empty_array_explicit}
    };

    cpr::Response r = cpr::Post(cpr::Url{imp_->provider_path_ + "/json_rpc"},
                   cpr::Body{payload.dump()},
                   cpr::Header{{"Content-Type", "json/application"}});

    std::cout << r.text << '\n';

    imp_->last_port_ = port_start;
}

} // namespace web3
