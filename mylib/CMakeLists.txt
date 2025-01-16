project(mylib)

set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

message(STATUS ${SOURCES})

set(HEADERS
   ${HEADER_DIR}/Foo.h
)
set(SOURCES
   ${SOURCE_DIR}/Foo.cpp
)

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