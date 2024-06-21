project(ublox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED)

include_directories(include)
add_library(${PROJECT_NAME} SHARED src/serialstream.cpp src/SparkFun_u-blox_GNSS_Arduino_Library.cpp )

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES include/ublox/SparkFun_u-blox_GNSS_Arduino_Library.h include/ublox/stream.h include/ublox/serialstream.h include/ublox/u-blox_config_keys.h include/ublox/u-blox_structs.h  DESTINATION include/ublox)