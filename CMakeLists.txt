cmake_minimum_required(VERSION 3.16)
project(openai)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include_directories(/root/github/incubator-brpc/output/include)
include_directories(${CMAKE_SOURCE_DIR})

link_directories(/root/github/incubator-brpc/output/lib)
link_directories(/usr/local/lib)
link_directories(/root/github/gflags/build/lib)

link_directories(/usr/lib/x86_64-linux-gnu)

aux_source_directory(src SOURCE_FILES)

add_executable(openai
        ${SOURCE_FILES}
        proto/http_service.pb.cc
        main.cc
        )

target_link_libraries(openai
        libbrpc.a
        libprotobuf.a
        libgflags.a
        libleveldb.a
        libssl.a
        libcrypto.a
        libsnappy.a
        libc.a
        libz.a
        dl
        )
