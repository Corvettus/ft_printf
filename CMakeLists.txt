cmake_minimum_required(VERSION 3.14)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_executable(printf main.c ft_printf.h ft_print_p.c)