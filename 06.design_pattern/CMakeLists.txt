cmake_minimum_required(VERSION 3.14)
project(design_pattern)
set(CMAKE_CXX_STANDARD 17)

set(PATTERNS
        abstract-factory
        builder
        singleton
        )

foreach (_dir IN ITEMS ${PATTERNS})
    file(GLOB _files "${_dir}/*.cpp")
    message(STATUS "Pattern `${_dir}':")

    # 对每个文件夹生成可执行文件
    foreach (_file IN ITEMS ${_files})

        get_filename_component(_file_name
                ${_file} NAME
                )

        set(_project_name "${_file_name}")
        message(STATUS "  ${_dir}/${_file_name} is going to be built")

        add_executable(${_project_name} "${_dir}/${_file_name}")
    endforeach ()

endforeach ()

