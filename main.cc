#include <gflags/gflags.h>
#include "src/http_server.h"

DECLARE_string(flagfile);

int main(int argc, char** args) {

    FLAGS_flagfile = "conf/openai.conf";
    google::ParseCommandLineFlags(&argc, &args, true);
    HttpServer server;
    server.start();
    server.join();
    return 0;

}
