cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDART ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

project(tree)

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
add_library(tree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/tree.cpp)

target_include_directories(tree PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} tree)
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin
    )
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

install(TARGETS tree 
    EXPORT tree-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT tree-config DESTINATION cmake)

if(BUILD_TESTS)
enable_testing()
file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
message(STATUS "PROJECT_NAME: [${PROJECT_NAME}]")
add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
message(STATUS "PROJECT_NAME_TEST_SOURCES: [${${PROJECT_NAME}_TEST_SOURCES}]")
target_link_libraries(check tree ${DEPENDS_LIBRARIES})
target_link_libraries(check ${PROJECT_NAME} ${DEPENDS_LIBRARIES})
message(STATUS "DEPENDS LIBS: [${DEPENDS_LIBRARIES}]")
add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
endif()


