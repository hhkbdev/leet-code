#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#
#add_executable(MyTest test_code.cpp)
#
#target_link_libraries(MyTest PRIVATE MyLibrary ${GTEST_LIBRARIES})

enable_testing()

add_executable(test_code test_code.cpp)
target_link_libraries(test_code GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_code)
