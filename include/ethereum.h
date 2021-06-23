#pragma once

#include "web3cpp_interfaces.h"

#include <map>
#include <string>

namespace web3 {

class Core_Method {

public:

    std::string name_ = "";
    std::string call_ = "";

    uint8_t params_ = 0;

    Core_Method(std::string n, std::string c, uint8_t p): name_(n),call_(c),params_(p) {};
    //~Core_Method();

//var Method = function Method(options) {

    //if (!options.call || !options.name) {
        //throw new Error('When creating a method you need to provide at least the "name" and "call" property.');
    //}

    //this.name = options.name;
    //this.call = options.call;
    //this.params = options.params || 0;
    //this.inputFormatter = options.inputFormatter;
    //this.outputFormatter = options.outputFormatter;
    //this.transformPayload = options.transformPayload;
    //this.extraFormatters = options.extraFormatters;
    //this.abiCoder = options.abiCoder; // Will be used to encode the revert reason string


    //// reference to eth.accounts
    //this.accounts = options.accounts;

    //this.defaultBlock = options.defaultBlock || 'latest';
    //this.defaultAccount = options.defaultAccount || null;
    //this.transactionBlockTimeout = options.transactionBlockTimeout || 50;
    //this.transactionConfirmationBlocks = options.transactionConfirmationBlocks || 24;
    //this.transactionPollingTimeout = options.transactionPollingTimeout || 750;
    //this.defaultCommon = options.defaultCommon;
    //this.defaultChain = options.defaultChain;
    //this.defaultHardfork = options.defaultHardfork;
    //this.handleRevert = options.handleRevert;
//};

};

std::map<std::string, Core_Method> methods = {{"getProtocolVersion", Core_Method("getProtocolVersion", "eth_protocolVersion", 0)}};


    //var methods = [
        //new Method({
            //name: 'getNodeInfo',
            //call: 'web3_clientVersion'
        //}),
        //new Method({
            //name: 'getProtocolVersion',
            //call: 'eth_protocolVersion',
            //params: 0
        //}),
        //new Method({
            //name: 'getCoinbase',
            //call: 'eth_coinbase',
            //params: 0
        //}),
        //new Method({
            //name: 'isMining',
            //call: 'eth_mining',
            //params: 0
        //}),
        //new Method({
            //name: 'getHashrate',
            //call: 'eth_hashrate',
            //params: 0,
            //outputFormatter: utils.hexToNumber
        //}),
        //new Method({
            //name: 'isSyncing',
            //call: 'eth_syncing',
            //params: 0,
            //outputFormatter: formatter.outputSyncingFormatter
        //}),
        //new Method({
            //name: 'getGasPrice',
            //call: 'eth_gasPrice',
            //params: 0,
            //outputFormatter: formatter.outputBigNumberFormatter
        //}),
        //new Method({
            //name: 'getAccounts',
            //call: 'eth_accounts',
            //params: 0,
            //outputFormatter: utils.toChecksumAddress
        //}),
        //new Method({
            //name: 'getBlockNumber',
            //call: 'eth_blockNumber',
            //params: 0,
            //outputFormatter: utils.hexToNumber
        //}),
        //new Method({
            //name: 'getBalance',
            //call: 'eth_getBalance',
            //params: 2,
            //inputFormatter: [formatter.inputAddressFormatter, formatter.inputDefaultBlockNumberFormatter],
            //outputFormatter: formatter.outputBigNumberFormatter
        //}),
        //new Method({
            //name: 'getStorageAt',
            //call: 'eth_getStorageAt',
            //params: 3,
            //inputFormatter: [formatter.inputAddressFormatter, utils.numberToHex, formatter.inputDefaultBlockNumberFormatter]
        //}),
        //new Method({
            //name: 'getCode',
            //call: 'eth_getCode',
            //params: 2,
            //inputFormatter: [formatter.inputAddressFormatter, formatter.inputDefaultBlockNumberFormatter]
        //}),
        //new Method({
            //name: 'getBlock',
            //call: blockCall,
            //params: 2,
            //inputFormatter: [formatter.inputBlockNumberFormatter, function (val) { return !!val; }],
            //outputFormatter: formatter.outputBlockFormatter
        //}),
        //new Method({
            //name: 'getUncle',
            //call: uncleCall,
            //params: 2,
            //inputFormatter: [formatter.inputBlockNumberFormatter, utils.numberToHex],
            //outputFormatter: formatter.outputBlockFormatter,

