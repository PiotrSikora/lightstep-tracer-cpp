// -*- Mode: C++ -*-
#ifndef __LIGHTSTEP_TYPES_H__
#define __LIGHTSTEP_TYPES_H__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

// Note these types are identical to those generated by Thrift
// TODO keep in sync with crouton.thrift

namespace lightstep_net {

struct LogRecord {
  int64_t timestamp_micros;
  std::string runtime_guid;
  std::string span_guid;
  std::string stable_name;
  std::string message;
  std::string level;
  int64_t thread_id;
  std::string filename;
  int64_t line_number;
  std::vector<std::string>  stack_frames;
  std::string payload_json;
  bool error_flag;
};

struct TraceJoinId {
  std::string TraceKey;
  std::string Value;
};

struct KeyValue {
  std::string Key;
  std::string Value;
};

struct SpanRecord {
  std::string span_guid;
  std::string trace_guid;
  std::string runtime_guid;
  std::string span_name;
  std::vector<TraceJoinId>  join_ids;
  int64_t oldest_micros;
  int64_t youngest_micros;
  std::vector<KeyValue>  attributes;
  bool error_flag;
  std::vector<LogRecord>  log_records;
};

#ifdef HAVE_CPP_NETLIB
// Reporting Service

struct Runtime {
  std::string guid;
  int64_t start_micros;
  std::string group_name;
  std::vector<KeyValue>  attrs;
};

struct MetricsSample {
  std::string name;
  int64_t int64_value;
  double double_value;
};

struct Metrics {
  std::vector<MetricsSample>  counts;
};

struct Command {
  bool disable;
};

struct Timing {
  int64_t receive_micros;
  int64_t transmit_micros;
};

struct ReportRequest {
  Runtime runtime;
  std::vector<SpanRecord>  span_records;
  std::vector<LogRecord>  log_records;
  int64_t timestamp_offset_micros;
  int64_t oldest_micros;
  int64_t youngest_micros;
  std::vector<LogRecord>  internal_logs;
  Metrics internal_metrics;
};

struct ReportResponse {
  std::vector<Command>  commands;
  Timing timing;
  std::vector<std::string>  errors;
};
#endif

} // namespace lightstep_net

#endif // __LIGHTSTEP_TYPES_H__