vim: et ts=2 sw=2

Links

https://foonathan.net/blog/2016/07/07/cmake-dependency-handling.html
https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html
https://github.com/psi4/psi4/wiki/External-subprojects-using-Git-and-CMake
https://blog.kitware.com/cmake-superbuilds-git-submodules/
https://stackoverflow.com/questions/43761594/cmake-and-using-git-submodule-for-dependence-projects
http://www.diracprogram.org/doc/release-12/programmers/external_projects.html
https://stackoverflow.com/questions/42253435/how-to-use-git-submodules-properly-in-cmake-project
https://stackoverflow.com/questions/42182596/cmake-projects-with-submodules-that-have-redudant-dependencies
https://stackoverflow.com/questions/31566773/c-with-git-and-cmake-how-to-build-submodules-with-specific-parameters
https://stackoverflow.com/questions/11524201/how-to-add-a-cmake-custom-target-for-all-submodules
https://www.google.com/search?q=cmake+how+to+include+other+cmake+projects&ie=utf-8&oe=utf-8&client=firefox-b-ab
https://stackoverflow.com/questions/16398937/cmake-and-finding-other-projects-and-their-dependencies



CMake

```cmake
# vim: et ts=4 sw=4
#
# Hello, user.
#
# Welcome to Aperture IT.
#

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.12)
```


Constructors
`add_executable()`
`add_library()`

Member variables

Member functions
`get_target_property()`
`set_target_properties()`
`get_property(TARGET)`
`set_property(TARGET)`
`target_compile_definitions()`
`target_compile_features()`
`target_compile_options()`
`target_include_directories()`
`target_link_libraries()`
`target_sources()`
