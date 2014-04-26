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

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/soem/
  DESTINATION include/youbot/youbot/include/soem
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)

install(TARGETS soem RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

