// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

}


void UBullCowCartridge::SetupGame()
{
    /*
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;
    */
    // Welcoming the player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    //PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    //PrintLine(TEXT("You Have %d lives"), Lives);
    PrintLine(TEXT("Type on your guess and \npress enter to continue...")); //Prompt for a guess
      
}