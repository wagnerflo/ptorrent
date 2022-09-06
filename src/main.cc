#include <libwebsockets.h>
#include <iostream>
#include "torrent.hh"

using namespace ptorrent::torrent;

void signal_handler(uv_signal_t *handle, int signum) {
  printf("Signal received: %d\n", signum);
  // uv_signal_stop(handle);
}

int main(int argc, char* argv[]) {
  auto fp = std::ifstream(argv[1]);
  auto tor = Torrent(fp);

  lws_context_creation_info lws_info = {};

  uv_loop_t loop = {};
  uv_signal_t sigint, sigusr1;

  uv_loop_init(&loop);

  // uv_signal_init(&loop, &sigint);
  // uv_signal_start(&sigint, signal_handler, SIGINT);

  uv_signal_init(&loop, &sigusr1);
  uv_signal_start(&sigusr1, signal_handler, SIGUSR1);

  uv_run(&loop, UV_RUN_DEFAULT);
  uv_loop_close(&loop);

  return 0;
}
