// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "ethereum/Address.h"
#include "ethereum/RLP.h"
#include "ethereum/Signer.h"
#include "HexCoding.h"

#include <gtest/gtest.h>

namespace web3::ethereum {

using boost::multiprecision::uint256_t;


TEST(EthereumTransaction, encodeTransactionNonTyped) {
    auto transaction = TransactionNonTyped::buildERC20Transfer(
        /* nonce: */ 0,
        /* gasPrice: */ 42000000000, // 0x09c7652400
        /* gasLimit: */ 78009, // 130B9
        /* tokenContract: */ parse_hex("0x6b175474e89094c44da98b954eedeac495271d0f"), // DAI
        /* toAddress: */ parse_hex("0x5322b34c88ed0691971bf52a7047448f0f4efc84"),
        /* amount: */ 2000000000000000000
    );
    uint256_t dummyChain = 0x34;
    auto dummySignature = Signature{0, 0, 0};

    auto preHash = transaction->preHash(dummyChain);
    EXPECT_EQ(hex(preHash), "b3525019dc367d3ecac48905f9a95ff3550c25a24823db765f92cae2dec7ebfd");
    
    auto encoded = transaction->encoded(dummySignature, dummyChain);
    EXPECT_EQ(hex(encoded), "f86a808509c7652400830130b9946b175474e89094c44da98b954eedeac495271d0f80b844a9059cbb0000000000000000000000005322b34c88ed0691971bf52a7047448f0f4efc840000000000000000000000000000000000000000000000001bc16d674ec80000808080");
}

TEST(EthereumSigner, PreHash) {
    auto address = parse_hex("0x3535353535353535353535353535353535353535");
    auto transaction = TransactionNonTyped::buildNativeTransfer(
        /* nonce: */ 9,
        /* gasPrice: */ 20000000000,
        /* gasLimit: */ 21000,
        /* to: */ address,
        /* amount: */ 1000000000000000000
    );
    auto preHash = transaction->preHash(1);
    
    ASSERT_EQ(hex(preHash), "daf5a779ae972f972197303d7b574746c7ef83eadac0f2791ad23db92e4c8e53");
}

TEST(EthereumSigner, Sign) {
    auto address = parse_hex("0x3535353535353535353535353535353535353535");
    auto transaction = TransactionNonTyped::buildNativeTransfer(
        /* nonce: */ 9,
        /* gasPrice: */ 20000000000,
        /* gasLimit: */ 21000,
        /* to: */ address,
        /* amount: */ 1000000000000000000
    );

    auto key = PrivateKey(parse_hex("0x4646464646464646464646464646464646464646464646464646464646464646"));
    auto signature = Signer::sign(key, 1, transaction);

    ASSERT_EQ(signature.v, 37);
    ASSERT_EQ(signature.r, uint256_t("18515461264373351373200002665853028612451056578545711640558177340181847433846"));
    ASSERT_EQ(signature.s, uint256_t("46948507304638947509940763649030358759909902576025900602547168820602576006531"));
}

TEST(EthereumSigner, SignERC20Transfer) {
    auto transaction = TransactionNonTyped::buildERC20Transfer(
        /* nonce: */ 0,
        /* gasPrice: */ 42000000000, // 0x09c7652400
        /* gasLimit: */ 78009, // 130B9
        /* tokenContract: */ parse_hex("0x6b175474e89094c44da98b954eedeac495271d0f"), // DAI
        /* toAddress: */ parse_hex("0x5322b34c88ed0691971bf52a7047448f0f4efc84"),
        /* amount: */ 2000000000000000000
    );

    auto key = PrivateKey(parse_hex("0x608dcb1742bb3fb7aec002074e3420e4fab7d00cced79ccdac53ed5b27138151"));
    auto signature = Signer::sign(key, 1, transaction);

    ASSERT_EQ(signature.v, 37);
    ASSERT_EQ(hex(web3::store(signature.r)), "724c62ad4fbf47346b02de06e603e013f26f26b56fdc0be7ba3d6273401d98ce");
    ASSERT_EQ(hex(web3::store(signature.s)), "032131cae15da7ddcda66963e8bef51ca0d9962bfef0547d3f02597a4a58c931");
}

} // namespace web3::ethereum
