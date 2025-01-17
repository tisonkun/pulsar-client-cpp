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

#ifndef PULSAR_CONSUMER_STATS_DISABLED_H_
#define PULSAR_CONSUMER_STATS_DISABLED_H_

#include "ConsumerStatsBase.h"

namespace pulsar {

class ConsumerStatsDisabled : public ConsumerStatsBase {
   public:
    virtual void receivedMessage(Message&, Result) {}
    virtual void messageAcknowledged(Result, CommandAck_AckType) {}
};

} /* namespace pulsar */

#endif /* PULSAR_CONSUMER_STATS_DISABLED_H_ */
