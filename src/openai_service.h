//
// Created by Swagger on 2023/3/31.
//

#ifndef OPENAI_OPENAI_SERVICE_H
#define OPENAI_OPENAI_SERVICE_H

#include <brpc/server.h>
#include "proto/http_service.pb.h"

namespace pb = google::protobuf;

class OpenAiService : public HttpService {
public:

    void signup(pb::RpcController* cntl,
               const HttpRequest*, HttpResponse*,
               pb::Closure* done) override;

    void login(pb::RpcController* cntl,
                const HttpRequest*, HttpResponse*,
                pb::Closure* done) override;

    void chat_create(pb::RpcController* cntl,
                    const HttpRequest*, HttpResponse*,
                    pb::Closure* done) override;

    void chat_delete(pb::RpcController* cntl,
                    const HttpRequest*, HttpResponse*,
                    pb::Closure* done) override;

    void chat(pb::RpcController* cntl,
              const HttpRequest*, HttpResponse*,
              pb::Closure* done) override;

    void chat_history(pb::RpcController* cntl,
                    const HttpRequest*, HttpResponse*,
                    pb::Closure* done) override;

private:

};

#endif //OPENAI_OPENAI_SERVICE_H
