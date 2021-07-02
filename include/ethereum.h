#pragma once

#include <map>
#include <string>

namespace web3 {


class Ethereum {

public:
    uint8_t GetProtocolVersion() const; //call: 'eth_protocolVersion',
    uint64_t GetNodeInfo() const; //call: 'web3_clientVersion'
    uint64_t GetCoinbase() const; //call: 'eth_coinbase',
    uint64_t IsMining() const; //call: 'eth_mining',
    uint64_t GetHashrate() const; //call: 'eth_hashrate',
    uint64_t IsSyncing() const; //call: 'eth_syncing',
    uint64_t GetGasPrice() const; //call: 'eth_gasPrice',
    uint64_t GetAccounts() const; //call: 'eth_accounts',
    uint64_t GetBlockNumber() const; //call: 'eth_blockNumber',
    uint64_t GetBalance() const; //call: 'eth_getBalance',
    uint64_t GetBalance(std::string address, uint64_t block) const; //call: 'eth_getBalance',
    uint64_t GetBalance(std::string address, std::string block) const; //call: 'eth_getBalance',
    uint64_t GetStorageAt() const; //call: 'eth_getStorageAt',
    uint64_t GetCode() const; //call: 'eth_getCode',
    uint64_t GetBlock() const; //call: blockCall,
    uint64_t GetUncle() const; //call: uncleCall,
    uint64_t GetBlockTransactionCount() const; //call: getBlockTransactionCountCall,
    uint64_t GetBlockUncleCount() const; //call: uncleCountCall,
    uint64_t GetTransaction() const; //call: 'eth_getTransactionByHash',
    uint64_t GetTransactionFromBlock() const; //call: transactionFromBlockCall,
    uint64_t GetTransactionReceipt() const; //call: 'eth_getTransactionReceipt',
    uint64_t GetTransactionCount() const; //call: 'eth_getTransactionCount',
    uint64_t SendSignedTransaction() const; //call: 'eth_sendRawTransaction',
    uint64_t SignTransaction() const; //call: 'eth_signTransaction',
    uint64_t SendTransaction() const; //call: 'eth_sendTransaction',
    uint64_t Sign() const; //call: 'eth_sign',
    uint64_t Call() const; //call: 'eth_call',
    uint64_t EstimateGas() const; //call: 'eth_estimateGas',
    uint64_t SubmitWork() const; //call: 'eth_submitWork',
    uint64_t GetWork() const; //call: 'eth_getWork',
    uint64_t GetPastLogs() const; //call: 'eth_getLogs',
    uint64_t GetChainId() const; //call: 'eth_chainId',
    uint64_t RequestAccounts() const; //call: 'eth_requestAccounts',
    uint64_t GetProof() const; //call: 'eth_getProof',
    uint64_t GetPendingTransactions() const; //call: 'eth_pendingTransactions',
    
    std::optional<std::string> Call(std::string name, ...);

    std::string provider_path_ = "";
    int last_port_ = 0;
}; // Ethereum

} // namespace web3
