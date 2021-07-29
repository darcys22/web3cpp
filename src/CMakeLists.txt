add_library(libweb3cpp
  STATIC
  web3.cpp
  ethereum.cpp
  Data.cpp
  Hash.cpp
  BinaryCoding.cpp
)

set_target_properties(libweb3cpp PROPERTIES OUTPUT_NAME web3cpp)
include_directories("../include")

target_link_libraries(libweb3cpp  PUBLIC
  nlohmann_json::nlohmann_json
  cpr
)

target_link_libraries(libweb3cpp PRIVATE
  TrezorCrypto Boost::boost)
