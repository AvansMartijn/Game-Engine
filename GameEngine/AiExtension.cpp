#include "pch.h"
#include "AiExtension.h"

AiExtension::AiExtension() {
	type = "AiExtension";
}

void AiExtension::execute() {
	if (ai != nullptr)
		ai->execute();
}
