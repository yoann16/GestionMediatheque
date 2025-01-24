project(mylib)

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

message(STATUS ${SOURCES})

set(HEADERS
   ${HEADER_DIR}/Api.h
   ${HEADER_DIR}/BaseType.h
   ${HEADER_DIR}/ClientAccount.h
   ${HEADER_DIR}/Command.h
   ${HEADER_DIR}/CommandFactory.h
   ${HEADER_DIR}/CommandManager.h
   ${HEADER_DIR}/Exception.h
   ${HEADER_DIR}/Interpreter.h
   ${HEADER_DIR}/Manager.h
)
set(SOURCES
   ${SOURCE_DIR}/Api.cpp
   ${SOURCE_DIR}/BaseType.cpp
   ${SOURCE_DIR}/ClientAccount.cpp
   ${SOURCE_DIR}/Command.cpp
   ${SOURCE_DIR}/CommandFactory.cpp
   ${SOURCE_DIR}/CommandManager.cpp
   ${SOURCE_DIR}/Exception.cpp
   ${SOURCE_DIR}/Interpreter.cpp
   ${SOURCE_DIR}/Manager.cpp
)

message(STATUS "SOURCES: ${SOURCES}")
add_library(${PROJECT_NAME}
STATIC
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME}
PUBLIC
     $<INSTALL_INTERFACE:include>
     $<BUILD_INTERFACE:${HEADER_DIR}>
    
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Libraries")