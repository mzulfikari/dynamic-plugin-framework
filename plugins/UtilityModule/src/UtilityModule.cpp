#include "UtilityModule.h"

#include "EchoCommand.h"
#include "TimeCommand.h"
#include "RandomCommand.h"

#include "CommandRegistry.h"

void registerUtilityModule(CommandRegistry& registry)
{
    registry.add(std::make_unique<EchoCommand>());
    registry.add(std::make_unique<TimeCommand>());
    registry.add(std::make_unique<RandomCommand>());
}