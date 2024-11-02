add_executable(hello-tests test_hello.cpp)

if(DEFINED ENV{HW3_DEPS}) # local builds, use gtest from ext/gtest
    file(TO_CMAKE_PATH "$ENV{HW3_DEPS}/ext/gtest/output/${PLATFORM_BUILD_DIR}" gtest_DIR)
    message(STATUS "Package GTest::gtest root: ${gtest_DIR}")
    include(${gtest_DIR}/lib/cmake/GTest/GTestConfig.cmake)
else()
    find_package(GTest REQUIRED)
endif()

target_link_libraries(hello-tests PRIVATE hello GTest::gtest_main)

add_test(HelloTest "${CMAKE_INSTALL_PREFIX}/tests/hello-tests")

include(GNUInstallDirs)
install(
    TARGETS hello-tests COMPONENT tests
    PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    RUNTIME DESTINATION tests
)