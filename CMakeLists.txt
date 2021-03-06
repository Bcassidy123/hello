cmake_minimum_required(VERSION 3.12)

project ("hello" 
    LANGUAGES CXX
    VERSION 0.1.0)

set(INSTALL_INCLUDE_DIR include)
set(INSTALL_ARCHIVE_DIR lib/${CMAKE_PROJECT_NAME})
set(INSTALL_CONFIG_DIR lib/cmake/${CMAKE_PROJECT_NAME})
set(EXPORT_TARGET ${CMAKE_PROJECT_NAME}-targets)
set(CONFIG_NAME ${CMAKE_PROJECT_NAME}-config)

add_library(${CMAKE_PROJECT_NAME} STATIC
    include/hello.h src/hello.cpp
    )
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    )

install(DIRECTORY include/ 
	DESTINATION ${INSTALL_INCLUDE_DIR}
	FILES_MATCHING PATTERN "*.h"
	)
install(TARGETS ${CMAKE_PROJECT_NAME} 
	EXPORT ${EXPORT_TARGET}   
    ARCHIVE DESTINATION ${INSTALL_ARCHIVE_DIR}
    )

# INSTALL TARGETS
install(EXPORT ${EXPORT_TARGET}
	NAMESPACE ${CMAKE_PROJECT_NAME}:: 
	FILE ${EXPORT_TARGET}.cmake 
	DESTINATION ${INSTALL_CONFIG_DIR}
	)
# INSTALL CONFIG 
include(CMakePackageConfigHelpers)
# CONFIG
configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/${CONFIG_NAME}.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/${CONFIG_NAME}.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIG_DIR}
	)
# VERSION
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${CONFIG_NAME}-version.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
	)
install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${CONFIG_NAME}.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${CONFIG_NAME}-version.cmake"
  DESTINATION
    ${INSTALL_CONFIG_DIR}
	)