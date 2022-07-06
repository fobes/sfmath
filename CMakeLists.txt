cmake_minimum_required(VERSION 3.18.0 FATAL_ERROR)

set(PROJECT_NAME sfmath)
project(${PROJECT_NAME})

set(HEADERS
	include/CMatrix.hpp
	include/CQuaternion.hpp
	include/CVector2.hpp
	include/CVector3.hpp
	include/CVector4.hpp
	include/Vertices.hpp
	include/VectorUtils.hpp
)

set(SOURCES
	source/main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