        //}),
        //new Method({
            //name: 'getBlockTransactionCount',
            //call: getBlockTransactionCountCall,
            //params: 1,
            //inputFormatter: [formatter.inputBlockNumberFormatter],
            //outputFormatter: utils.hexToNumber
        //}),
        //new Method({
            //name: 'getBlockUncleCount',
            //call: uncleCountCall,
            //params: 1,
            //inputFormatter: [formatter.inputBlockNumberFormatter],
            //outputFormatter: utils.hexToNumber
        //}),
        //new Method({
            //name: 'getTransaction',
            //call: 'eth_getTransactionByHash',
            //params: 1,
            //inputFormatter: [null],
            //outputFormatter: formatter.outputTransactionFormatter
        //}),
        //new Method({
            //name: 'getTransactionFromBlock',
            //call: transactionFromBlockCall,
            //params: 2,
            //inputFormatter: [formatter.inputBlockNumberFormatter, utils.numberToHex],
            //outputFormatter: formatter.outputTransactionFormatter
        //}),
        //new Method({
            //name: 'getTransactionReceipt',
            //call: 'eth_getTransactionReceipt',
            //params: 1,
            //inputFormatter: [null],
            //outputFormatter: formatter.outputTransactionReceiptFormatter
        //}),
        //new Method({
            //name: 'getTransactionCount',
            //call: 'eth_getTransactionCount',
            //params: 2,
            //inputFormatter: [formatter.inputAddressFormatter, formatter.inputDefaultBlockNumberFormatter],
            //outputFormatter: utils.hexToNumber
        //}),
        //new Method({
            //name: 'sendSignedTransaction',
            //call: 'eth_sendRawTransaction',
            //params: 1,
            //inputFormatter: [null],
            //abiCoder: abi
        //}),
        //new Method({
            //name: 'signTransaction',
            //call: 'eth_signTransaction',
            //params: 1,
            //inputFormatter: [formatter.inputTransactionFormatter]
        //}),
        //new Method({
            //name: 'sendTransaction',
            //call: 'eth_sendTransaction',
            //params: 1,
            //inputFormatter: [formatter.inputTransactionFormatter],
            //abiCoder: abi
        //}),
        //new Method({
            //name: 'sign',
            //call: 'eth_sign',
            //params: 2,
            //inputFormatter: [formatter.inputSignFormatter, formatter.inputAddressFormatter],
            //transformPayload: function (payload) {
                //payload.params.reverse();
                //return payload;
            //}
        //}),
        //new Method({
            //name: 'call',
            //call: 'eth_call',
            //params: 2,
            //inputFormatter: [formatter.inputCallFormatter, formatter.inputDefaultBlockNumberFormatter],
            //abiCoder: abi
        //}),
        //new Method({
            //name: 'estimateGas',
            //call: 'eth_estimateGas',
            //params: 1,
            //inputFormatter: [formatter.inputCallFormatter],
            //outputFormatter: utils.hexToNumber
        //}),
        //new Method({
            //name: 'submitWork',
            //call: 'eth_submitWork',
            //params: 3
        //}),
        //new Method({
            //name: 'getWork',
            //call: 'eth_getWork',
            //params: 0
        //}),
        //new Method({
            //name: 'getPastLogs',
            //call: 'eth_getLogs',
            //params: 1,
            //inputFormatter: [formatter.inputLogFormatter],
            //outputFormatter: formatter.outputLogFormatter
        //}),
        //new Method({
            //name: 'getChainId',
            //call: 'eth_chainId',
            //params: 0,
            //outputFormatter: utils.hexToNumber
        //}),
        //new Method({
            //name: 'requestAccounts',
            //call: 'eth_requestAccounts',
            //params: 0,
            //outputFormatter: utils.toChecksumAddress
        //}),
        //new Method({
            //name: 'getProof',
            //call: 'eth_getProof',
            //params: 3,
            //inputFormatter: [formatter.inputAddressFormatter, formatter.inputStorageKeysFormatter, formatter.inputDefaultBlockNumberFormatter],
            //outputFormatter: formatter.outputProofFormatter
        //}),
        //new Method({
            //name: 'getPendingTransactions',
            //call: 'eth_pendingTransactions',
            //params: 0,
            //outputFormatter: formatter.outputTransactionFormatter
        //}),

class EthImp : public EthInterface {

    uint8_t GetProtocolVersion();
    uint64_t GetGasPrice();
    uint64_t GetBlockNumber();
};

} // namespace web3
