cmake_minimum_required(VERSION 3.13)
project(CO892_2019_assessment2)
set(CMAKE_C_STANDARD 99)

include(FindPCAP.cmake)

set(SOURCE_FILES src/main.c src/list_devices.c src/list_devices.h src/parse_args.c src/parse_args.h src/usage.c src/usage.h src/sniff.c src/sniff.h)

add_executable(sniffer ${SOURCE_FILES})
target_link_libraries(sniffer ${PCAP_LIBRARY})