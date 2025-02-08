// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnyPrint.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FAnyPrintModule"

void FAnyPrintModule::StartupModule()
{
	// This code will execute after your module is loaded into memory.
	// If you plan to register editor UI elements or commands, do it here.
}

void FAnyPrintModule::ShutdownModule()
{
	// Cleanup logic before module is unloaded.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAnyPrintModule, AnyPrint)
