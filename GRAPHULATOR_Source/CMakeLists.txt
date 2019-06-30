cmake_minimum_required(VERSION 3.7)
project(trycl)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )


set(CMAKE_CXX_STANDARD 11)

add_executable(trycl main.cpp expression/addExpression.h expression/baseExpression.h expression/divideExpression.h expression/expressions.h expression/lnExpression.h expression/logExpression.h expression/modExpression.h expression/multiplyExpression.h expression/numberExpression.h expression/powExpression.h expression/rpnBuilder.h expression/subtractExpression.h expression/token.h expression/trigExpression.h expression/variableExpression.h expression/token.cpp expression/rpnBuilder.cpp)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
