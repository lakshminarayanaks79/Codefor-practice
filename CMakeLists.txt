cmake_minimum_required(VERSION 3.22)

project(HELLOAPP VERSION 1.1)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET (SRC_FILES 
    main.cpp 
    src/calc.cpp)

#SET (SRC_FILES "main.cpp;src/calc.cpp")
message(STATUS "Src ile has ${SRC_FILES}")

if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message("file exists")
else()
    message(FATAL_ERROR "file not exists")
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

add_executable(hellobinary ${SRC_FILES})

target_include_directories(hellobinary PUBLIC include/ lib/)

target_link_libraries(hellobinary PUBLIC wifi_lib)

#message(STATUS "PATH : $ENV{PATH}")

#message(STATUS "Show C++ standard : ${CMAKE_CXX_STANDARD}")
#message(STATUS "Show C++ standard : ${CMAKE_CXX_STANDARD_REQUIRED}")
# set value on Arugument option
#message(STATUS "Argument Value is ${MyValue}")

###################################################
set (PRODUCT_YEAR "2023")
target_include_directories(hellobinary PUBLIC ${PROJECT_BINARY_DIR})
##############################################################
# 1- if
# OFF 0 NO FALSE N "NOTFOUND" "IGNORE" ----> False
if(DEBUG)
    set(DEBUGINFO "author ABHINAV")
endif()


if(TARGET wifi_lib)
    message("wifi is avilable")
else()
    message(FATAL_ERROR "File not found")
endif()

#####################################################

foreach(F IN ITEMS ABHINAV )
    message(STATUS {F}) 
endforeach()

#############################################

function(happynewyear arg1)
    message("ARG1 ${arg1}") #name of the variable
    message("ARG1 ${${arg1}}") #show values of the list
    message("ARG1 ${ARGN}") #extra argument
    message("ARG1 ${ARGC}") #count
endfunction()
set(var 2 0 2 3 )
happynewyear(var jan)
 

####################################################
# complier info
target_compile_definitions(hellobinary PUBLIC "STD_CXX=17")
target_compile_options(hellobinary PUBLIC -march=native)

install(FILES "${PROJECT_BINARY_DIR}/hellobinary.exe"
    DESTINATION "${PROJECT_BINARY_DIR}/executable"
)

install(FILES 
    "${CMAKE_SOURCE_DIR}/lib/Wifi.hpp"
    "${CMAKE_SOURCE_DIR}/include/calc.hpp"
    DESTINATION "${PROJECT_BINARY_DIR}/include"
)

configure_file(defaultconfig.h.in defaultconfig.h)

######################################################
# file
#1-File
  # FILE(READ "main.cpp" MAIN_Text)
  # Message("${MAIN_Text}")
  # message("---------------------------------------")
  # FILE(STRINGS "main.cpp" MAIN_Text)
  # Message("${MAIN_Text}")
  # message("---------------------------------------")
  # FILE(STRINGS "main.cpp" MAIN_Text REGEX "^key.")
  # Message("${MAIN_Text}")
  # message("---------------------------------------")
  # file(GLOB_RECURSE SRCS "*.cpp")
  # message("${SRCS}")
####################################################

  #2-String
  # FILE(READ "main.cpp" MAIN_Text)
  # STRING(REGEX REPLACE "int" "void" OUT  ${MAIN_Text})
  # message("${OUT}")
####################################################
#3- macro
# set(gloablvariable 10)
# function(funname x)
#   message("${x}")
#   message("${${x}}")
#   set(gloablvariable 15 PARENT_SCOPE)
# endfunction()

# message("${gloablvariable}")
# funname(gloablvariable)
# message("${gloablvariable}")
####################################################
#4- break continue
# while(True)
#   message("hello")
#   continue()
# endwhile()

######################################################
#5-execute_process
execute_process(COMMAND "ls" PARENT_SCOPE)
# endfunction()

# message("${gloablvariable}")
# funname(gloablvariable)
# message("${gloablvariable}")
####################################################
#4- break continue
# while(True)
#   message("hello")
#   continue()
# endwhile()

######################################################
#5-execute_process
execute_process(COMMAND "ls" PARENT_SCOPE)
# endfunction()

# message("${gloablvariable}")
# funname(gloablvariable)
# message("${gloablvariable}")
####################################################
#4- break continue
# while(True)
#   message("hello")
#   continue()
# endwhile()

######################################################
#5-execute_process
execute_process(COMMAND "ls")