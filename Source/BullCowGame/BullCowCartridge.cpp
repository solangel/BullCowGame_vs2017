// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ProcessGuess(Input);
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;
    // Welcoming the player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You Have %i lives"), Lives);
    PrintLine(TEXT("Type on your guess and \npress enter to continue...")); //Prompt for a guess

    const TCHAR HW[] = TEXT("cakes");
    PrintLine(TEXT("Character 1 of the hidden word is: %c"),HiddenWord[0]);
    PrintLine(TEXT("The 4th character of HW is: %c"),HW[3]);
}

void UBullCowCartridge::EndGame()
{
    bGameOver=true;
    PrintLine(TEXT("Press enter to play again!"));
}

void UBullCowCartridge::ProcessGuess(const FString & Guess)
{
   if (Guess == HiddenWord) 
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letter long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry try guessing again, \nYou have %i lives remaining"), Lives);
        return;
    }

    //Check is isogram
    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, Guess again!"));
        return;
    }

    //Remove life
    PrintLine(TEXT("Lost a life!"));
    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
        EndGame();       
    }

    //PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);
    PrintLine(TEXT("Guess agan, you have %i lives left"), Lives);
}

bool UBullCowCartridge::IsIsogram(FString Word)
{
    return true;
}
