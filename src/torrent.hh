#ifndef PTORRENT_TORRENT_HH
#define PTORRENT_TORRENT_HH

#include <fstream>
#include <vector>
#include <bencode.hpp>
#include <uv.h>

namespace ptorrent::torrent {

  namespace detail {
    using integer = bencode::data::integer;
    using string  = bencode::data::string;
    using list    = bencode::data::list;
    using dict    = bencode::data::dict;
    constexpr auto to_int(auto d)  { return std::get<integer>(d); }
    constexpr auto to_str(auto d)  { return std::get<string>(d);  }
    constexpr auto to_list(auto d) { return std::get<list>(d);    }
    constexpr auto to_dict(auto d) { return std::get<dict>(d);    }
  }

  class Torrent {
    public:
      long long pieces_length;
      std::vector<std::string> announce_list;

      Torrent(std::istream&);
      Torrent(detail::dict&&);
  };
}

#endif
