# learning-game-dev

Early attempt at learning basic game development. The goal is to learn and apply concepts such as the game loop, how to handle input and updating game objects.
Simple 2D whack-a-mole with rectangles: upper rectangle (hammer) automatically moves from wall to wall. Lower rectangle (nail) is spawned at a random x position at the bottom of the screen. Hitting the nail increases hammer's horizontal speed, despawns the nail and spawns another one at a random spot.


+++This is a Visual Studio 2017 project. To run, double-click on learning/learning/learning.exe


Controls:

A: switch hammer direction to left

D: switch hammer direction to right

SPACE: move the hammer down (smash)


Flaws:

-No time step ==> the game runs at different speeds according to the hardware

-At high speeds, the hammer moves great distances with each frame, essentially making it impossible to hit the nail.

-It is possible to break the game by moving the hammer left or right as it reaches the bottom of the screen, thus locking it at that height and making it hit nails on its own as it moves back and forth. Pressing the SPACE bar again allows it to return to its original y position.
