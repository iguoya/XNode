

# Conan automatically generated toolchain file
# DO NOT EDIT MANUALLY, it will be overwritten

# Avoid including toolchain file several times (bad if appending to variables like
#   CMAKE_CXX_FLAGS. See https://github.com/android/ndk/issues/323
include_guard()

message(STATUS "Using Conan toolchain: ${CMAKE_CURRENT_LIST_FILE}")

if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeToolchain' generator only works with CMake >= 3.15")
endif()










string(APPEND CONAN_CXX_FLAGS " -m64")
string(APPEND CONAN_C_FLAGS " -m64")
string(APPEND CONAN_SHARED_LINKER_FLAGS " -m64")
string(APPEND CONAN_EXE_LINKER_FLAGS " -m64")



message(STATUS "Conan toolchain: C++ Standard 17 with extensions ON")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Extra c, cxx, linkflags and defines


if(DEFINED CONAN_CXX_FLAGS)
  string(APPEND CMAKE_CXX_FLAGS_INIT " ${CONAN_CXX_FLAGS}")
endif()
if(DEFINED CONAN_C_FLAGS)
  string(APPEND CMAKE_C_FLAGS_INIT " ${CONAN_C_FLAGS}")
endif()
if(DEFINED CONAN_SHARED_LINKER_FLAGS)
  string(APPEND CMAKE_SHARED_LINKER_FLAGS_INIT " ${CONAN_SHARED_LINKER_FLAGS}")
endif()
if(DEFINED CONAN_EXE_LINKER_FLAGS)
  string(APPEND CMAKE_EXE_LINKER_FLAGS_INIT " ${CONAN_EXE_LINKER_FLAGS}")
endif()

get_property( _CMAKE_IN_TRY_COMPILE GLOBAL PROPERTY IN_TRY_COMPILE )
if(_CMAKE_IN_TRY_COMPILE)
    message(STATUS "Running toolchain IN_TRY_COMPILE")
    return()
endif()

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

# Definition of CMAKE_MODULE_PATH
# the generators folder (where conan generates files, like this toolchain)
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

# Definition of CMAKE_PREFIX_PATH, CMAKE_XXXXX_PATH
# The Conan local "generators" folder, where this toolchain is saved.
list(PREPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR} )
list(PREPEND CMAKE_LIBRARY_PATH "/home/tiger/.conan2/p/poco0f8a6250ece3f/p/lib" "/home/tiger/.conan2/p/pcre27ea830da3beb2/p/lib" "/home/tiger/.conan2/p/bzip26d48265eb59fb/p/lib" "/home/tiger/.conan2/p/expat7da784642e3d5/p/lib" "/home/tiger/.conan2/p/sqlit901a58a890604/p/lib" "/home/tiger/.conan2/p/libpq1579916154fff/p/lib" "/home/tiger/.conan2/p/libmy5a95d901c3d4f/p/lib" "/home/tiger/.conan2/p/opens3d01fe559d02c/p/lib" "/home/tiger/.conan2/p/zlib10e4879147c91/p/lib" "/home/tiger/.conan2/p/zstd7cecd195eee47/p/lib" "/home/tiger/.conan2/p/lz45aef30e187546/p/lib")
list(PREPEND CMAKE_INCLUDE_PATH "/home/tiger/.conan2/p/nlohm552351c8663ae/p/include" "/home/tiger/.conan2/p/poco0f8a6250ece3f/p/include" "/home/tiger/.conan2/p/pcre27ea830da3beb2/p/include" "/home/tiger/.conan2/p/bzip26d48265eb59fb/p/include" "/home/tiger/.conan2/p/expat7da784642e3d5/p/include" "/home/tiger/.conan2/p/sqlit901a58a890604/p/include" "/home/tiger/.conan2/p/libpq1579916154fff/p/include" "/home/tiger/.conan2/p/libmy5a95d901c3d4f/p/include" "/home/tiger/.conan2/p/opens3d01fe559d02c/p/include" "/home/tiger/.conan2/p/zlib10e4879147c91/p/include" "/home/tiger/.conan2/p/zstd7cecd195eee47/p/include" "/home/tiger/.conan2/p/lz45aef30e187546/p/include")



if (DEFINED ENV{PKG_CONFIG_PATH})
set(ENV{PKG_CONFIG_PATH} "${CMAKE_CURRENT_LIST_DIR}:$ENV{PKG_CONFIG_PATH}")
else()
set(ENV{PKG_CONFIG_PATH} "${CMAKE_CURRENT_LIST_DIR}:")
endif()




# Variables
# Variables  per configuration


# Preprocessor definitions
# Preprocessor definitions per configuration
