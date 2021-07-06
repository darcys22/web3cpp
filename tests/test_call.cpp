#include "web3.h"

#include <iostream>

namespace web3cpp {

//
// TestCall
//

bool TestCall(int argc, char** argv) {
  web3::Web3 web3;

  web3.SetProvider("https://ropsten.infura.io/v3/d0391933f658431c867694f849396346");

  std::string from_param = "0xb60e8dd61c5d32be8058bb8eb970870f07233155";
  std::string to_param = "0xd46e8dd67c5d32be8058bb8eb970870f07244567";
  std::string gas_param = "0x76c0";
  std::string gasPrice_param = "0x9184e72a000";
  std::string value_param = "0x9184e72a";
  std::string data = "0xd46e8dd67c5d32be8d46e8dd67c5d32be8058bb8eb970870f072445675058bb8eb970870f072445675";

  std::string block = "latest";


  std::string result = web3.Eth()->Call(from_param, to_param, gas_param, gasPrice_param, value_param, data, block);

  return result == "{\"jsonrpc\":\"2.0\",\"id\":1,\"result\":\"0x\"}";

}

} // namespace web3cpp

