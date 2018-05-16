#include <teoslib/command/create_commands.hpp>

const char* createSubcommands = R"(
ERROR: RequiredError: Subcommand required
Create various items, on and off the blockchain
Usage : ./ teos [OPTIONS] create SUBCOMMAND [OPTIONS]

Subcommands:
    key             Create a new keypair and print the public and private keys
    account         Create a new account on the blockchain
    producer        Create a new producer on the blockchain
)";

const std::string createCommandPath = "";