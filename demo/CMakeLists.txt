# Copyright (c) Borislav Stanimirov
# SPDX-License-Identifier: MIT
#
function(add_demo name)
    add_executable(${name} ${ARGN})
    target_link_libraries(${name} splat::splat)
endfunction()

add_demo(endian endian.c)
add_demo(pp_select-c pp_select.c)
add_demo(pp_select-cpp pp_select.cpp)
add_demo(pp_util pp_util.c)
