cmake_minimum_required(VERSION 2.8)

add_executable(displayIpAddress
  DisplayIpAddress.cpp
)

target_link_libraries(displayIpAddress stdc++)

install(TARGETS displayIpAddress RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

