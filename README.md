"# FakeSraz2D" 

INSTALLATION:
installation file: FakeSraz2D_Setup/Debug/FakeSraz2D_Setup.msi

Just run the .msi file and follow the instructions.

DESCRIPTION:
This is a simple clone of an old game "Sraz" from 1993, a first official Croatian game.
I don't really remember the actual rules for the game, so I improvised. Don't be mad if something
isn't as it should be.
The objective is simple - destroy the other teams. You can destroy a team by defeating all the pawns
belonging to the team, or going straight for the base (which destroys all the pawns belonging to that
base). To move you will need to answer a random question from a variety of categories - history, art,
math, chemistry,... If you answer the question correctly, you get to move a single tile and end your
turn, and if you answer incorrectly, nothing happens and your turn is over. If you step on a tile with
an enemy pawn, you will engage in a battle and will need to answer 3 questions to defeat the opposing
pawn, and if you step on an enmey base tile, you will need to answer 5 questions. Should you step on
a tile with both an enemy base and an enemy pawn, you will need to destroy them both. If you succeed
in any form of battle, you will receive an equipment upgrade (up to 2 times), which is represented by
your pawn first receiving a sword and later a shield. Equipment decreases/increases the amount of
questions you will need to answer by 1, depending if you're attacking or defending.

CONTROLS:
Main menu - left click on either "NEW GAME" or "QUIT"
Game over - left click anywhere
Playing - red tile indicates which pawn is to be moved
		- green tiles indicate where can the pawn move -> left click on one to move
		- upon selecting a tile to move to you will be asked a question (or questions)
			-> left click on "a)", "b)", "c)" or "d)" to select your answer

FUTURE PLANS:
1) add a stylized title to main menu
2) improve the way buttons work, they are basically just rectangles now
		- current iteration requires the user to check if they are clicked and find a way to detect if
			they've been pressed
		- this will most likely be done using the observer design pattern
3) using shaders
4) improve text font - plans are to use freetype library, but i still haven't 100% figured out how it
works
5) add more questions - a LOT more questions
6) add more functionalities to the game, like modifiying the player number, modifying team colors,
	options menu, etc.
7) add AI
