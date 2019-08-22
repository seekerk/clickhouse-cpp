project(clickhouse-cpp-lib VERSION 1.0 DESCRIPTION "C++ client for Yandex ClickHouse")

SET ( clickhouse-cpp-lib-src
    base/coded.cpp
    base/compressed.cpp
    base/input.cpp
    base/output.cpp
    base/platform.cpp
    base/socket.cpp

    columns/array.cpp
    columns/date.cpp
    columns/enum.cpp
    columns/factory.cpp
    columns/nullable.cpp
    columns/numeric.cpp
    columns/string.cpp
    columns/tuple.cpp
    columns/uuid.cpp

    types/type_parser.cpp
    types/types.cpp

    block.cpp
    client.cpp
    query.cpp
)

ADD_LIBRARY (${PROJECT_NAME} SHARED ${clickhouse-cpp-lib-src} clickhouse-cpp.pc)

SET_TARGET_PROPERTIES(${PROJECT_NAME}
    PROPERTIES LINKER_LANGUAGE CXX)

TARGET_LINK_LIBRARIES (${PROJECT_NAME}
    cityhash-lib
    lz4-lib
)

# correct library version
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_INCLUDE_DIR}")


ADD_LIBRARY (clickhouse-cpp-lib-static STATIC ${clickhouse-cpp-lib-src})
TARGET_LINK_LIBRARIES (clickhouse-cpp-lib-static
    cityhash-lib
    lz4-lib
)

set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")
CONFIGURE_FILE("clickhouse-cpp.pc.in" "clickhouse-cpp.pc" @ONLY)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
install(DIRECTORY . DESTINATION include/clickhouse-cpp FILES_MATCHING PATTERN "*.h")

set(INSTALL_PKGCONFIG_DIR "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" CACHE PATH "Installation directory for pkgconfig (.pc) files")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/clickhouse-cpp.pc DESTINATION "${INSTALL_PKGCONFIG_DIR}")
