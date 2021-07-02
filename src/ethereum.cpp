#include "ethereum.h"

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <iostream>

using json = nlohmann::json;

namespace web3 {

//-------------------------------------------------------------------------------------------------
// Ethereum: manages calls to Ethereum RPC
//-------------------------------------------------------------------------------------------------

uint8_t Ethereum::GetProtocolVersion() const { 
//call: 'eth_protocolVersion',

  json empty_array_explicit = json::array();
  json payload = {
    {"jsonrpc", "2.0"},
    {"method", "net_version"},
    {"params", empty_array_explicit},
    {"id", 1}
  };

  cpr::Response r = cpr::Post(cpr::Url{provider_path_},
                 cpr::Body{payload.dump()},
                 cpr::Header{{"Content-Type", "json/application"}});

  std::cout << r.text << '\n';

  return 0; 
}

uint64_t Ethereum::GetNodeInfo() const { return 0; }; //call: 'web3_clientVersion'
uint64_t Ethereum::GetCoinbase() const { return 0; }; //call: 'eth_coinbase',
uint64_t Ethereum::IsMining() const { return 0; }; //call: 'eth_mining',
uint64_t Ethereum::GetHashrate() const { return 0; }; //call: 'eth_hashrate',
uint64_t Ethereum::IsSyncing() const { return 0; }; //call: 'eth_syncing',
uint64_t Ethereum::GetGasPrice() const { return 0; }; //call: 'eth_gasPrice',
uint64_t Ethereum::GetAccounts() const { return 0; }; //call: 'eth_accounts',
uint64_t Ethereum::GetBlockNumber() const { return 0; }; //call: 'eth_blockNumber','

uint64_t Ethereum::GetBalance(std::string address, uint64_t block) const { 
//call: 'eth_getBalance',

  json params = json::array({address, "latest"});

  json payload = {
    {"jsonrpc", "2.0"},
    {"method", "eth_getBalance"},
    {"params", params},
    {"id", 1}
  };

  cpr::Response r = cpr::Post(cpr::Url{provider_path_},
                 cpr::Body{payload.dump()},
                 cpr::Header{{"Content-Type", "json/application"}});

  std::cout << r.text << '\n';

  return 0; 
}; 

uint64_t Ethereum::GetBalance(std::string address, std::string block) const { 
//call: 'eth_getBalance',

  return 0; 
}; 
uint64_t Ethereum::GetStorageAt() const { return 0; }; //call: 'eth_getStorageAt',
uint64_t Ethereum::GetCode() const { return 0; }; //call: 'eth_getCode',
uint64_t Ethereum::GetBlock() const { return 0; }; //call: blockCall,
uint64_t Ethereum::GetUncle() const { return 0; }; //call: uncleCall,
uint64_t Ethereum::GetBlockTransactionCount() const { return 0; }; //call: getBlockTransactionCountCall,
uint64_t Ethereum::GetBlockUncleCount() const { return 0; }; //call: uncleCountCall,
uint64_t Ethereum::GetTransaction() const { return 0; }; //call: 'eth_getTransactionByHash',
uint64_t Ethereum::GetTransactionFromBlock() const { return 0; }; //call: transactionFromBlockCall,
uint64_t Ethereum::GetTransactionReceipt() const { return 0; }; //call: 'eth_getTransactionReceipt',
uint64_t Ethereum::GetTransactionCount() const { return 0; }; //call: 'eth_getTransactionCount',
uint64_t Ethereum::SendSignedTransaction() const { return 0; }; //call: 'eth_sendRawTransaction',
uint64_t Ethereum::SignTransaction() const { return 0; }; //call: 'eth_signTransaction',
uint64_t Ethereum::SendTransaction() const { return 0; }; //call: 'eth_sendTransaction',
uint64_t Ethereum::Sign() const { return 0; }; //call: 'eth_sign',
uint64_t Ethereum::Call() const { return 0; }; //call: 'eth_call',
uint64_t Ethereum::EstimateGas() const { return 0; }; //call: 'eth_estimateGas',
uint64_t Ethereum::SubmitWork() const { return 0; }; //call: 'eth_submitWork',
uint64_t Ethereum::GetWork() const { return 0; }; //call: 'eth_getWork',
uint64_t Ethereum::GetPastLogs() const { return 0; }; //call: 'eth_getLogs',
uint64_t Ethereum::GetChainId() const { return 0; }; //call: 'eth_chainId',
uint64_t Ethereum::RequestAccounts() const { return 0; }; //call: 'eth_requestAccounts',
uint64_t Ethereum::GetProof() const { return 0; }; //call: 'eth_getProof',
uint64_t Ethereum::GetPendingTransactions() const { return 0; }; //call: 'eth_pendingTransactions',

std::optional<std::string> Ethereum::Call(std::string name, ...) {

  return std::nullopt; 

} // Call()

} // namespace web3
