#include "web3.h"
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

    std::unique_ptr<Ethereum> Eth_imp_;

    std::string provider_path_ = "";
    int last_port_ = 0;
};

Web3Imp::Web3Imp() {
  Eth_imp_ = std::make_unique<Ethereum>();
}
Web3Imp::~Web3Imp() { 
  Eth_imp_.reset();
}

// Web3.
Web3::Web3() {
  imp_ = new Web3Imp();
}

Web3::~Web3() {
  delete imp_;
}

void Web3::SetProvider(const std::string& provider) {
  imp_->provider_path_ = provider;
  imp_->Eth_imp_->provider_path_ = provider;
}

const Ethereum* Web3::Eth() const {
  return imp_->Eth_imp_.get();
}

void Web3::Launch() {

  int port_start = 22023;

  json empty_array_explicit = json::array();
  json payload = {
    {"jsonrpc", "2.0"},
    {"method", "net_version"},
    {"params", empty_array_explicit},
    {"id", 1}
  };

  cpr::Response r = cpr::Post(cpr::Url{imp_->provider_path_},
                 cpr::Body{payload.dump()},
                 cpr::Header{{"Content-Type", "json/application"}});

  std::cout << r.text << '\n';

  imp_->last_port_ = port_start;
}

} // namespace web3
