# cmake的最小要求版本
cmake_minimum_required(VERSION 3.29.0)

# 指定我们的项目名称，工程名
project(planning)

# 指定C++的最小版本
set(CMAKE_CXX_STANDARD 17)

# 指定一下我们的可执行文件生成的目录
# EXECUTABLE_OUTPUT_PATH，把这个变量给它赋值
# ${PROJECT_SOURCE_DIR}/bin用来存放exe可执行文件
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 获取一下当前目录下所有的.cpp文件
# 把所有.cpp文件打包到变量SRC_LIST中
aux_source_directory(. SRC_LIST)

# 生成可执行文件,由${SRC_LIST}中的.cpp文件生成
add_executable(planning_main ${SRC_LIST})


# # 包含头文件的目录
# # PROJECT_SOURCE_DIR 表示CMakeLists.txt所在的目录
# include_directories(${PROJECT_SOURCE_DIR}/include)











