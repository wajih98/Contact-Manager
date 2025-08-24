cmake_minimum_required(VERSION 3.20)

project(ContactManager VERSION 0.1.0 LANGUAGES CXX)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
set(SOURCES
    src/main.cpp
    src/ContactManager.cpp
    src/Contact.cpp
)

# Include headers
include_directories(include)

# Create executable
add_executable(ContactManager ${SOURCES})
