# cmake的最小要求版本
cmake_minimum_required(VERSION 3.29.0)

# 指定我们的项目名称，工程名
project(planning)

# 指定C++的最小版本
set(CMAKE_CXX_STANDARD 17)



# 变量和目录设置

# 指定动态库生成的目录，把动态库和exe都指定到bin目录下
# CMAKE_RUNTIME_OUTPUT_DIRECTORY只适用于Windows系统
# CMAKE_LIBRARY_OUTPUT_DIRECTORY用于Linux系统
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)



# 动态库

# 让生成的可执行文件包含include和src两个目录
# ${PROJECT_SOURCE_DIR}/src抓取src目录下的所有.cpp文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)

# 生成动态库
# 给动态库取名字叫common
# SHARED ${SRC_LISTS} 给src目录下的所有.cpp文件生成一个动态库
add_library(common
SHARED
${SRC_LISTS}
)

# 动态库依赖头文件，还要包含头文件的目录
target_include_directories(common
PUBLIC
${PROJECT_SOURCE_DIR}/include
)



# # 指定一下我们的可执行文件生成的目录
# # EXECUTABLE_OUTPUT_PATH，把这个变量给它赋值
# # ${PROJECT_SOURCE_DIR}/bin用来存放exe可执行文件
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)



# # 获取一下当前目录下所有的.cpp文件
# # 把所有.cpp文件打包到变量SRC_LIST中
# aux_source_directory(. SRC_LIST)

# 可执行文件

# 基于planning_main生成可执行文件,由${SRC_LIST}中的.cpp文件生成
# 修改planning_main原来依赖的文件${SRC_LIST}
# 修改planning_main依赖的文件改为planning_main.cpp
add_executable(planning_main planning_main.cpp)

# 让planning_main通过PUBLIC的方式去包含${PROJECT_SOURCE_DIR}/include
target_include_directories(planning_main
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

# 链接

# 把可执行文件链接到生成的动态库common上面
target_link_libraries(planning_main
PUBLIC
common
)


# 在Windows系统上，可执行文件是exe，动态库是.dll





