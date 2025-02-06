// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Fonts/SlateFontInfo.h"
#include "EditorUtilityWidget.h"
#include "PrintLogWidget.generated.h"

/**
 * This is the base Editor Utility Widget that displays each log made
 */

UCLASS()
class ANYPRINTEDITOR_API UPrintLogWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

	// ====================================
	// Function Overrides
	// ====================================
	
	virtual void NativeConstruct() override;
	
	// ====================================
	// Private UProperty Variables
	// ====================================

	UPROPERTY()
	UTextBlock* LogEntryText;

	UPROPERTY()
	UEditableTextBox* TextSizeInput;

	UPROPERTY()
	FSlateFontInfo FontInfo;
	
	// ====================================
	// Private Functions
	// ====================================

	static float GetTextSize();
	void UpdateLog();

	// ====================================
	// Private UFunctions
	// ====================================

	UFUNCTION()
	void OnLogUpdatedHandler();

protected:
	
	// ====================================
	// Protected UProperty Variables
	// ====================================

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category="UMG")
	UScrollBox* LogScrollBox;

	// ====================================
	// Protected UFunctions
	// ====================================
	
	UFUNCTION(BlueprintCallable, Category="UMG")
	void SetTextSize(const FString& TextSizeIn);
	
};
