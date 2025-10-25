cmake_minimum_required(VERSION 4.0)
project(wxTemplate)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_PREFIX_PATH C:/wxWidgets)
set(wxWidgets_ROOT_DIR C:/wxWidgets)
add_executable(wxTemplate WIN32
        main.cpp
        iconpool.h
        sample.rc sample.ico
        definitions.h
        wxTemplate.pot
        de.po
        de.po
)
find_package(wxWidgets REQUIRED COMPONENTS core base CONFIG)
target_link_libraries(wxTemplate PRIVATE ${wxWidgets_LIBRARIES})
set(TRANSLATION_DIR "${PROJECT_BINARY_DIR}/locale/de")

if(WIN32)
add_custom_command(TARGET wxTemplate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${TRANSLATION_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/de.mo" ${TRANSLATION_DIR}
)
endif()
