#include "echo2.h"

#include "envoy/buffer/buffer.h"
#include "envoy/network/connection.h"

#include "common/common/assert.h"

namespace Envoy {
namespace Filter {

Network::FilterStatus Echo2::onData(Buffer::Instance& data, bool) {
  ENVOY_CONN_LOG(trace, "echo: got {} bytes", read_callbacks_->connection(), data.length());
  ENVOY_CONN_LOG(trace, "echo: data {} ", read_callbacks_->connection(), data.toString());

  //read_callbacks_->connection().write(data, false);
  return Network::FilterStatus::Continue;
}

} // namespace Filter
} // namespace Envoy
