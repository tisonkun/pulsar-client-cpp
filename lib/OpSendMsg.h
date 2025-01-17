/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifndef LIB_OPSENDMSG_H_
#define LIB_OPSENDMSG_H_

#include <pulsar/Message.h>
#include <pulsar/Producer.h>

#include <boost/date_time/posix_time/ptime.hpp>

#include "PulsarApi.pb.h"
#include "SharedBuffer.h"
#include "TimeUtils.h"

namespace pulsar {

struct OpSendMsg {
    proto::MessageMetadata metadata_;
    SharedBuffer payload_;
    SendCallback sendCallback_;
    uint64_t producerId_;
    uint64_t sequenceId_;
    boost::posix_time::ptime timeout_;
    uint32_t messagesCount_;
    uint64_t messagesSize_;

    OpSendMsg() = default;

    OpSendMsg(const proto::MessageMetadata& metadata, const SharedBuffer& payload,
              const SendCallback& sendCallback, uint64_t producerId, uint64_t sequenceId, int sendTimeoutMs,
              uint32_t messagesCount, uint64_t messagesSize)
        : metadata_(metadata),  // the copy happens here because OpSendMsg of chunks are constructed with the
                                // a shared metadata object
          payload_(payload),
          sendCallback_(sendCallback),
          producerId_(producerId),
          sequenceId_(sequenceId),
          timeout_(TimeUtils::now() + milliseconds(sendTimeoutMs)),
          messagesCount_(messagesCount),
          messagesSize_(messagesSize) {}

    void complete(Result result, const MessageId& messageId) const {
        if (sendCallback_) {
            sendCallback_(result, messageId);
        }
    }
};

}  // namespace pulsar

#endif
