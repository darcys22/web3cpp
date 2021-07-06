include_directories("../include")

file(GLOB test_SRC
    "*.h"
    "*.cc"
    "*.cpp"
)

#all_tests
add_executable(all_tests ${test_SRC})
set_target_properties(all_tests PROPERTIES FOLDER tests)

target_link_libraries(all_tests libweb3cpp)
