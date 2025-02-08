// Copyright 2025 G3N7AX. Licensed under the MIT License.

#pragma once

#include "Modules/ModuleManager.h"

class FAnyPrintModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
