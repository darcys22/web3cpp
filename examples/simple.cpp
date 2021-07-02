#include "web3.h"
#include <iostream>

int main(int argc, char* argv[]) {
    web3::Web3 web3;

    //web3.SetProvider("http://localhost:22023");
    web3.SetProvider("https://ropsten.infura.io/v3/d0391933f658431c867694f849396346");

    //web3.Launch();

    std::cout << "finished" << "\n";
    web3.Eth()->GetBalance("0x407d73d8a49eeb85d32cf465507dd71d507100c1", 0);

    return 0;
}
