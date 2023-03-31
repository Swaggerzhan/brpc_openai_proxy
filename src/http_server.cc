//
// Created by Swagger on 2023/3/31.
//
#include "http_server.h"
#include <gflags/gflags.h>

DEFINE_string(host_addr, "0.0.0.0:8888", "default host addr");

HttpServer::HttpServer() {
}

HttpServer::~HttpServer() {
}

int HttpServer::start() {
    int ret = 0;
    ret = _server.AddService(&_openai_service,
                             brpc::SERVER_DOESNT_OWN_SERVICE,
                             "/openai/signup => signup,"
                             "/openai/login => login,"
                             "/openai/chat_create => chat_create,"
                             "/openai/chat => chat,"
                             "/openai/chat_delete => chat_delete,"
                             "/openai/chat_history => chat_history"
                             );
    if (ret != 0) {
        LOG(ERROR) << "add openai service failed";
        return -1;
    }
    ret = _server.Start(FLAGS_host_addr.c_str(), nullptr);
    if (ret != 0) {
        LOG(ERROR) << "host start failed";
        return -1;
    }
    return 0;
}

void HttpServer::join() {
    _server.RunUntilAskedToQuit();
}
