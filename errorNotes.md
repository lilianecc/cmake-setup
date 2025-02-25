error Lnk2005 is probably you include same header file in 2 different cpp
and that header file is not a class, then it will cause multiple definition

when you want to revert a file after push it to the repo

`git checkout HEAD^ -- /path/to/file`
`git commit -am "revert changes on this file, not finished with it yet"`
`git push`

revert the last push

`git push -f origin last_known_good_commit_number:branch_name`


helpful vim command

`:set number` to show line number

**Some error Notes**
* unresolved external symbol "public:
means it doesn't know where it's defined, usually need::
target_link_libraries(multiplyProject
  ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/multiply.lib
)

* the following two include_directories difference is depends on if link to the project
`include_directories(path1 path2 path3)`
`target_include_directories(ProjectName Private path1)`

* When add_library then generate target then you can use `target_include_directories`.
It will show up on visual studio when you right click on the project, and under C/C++/Additional Include Directories will be there.
* `target_link_libraries(libraryName otherLibsNeedToLink)`. This will show up under Linker/Input on Visual Studio.

* Specifies include directories to use when compiling a given target.

when creating MS1553 library, we should list every file into the set and add to library 
we also dont need `${CMAKE_CURRENT_SOURCE_DIR}` in front of every file, if you set things up correctly,
`${CMAKE_CURRENT_DIR}` should be either just an absolute path to where the CMakeList.txt is at which is same as . path

**CMAKE notes**

====use 
`#set(CMAKE_FIND_DEBUG_MODE TRUE)` to look for debug info

- 3 different ways to use .so library
  - no.1
    find_library(MyLib NAMES MS1553 PATHS ${CMAKE_CURRENT_SOURCE_DIR}/..build/ms1553)
  - add_executable(PPC405Test PPC405Test.cpp)
    target_link_libraries(PPC405Test
	gtest_main
	${CMAKE_CURRENT_SOURCE_DIR}/..build/ms1553/libMS1553.so
  - no.2#MS1553
  - no.3 ${MyLib}
)

`add_test(PPC405GTest PPC405Test)` #this will enable ctest


##cannot run .so file directly
##when add_library(name SHARED fileName)
has SHARED in there then it will create .so file

- using static works in windows when doing gtest
  - reason: This discrepancy often arises from how gtest is linked and how Windows handles DLL dependencies. When gtest is linked statically, all the necessary code is included directly into the executable. This eliminates external dependencies at runtime, simplifying the process and often leading to fewer issues. However, when gtest is linked as a shared library (DLL), the executable relies on the gtest DLL being present at runtime. On Windows, this can lead to problems if the DLL is not found in the expected locations (e.g., the same directory as the executable, the system's PATH, etc.).
- something