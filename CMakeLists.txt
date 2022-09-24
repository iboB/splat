add_library(splat INTERFACE)
add_library(splat::splat ALIAS splat)
target_include_directories(splat INTERFACE .)
