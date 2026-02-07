# Card Game in C++

## General Description
This project consists of the development of a card game programmed in C++ following the principles of object-oriented programming (OOP).

The main objective is to model the different entities of the game (cards, deck, players, board, etc.) using classes, as well as to implement the necessary logic to manage the correct progression of a game.

The project places special emphasis on:
- The use of classes and encapsulation
- The separation between interface (.h) and implementation (.cpp)
- A modular and reusable structure
- Code and design clarity

## Main Features
- Creation and management of a deck of cards
- Representation of individual cards
- Management of card stacks
- Control of players and their actions
- Management of the game board
- Control of the game flow (initialization, progression, and termination)

## Project Structure
The project is organized into different files, each with a clear responsibility:

### Main Classes
- **Carta** (`Carta.h / Carta.cpp`)  
  Represents a game card, including its attributes and basic behavior.

- **Baralla** (`Baralla.h / Baralla.cpp`)  
  Manages the set of cards, including their initialization and distribution.

- **PilaCartes** (`PilaCartes.h / PilaCartes.cpp`)  
  Implements a stack structure to manage sets of cards.

- **Jugador** (`Jugador.h / Jugador.cpp`)  
  Represents a player in the game and their properties.

- **Tauler** (`Tauler.h / Tauler.cpp`)  
  Maintains the overall state of the game on the board.

- **Seguidors** (`Seguidors.h / Seguidors.cpp`)  
  Manages the followers associated with the game.

- **Joc** (`Joc.h / Joc.cpp`)  
  Contains the main game logic and coordinates the interaction between the different classes.

### Main File
- **main.cpp**  
  Entry point of the program. Initializes the game and controls its execution.

## Design and Architecture
The project design follows an object-oriented approach, where each class has a clear and well-defined responsibility.

Priority has been given to:
- Code modularity
- Ease of maintenance
- Component reusability
- Readability and organization

Each class has its own header file (.h) and implementation file (.cpp), making the project easier to understand and extend.



