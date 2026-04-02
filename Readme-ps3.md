# PS3b: Sokoban

## Contact
Name: Dhruvkumar Patel
Section: 204
Time to Complete: around 15 - 16 hours


## Description
Explain what the project does.
In this project we created sokoban game using the sfml.In this we created the namespace SB that has the sokoban class and we created enum for the direction.In this we created the const height and weight to get the h and w from the input file and in the grid is created in the operator>> that take height and width from the input file and we also declared the textures and used the mapping for all the char charaters and used to draw in the sfml window and also firstly i drawn the ground floor for the @ and A which is the player and the create and then created another for loop for the all texture to draw in the sfml this all things are in the draw function.So, basically in this project it take file input from the command line which is level and then its read the height and width from it and then it creates the grid and then map all the textures into it and this way it shows the level which is created.
For partB 
In this i implemented the moveplayer function to move left right up and down with the help of the keyboard input and and update the player position and the crate position by pushing them to the new position if the movement is valid and not allowing the player not to move into the crate or in the wall and also implemented the isWon function to determine if all crates are in storage location or if there are more crate and less storage area than also if the crate moves to storage location it's returns true and also same for less crate and more storage and implemeted the reset function to reset the player and the crate position when R is pressed through the keyboard. Also, when the player wins the message is seen in the sfml window and player can't move. Basically, in this project we need to create the game such a way that game implementation is not change carefully handel all the situtaion and if all the crate boxes are in storage location the player wins the game message can be seen congratulation you won and he can reload the level by pressing R.

### Features
Describe what your major decisions were and why you did things that way.
the major decision that i took was to used the std::map for the sprites and textures with char as key this help us look directly for the sprite or texture needed based on the symbol which is in the inputfile when rendering. This helps for the loading and unloading of the sprites and textures making it very easy to change and draw.
For partB
In this when my player was going on the storage than it was removing the storage location after it moves so i made a playerOnStorage as bool and then in my draw function i created if statement to draw the player on storage if it is true or only it will draw the player only and also added 1 to mark as when the crate reaches the storage location and also this help me to write the movePlayer function easily and change aaccording to what is needed and when player is move to the new location then we need to clear the old position so this help me figure out what to add and when so i added the if statement for the playerOnStorage and according to that it clear the player sprite.
### Memory
Describe how you decided to store the level data including whether you used smart pointers.
I used the 2D vector to store and acces the games 2D level.This help us to directly store of the characters over the use of the smarpointer and it also reduce the memory usage and it is also easy to access the grif during the gameplay. Also, using this 2D vector every row of the grid can be access or change anything if we want. We used the char because it is the lightweight and also helps for the memory efficient way to represent the state of each cell in the grid.
For partB
In the partB to reset level i used the vector2i to get the initial position of the player and crate position of the player and also store the grid to initial grid and this helps to make the reset function which was easy to make and just replace the current player position and crate position to the initial position which was there from the input file this way help easy to use and access the 2D array to reset the level.

### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.
We did not used the lambda in this part.
For partB i used the lamda function in the MoveBlocked is designed to check is move is blocked on the base on the current position (x,y) and the direction movement and also i used the refrence in the capture and this allow the lamda to  access and modify the external variable in this move function. Also, i added bool so the return is bool true if the move is blocked or false otherwise.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
When i was running the program the output was not correct it also takes the whitespaces after the weight and height and also for the others lines to so i used the string unused to ignore all the white space and it helps to get the correct output and the other error was regarding the player location the autograder was giving error in the test i also out the cout statement in the for loop to check if my player location is correct i found out that it was correct but my playerLoc() was not correct i need t use the for loop to find the player location and give it in vector2i
For partb
In this i was having trouble in the moveplayer function when i run and move the player or crate through the storage location it removes the storage location so for this i created the playerOnStorage as a bool and for the crate i implemented 1 for the crate on the storage this help me to change in the move player location and update and erase the last player location when checking if it is on the storage location it leaves the storage location as it is and move the player to the new position. Also i was having trouble in the isWon function becuase it was not calculating the storage location right it was reducing the storage location when the crate moves to the storage location so i make changes to the isWon function and also added 1 to count that crate is on the storage location and count both. I was not abel to figure out what to write in the test for the missing symbol.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
I don't think so i used any special thing.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.
I took the help form the discord which provides the issue for the unable to open the file and also about the player location which i was getting error and in discord professor had already provided this issues because many of them very having the same issue. Also, for the font i downloaded the arial.ttf file 
Arial font : https://befonts.com/arial-font.html
Kenney Sokoban Pack (CC0): https://kenney.nl/assets/sokoban

