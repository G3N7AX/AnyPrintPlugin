// Copyright 2025 G3N7AX. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "AnyPrintWidget.generated.h"

/**
 * 
 */
UCLASS()
class ANYPRINTEDITOR_API UAnyPrintWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

	// ====================================
	// Overriden Functions
	// ====================================
	
	virtual void NativeOnInitialized() override;
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	// ====================================
	// Public Components
	// ====================================
	
	UPROPERTY()
	UTextBlock* LogEntryTextBlock;

	UPROPERTY()
	FSlateFontInfo FontInfo;

	UPROPERTY(meta = (BindWidget))
	UScrollBox* LogScrollBox;

	// ====================================
	// Listener UFunctions
	// ====================================

	UFUNCTION()
	void OnLogUpdatedHandler();

	UFUNCTION()
	void OnEmptyLogHandler();

	// ====================================
	// Private UFunctions
	// ====================================

	UFUNCTION(Category = AnyPrintEditor)
	void PrintLogEntries();
	
	UFUNCTION(BlueprintCallable, Category = AnyPrintEditor)
	void SetTextSize(FText TextSize);

public:

	// ====================================
	// Public UFunctions
	// ====================================
	
	UFUNCTION(BlueprintCallable, Category = AnyPrintEditor)
	void SetShowTimestamps(bool ShowTimestampsValue);
};
