#include "torrent.hh"

using namespace ptorrent::torrent;

Torrent::Torrent(std::istream& fp) :
  Torrent::Torrent(detail::to_dict(bencode::decode(fp))) {
  /* empty */
}

Torrent::Torrent(detail::dict&& root) {
  // --- ANNOUNCE ---
  auto alist = root.find("announce-list");

  if (alist != root.end()) {
    for (const auto& tier : detail::to_list(alist->second)) {
      for (const auto& tracker : detail::to_list(tier)) {
        announce_list.push_back(detail::to_str(tracker));
      }
    }
  }
  else {
    announce_list.push_back(detail::to_str(root["announce"]));
  }

  // ---
}
