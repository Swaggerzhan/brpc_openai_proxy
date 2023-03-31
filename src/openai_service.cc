//
// Created by Swagger on 2023/3/31.
//
#include <json2pb/json_to_pb.h>
#include <json2pb/pb_to_json.h>
#include "openai_service.h"


#define PROTO_DECODE(cntl, body) \
    butil::IOBufAsZeroCopyInputStream wrapper(cntl->request_attachment()); \
    std::string errmsg;          \
    if (!json2pb::JsonToProtoMessage(&wrapper, &body, &errmsg)) {          \
        LOG(ERROR) << "decode proto err, errmsg: " << errmsg;              \
        cntl->SetFailed(500, "protobuf decode failed");                    \
        cntl->http_response().set_status_code(500);                        \
        return;                  \
    }

#define PROTO_ENCODE(cntl, body) \
    std::string ret;             \
    std::string errmsg2;          \
    if (!json2pb::ProtoMessageToJson(body, &ret, &errmsg2)) { \
        LOG(ERROR) << "encode proto err, errmsg: " << errmsg2; \
        cntl->SetFailed(500, "protobuf encode failed");      \
        cntl->http_response().set_status_code(500);         \
        return;                  \
    }                            \
    cntl->response_attachment().append(ret);


void OpenAiService::signup(pb::RpcController *cntl,
                           const HttpRequest *,
                           HttpResponse *,
                           pb::Closure *done) {
    brpc::ClosureGuard done_guard(done);
    // TODO:
}

void OpenAiService::login(pb::RpcController *cntl,
                          const HttpRequest *,
                          HttpResponse *,
                          pb::Closure *done) {
    brpc::ClosureGuard done_guard(done);
    // TODO:
}

void OpenAiService::chat_create(pb::RpcController *cntl,
                                const HttpRequest *,
                                HttpResponse *,
                                pb::Closure *done) {
    brpc::ClosureGuard done_guard(done);
    // TODO:
}

void OpenAiService::chat_delete(pb::RpcController *cntl,
                                const HttpRequest *,
                                HttpResponse *,
                                pb::Closure *done) {
    brpc::ClosureGuard done_guard(done);
    // TODO:
}

void OpenAiService::chat(pb::RpcController *controller,
                         const HttpRequest *,
                         HttpResponse *,
                         pb::Closure *done) {
    brpc::ClosureGuard done_guard(done);
    auto cntl = static_cast<brpc::Controller*>(controller);
    ChatRequestBody req_body;
    PROTO_DECODE(cntl, req_body);
    LOG(NOTICE) << req_body.DebugString();
    ChatResponseBody res_body;
    res_body.set_user_id(req_body.user_id());
    res_body.set_answer("fuck you");
    PROTO_ENCODE(cntl, res_body);
}

void OpenAiService::chat_history(pb::RpcController *cntl,
                                 const HttpRequest *,
                                 HttpResponse *,
                                 pb::Closure *done) {
    brpc::ClosureGuard done_guard(done);
    // TODO:
}
