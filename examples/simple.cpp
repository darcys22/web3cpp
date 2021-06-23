#include "web3.h"

int main(int argc, char* argv[]) {
    web3::Web3 web3;

    web3.SetProvider("http://localhost:22023");

    web3.Launch();

    return 0;
}
