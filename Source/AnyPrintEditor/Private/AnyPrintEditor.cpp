// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnyPrintEditor/Public/AnyPrintEditor.h"

#define LOCTEXT_NAMESPACE "FAnyPrintEditorModule"

void FAnyPrintEditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("AnyPrintEditor Module Loaded"));
}

void FAnyPrintEditorModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("AnyPrintEditor Module Unloaded"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAnyPrintEditorModule, AnyPrintEditor)