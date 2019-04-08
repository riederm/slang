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
             )

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

message("antlr outputs: " ${ANTLR_Slang_CXX_OUTPUTS})

# add generated grammar to demo binary target
add_executable(main
  main.cpp
  ${ANTLR_Slang_CXX_OUTPUTS}
)

target_link_libraries(main antlr4_static)