//
// Created by Swagger on 2023/3/31.
//

#ifndef OPENAI_HTTP_SERVER_H
#define OPENAI_HTTP_SERVER_H

#include <brpc/server.h>
#include "openai_service.h"

class HttpServer {
public:
    HttpServer();
    ~HttpServer();

    int start();
    void join();

private:
    brpc::Server _server;
    OpenAiService _openai_service;
};

#endif //OPENAI_HTTP_SERVER_H
