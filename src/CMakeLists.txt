
add_library(hello STATIC hello.cpp)
target_compile_features(hello PUBLIC cxx_std_17)
target_include_directories(hello INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(helloworld_cli main.cpp)
target_link_libraries(helloworld_cli hello)

include(GNUInstallDirs)
install(
    TARGETS helloworld_cli COMPONENT app
    PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
