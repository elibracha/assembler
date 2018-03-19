cmake_minimum_required(VERSION 3.9)
project(assembler C)

set(CMAKE_C_STANDARD 99)

add_executable(assembler assembler.c module/switch.c module/reader.c module/parser.c module/parser.h module/reader.h module/switch.h module/builder.c module/builder.h module/const.h module/table.c module/data.c module/code.c module/table.h module/code.h module/data.h)
