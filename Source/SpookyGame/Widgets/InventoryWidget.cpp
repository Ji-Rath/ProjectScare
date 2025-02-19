// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "InteractionSystem_Settings.h"
#include "Components/ScrollBox.h"
#include "Inventory/InventoryComponent.h"
#include "InventoryItemWidget.h"
#include "Interaction/ItemData.h"
#include "Inventory/InventoryInfo.h"
#include "Inventory/PlayerEquipComponent.h"

bool UInventoryWidget::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) { return false; }

	if (!InventoryRef)
	{
		if (APawn* Player = GetOwningPlayerPawn())
		{
			InventoryRef = Player->FindComponentByClass<UInventoryComponent>();
		}	
	}

	// Bind UpdateInventory to OnInventoryChange so it is called everytime there is an inventory update
	if (InventoryRef)
	{
		InventoryRef->OnInventoryChange.AddDynamic(this, &UInventoryWidget::UpdateInventory);
		TArray<FInventoryContents> Inventory;
		InventoryRef->GetInventory(Inventory);
		UpdateInventory(Inventory);
	}
	
	return true;
}

void UInventoryWidget::UpdateInventory(const TArray<FInventoryContents>& Inventory)
{
	if (ensure(InventoryRef && ItemWidget))
	{
		// Clear all items from display
		InventoryDisplay->ClearChildren();

		// Get player inventory contents
		int CurrentSlot = 0;

		// Loop through all current items in player inventory and display them to UI
		for (const FInventoryContents& InventoryItem : Inventory)
		{
			const auto ItemInfo = InventoryItem.GetItemInformation<UItemInformation>();
			if (ensure(ItemInfo && InventoryDisplay))
			{
				UInventoryItemWidget* ItemReference = CreateWidget<UInventoryItemWidget>(InventoryDisplay, ItemWidget);
				ItemReference->UpdateDisplay(ItemInfo->DisplayName, InventoryItem.Item.Get().Count);
				InventoryDisplay->AddChild(ItemReference);
				ItemReference->ItemSlot = CurrentSlot;
				ItemReference->OnClick.AddDynamic(this, &UInventoryWidget::ClickedOnItem);
				CurrentSlot++;
			}
		}
	}
}

void UInventoryWidget::ClickedOnItem(int ItemIndex)
{
	OnItemClick.Broadcast(ItemIndex, InventoryRef);
}

