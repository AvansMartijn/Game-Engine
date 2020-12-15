#include "pch.h"
#include "AiExtension.h"

AiExtension::AiExtension() {
	type = getType();
}

void AiExtension::execute() {
	if (ai != nullptr)
		ai->execute();
}

void AiExtension::fillProperties(std::map<std::string, ExtensionProperty> properties) {

}
