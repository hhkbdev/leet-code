# add current dir all files to SRC_FILES variable
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# create static library
add_library(shape STATIC ${SRC_FILES})

# include directory for header files
target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/include)

# compile options
target_compile_options(shape PRIVATE -Wall -Werror)

# compile features
target_compile_features(shape PRIVATE cxx_std_17)

# fmt 라이브러리를 불러온다.
include(FetchContent)
FetchContent_Declare(
        Fmt
        GIT_REPOSITORY "https://github.com/fmtlib/fmt"
        GIT_TAG "7.1.3"
)
FetchContent_MakeAvailable(Fmt)

# fmt 라이브러리를 링크한다.
target_link_libraries(shape PRIVATE fmt)