include_directories("../include")

# Included for all examples
include_directories(SYSTEM "${PROJECT_BINARY_DIR}/generated")

# Function to generate an example project with extra libraries
function (example_project_extra project_name source_code extra_libs)
    message("Adding new example project ${project_name}, sources: ${source_code}, extra_libs: ${extra_libs}")
    file (GLOB example_project_sources ${source_code})
    add_executable(${project_name} ${example_project_sources})

    set_target_properties(${project_name} PROPERTIES FOLDER examples)

    target_link_libraries(${project_name} libweb3cpp ${extra_libs})
endfunction ()

# Function to generate a simple example project
function (example_project project_name source_code)
    example_project_extra(${project_name} ${source_code} "")
endfunction ()

example_project(simple "simple.cpp")
