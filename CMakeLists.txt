cmake_minimum_required ( VERSION 3.4.1 )
project ( ptorrent )

find_package ( Libwebsockets CONFIG REQUIRED )
find_package ( PkgConfig REQUIRED )
pkg_search_module ( UV REQUIRED libuv )

add_executable ( ptorrent
  src/main.cc
  src/torrent.cc
)

target_compile_features( ptorrent PRIVATE cxx_std_20 )
target_compile_options( ptorrent PRIVATE
  -Wall -Wextra -Wconversion
  ${UV_CFLAGS_OTHER}
)
target_include_directories ( ptorrent PRIVATE
  ext/bencode.hpp/include
  ${UV_INCLUDE_DIRS}
)
target_link_libraries ( ptorrent
  websockets_shared
  ${UV_LIBRARIES}
)

add_dependencies ( ptorrent websockets_shared )
