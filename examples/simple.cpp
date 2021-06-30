#include "web3.h"
#include <iostreamt

int main(int argc, char* argv[]) {
    web3::Web3 web3;

    //web3.SetProvider("http://localhost:22023");
    web3.SetProvider("https://ropsten.infura.io/v3/d0391933f658431c867694f849396346");

    //web3.Launch();

    std::cout << "finished" << "\n";
    web3.Eth()->Call("hello", "1");

    return 0;
}
