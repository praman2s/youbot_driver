include_directories(
 ${PROJECT_SOURCE_DIR}/include/soem
)

add_library(soem 
	ethercatbase.c 
  ethercatcoe.c 
  ethercatconfig.c 
  ethercatfoe.c 
  ethercatsoe.c 
  ethercatmain.c 
  ethercatprint.c 
  nicdrv.c 
  ethercatdc.c
)

set(SOEM_HEADERS
	ethercatbase.h
	ethercatcoe.h
	ethercatconfig.h
	ethercatconfiglist.h
	ethercatdc.h
	ethercatfoe.h
	ethercatmain.h
	ethercatprint.h
	ethercatsoe.h
	ethercattype.h
	nicdrv.h
)


macro(INSTALL_HEADERS_WITH_DIRECTORY HEADER_LIST)
  foreach(HEADER ${${HEADER_LIST}})
    string(REGEX MATCH "(.*)[/\\]" DIR ${HEADER})
    install(FILES ${HEADER} DESTINATION include/youbot/youbot/${DIR})
  endforeach()
endmacro()

INSTALL_HEADERS_WITH_DIRECTORY(SOEM_HEADERS)

install(TARGETS soem RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

