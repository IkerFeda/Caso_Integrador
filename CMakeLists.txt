cmake_minimum_required(VERSION 3.26)
project(Caso_Integrador)

set(CMAKE_CXX_STANDARD 14)
find_package(nlohmann_json REQUIRED)

add_executable(Caso_Integrador
        Clase_variant.cpp
        To_String.cpp
        Json_Tostring.cpp
        from_Json.cpp
        Todo_Junto.cpp)
