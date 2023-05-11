
        cmake_minimum_required(VERSION 3.15)
        project(conan-setup)
        include("/usr/share/qtcreator/package-manager/conan.cmake")
        conan_cmake_run(
          CONANFILE "/home/tiger/XNode/conanfile.txt"
          INSTALL_FOLDER "/home/tiger/XNode/build/conan-dependencies"
          GENERATORS cmake_paths json
          BUILD missing
          ENV CONAN_CMAKE_TOOLCHAIN_FILE="/home/tiger/XNode/build/conan-dependencies/toolchain.cmake"
        )