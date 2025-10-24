cmake_minimum_required(VERSION 4.0)
project(wxTemplate)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH C:/wxWidgets)
set(wxWidgets_ROOT_DIR C:/wxWidgets)
add_executable(wxTemplate
        main.cpp
        iconpool.h
        sample.rc sample.ico
        snippets.h
)
find_package(wxWidgets REQUIRED COMPONENTS core base CONFIG)
target_link_libraries(wxTemplate PRIVATE ${wxWidgets_LIBRARIES})
