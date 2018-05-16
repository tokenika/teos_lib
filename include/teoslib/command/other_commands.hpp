#pragma once

#include <teoslib/config.h>
#include <teoslib/command.hpp>

namespace teos
{
  namespace command
  {
    class VersionClient : public TeosCommand
    {
    public:

      VersionClient(ptree reqJson) : TeosCommand(
        "", reqJson) {
        stringstream ss;
        ss << PROJECT_NAME << " " <<VERSION_MAJOR << "." << VERSION_MINOR;
        respJson_.put("version", ss.str());
      }
    };

    class VersionClientOptions : public CommandOptions
    {
    public:
      VersionClientOptions(int argc, const char **argv)
        : CommandOptions(argc, argv) {}

    protected:
      const char* getUsage() {
        return R"(
Retrieve version information of the client
Usage: ./teos version client [Options]
Usage: ./teos version client --jarg '{}' [OPTIONS]
)";
      }

      TeosControl executeCommand() {
        return VersionClient(reqJson_);
      }

      void printout(TeosControl command, variables_map &vm) {
        output("Version", "%s", GET_STRING(command, "version"));
      }

    };

  }
}