cmake_minimum_required(VERSION 3.16)
project(Endecry)

set(CMAKE_CXX_STANDARD 17)

add_executable(endecry src/main.cpp
        src/decrypt.h
        src/encrypt.h
        src/utility.h
        src/decrypt.cpp
        src/encrypt.cpp
        src/utility.cpp
        src/cipher/caesar.h
        src/cipher/caesar.cpp
        src/cipher/vigenere.cpp
        src/cipher/vigenere.h
        src/cipher/xor.cpp
        src/cipher/xor.h src/hash/md2.h src/hash/md2.cpp src/hash.cpp src/hash.h src/cipher/DES.cpp src/cipher/DES.h src/cipher/RC4.cpp src/cipher/RC4.h)