// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnyPrintLibrary/Public/AnyPrintLibrary.h"

#define LOCTEXT_NAMESPACE "FAnyPrintLibraryModule"

void FAnyPrintLibraryModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("AnyPrintLibrary Module Loaded"));
}

void FAnyPrintLibraryModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("AnyPrintLibrary Module Unloaded"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAnyPrintLibraryModule, AnyPrintLibrary)