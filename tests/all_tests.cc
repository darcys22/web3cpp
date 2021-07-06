#include "test_get_balance.h"
#include "test_call.h"

#include <iostream>
#include <string>

#define TEST(X)                                                     \
    std::cout << "Running test: " << #X << std::endl;               \
    if (X(argc, argv)) {                                            \
        std::cout << "Test: " << #X << " succeeded." << std::endl;  \
    }                                                               \
    else {                                                          \
        success = false;                                            \
        std::cerr << "Test: " << #X << " failed!" << std::endl;     \
    }

//*************************************************************************************************
int main(int argc, char* argv[]) {
    bool success = true;

    // Add tests here.
    TEST(web3cpp::TestGetBalance);
    TEST(web3cpp::TestCall);

    if (success)
        std::cout << "All tests succeeded!" << std::endl;
    else
        std::cerr << "Some tests failed!" << std::endl;

    return success ? 0 : -1;
}
