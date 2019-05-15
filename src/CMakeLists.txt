# Include source files and the generated files
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include(ExternalAntlr4Cpp)

# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})


# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ../lib/antlr-4.7.2-complete.jar)
find_package(ANTLR REQUIRED)


antlr_target(Slang Slang.g4
             PACKAGE slang_parser
             OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/parser
             VISITOR
             )

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

message("antlr outputs: " ${ANTLR_Slang_CXX_OUTPUTS})


message("G-TEST CMAKE")
configure_file(CMakeList.gtest.txt.in googletest-download/CMakeLists.txt)

# Download and unpack googletest at configure time
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

enable_testing()

add_test( NAME runUnitTests COMMAND runUnitTests)

file(GLOB AST_SRC
    "ast/*.h"
    "ast/*.cpp"
)

set(ALL_SRC 
  SlangAstBuilder.cpp 
  StringParser.cpp
  ${ANTLR_Slang_CXX_OUTPUTS}
  ${AST_SRC}
  )

#unit tests executable
ADD_EXECUTABLE(runUnitTests
  test/ParserTest.cpp
  test/PouParserTests.cpp
  ${ALL_SRC}
  )

target_link_libraries(runUnitTests antlr4_static gtest_main ${llvm_libs})

# main executable
add_executable(main
  main.cpp 
  ${ALL_SRC}
)

target_link_libraries(main antlr4_static ${llvm_libs})

#include(GTest)