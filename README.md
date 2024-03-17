Markdown
# So Long
## First graphical project in 42

This project is about creating a simple 2D game in order to learn about the Minilibx graphic library, and how to manage windows, images, pixels, events, ...

![image](https://github.com/merlot-dev/42-so_long/assets/53099349/34a4b516-b9a6-4321-a056-d1b1c36e7d18)


## Table of Contents

* [Introduction](#introduction)
* [Pacman revenge](#pacman-revenge)
* [Images](#images)
* [Code](#code)
* [Bonus](#bonus)

## Introduction

Although there are some explicit requirements, there are some decissions I've made before starting. Some because you are free to decide, like the theme or the movement keys, others that are game design decission from my own interpretation of the subject. Let's see:
* The theme would be Pacman. It was my first decision, and comes from the fact that I belong to the Pacman coallition
* The movement keys would be just the arrows
* Although you can create windows larger than your screen size, I think it makes the game not playable at all. So I limited the size to the maximum size the Campus screen allows, in my case 40x33. I can parse any size (the subject ask for it) and I check if it's correct or not, but I don't show maps larger than that maximum.
* A square is a rectangle. This is not a free interpretation it's a fact. I say this because some evaluator asked me if I was checking if it was a square, that in some projects they have done. 

## Pacman revenge

The subject ask for an start point, an exit point and and least one collectible, which are to be collected before exiting.

With this requirements and having choosen pacman as the theme, I thought about letting Pacman revenge from ghosts, and then he can freely eat the ghosts (Blinky, Inky, Clyde, Pinky), and then the dessert to finish the game.

## Images

Since I read something about Minilibx leaks if using png images, I decided to use images with XPM format. I found some in this format others I had to create. Let's see
* **Pacman, Ghosts and pills:**  
I found them in the [codingteam github repository](https://github.com/codingteam/pacmacs.el/tree/master/sprites)
They are 40x40, and after some tests drawing walls and images I decided to leave some room between image and wall, so I decided to use cells of 44x44 (CELLDIM)
* **Walls and corner:**  
  I have created them, just using vim. I have 4 wall images, one for each side, and 4 corner, one for each. You will see why later on
* **Fruits:**  
  I don't remember where I got the fruits from, but there were all in a row an as png. To convert it to XPM, I first tried GIMP, without success. So I used the [Image to ASCII Art converter](https://www.asciiart.eu/image-to-ascii), adjusting some sliders to get a minimum ASCII set in the generated file to minimize the final edition, with vim, to add the XPM header, with the set of colours, and the sintax of the pixel definition (between quotes, ...)t
* **Text:**
  For the text messages (Moves, Instructions, Game Over) and the numbers (used in the bonus part), I got a TTF file with the PACMAN font and to avoid installing locally the font I wrote the texts in [fontdrop](https://fontdrop.info/), captured the image, converted to txt with Ascii Art and then fine edition with vim.
* **Fire:**
  I got the png from [opengameart.org](https://opengameart.org/content/camp-fire-animation-for-rpgs-finished) and then convert using ASCII Art and vim. 
* **Title:**
  I got the base title from [Pacman official site](https://pacman.com) and then edited with vim to add the subtitle Revenge, and then converted using ASCII Art and vim.
  
## Code

I won't go to details of the code, but I will point out some

* Struct

  Since the hooks of minilibx (the functions that will be called to manage events (key pressed, windows close, ...) just accept a pointer to something, if it points to an structure you can have a lot of information. In may case the whole information of the game: the parsed map from the ber file, the mlx pointers, the images that will be used, game status (moves, pacman position, ...). All that information is grouped in the t_game struct

* Main
  
  The high level steps of the project are:
  * Check number of arguments
  * Check file name ending with .ber
  * Load map file and chek for errors (not rectangle, no walls, char forbidden, no exit or start or cllectible, ...)
  * Initialize MLX
  * Load images from XPM files and draw initial map
  * Set hooks
  * Just mlx_loop

* Walls
  As stated before, I have 4 walls and 4 corners.

  I just draw the side of the wall that have a no wall element beside. And to avoid some discontinuity I have to drive some corner. Just see the draw_wall file.

## Bonus

I planned the project from the beginning to include de bonus part. In fact I finnished first the bonus code, and then I deleted some parts to leave just the mandatory part. 

Which are the main differences of the bonus part? From less to more difficult:

* **Show moves on the window**

  In the Side screen of the game I "print" (draw) an image with the MOVES text (inside draw_sidescr function) and to print/draw the number of moves with 6 digits. For this I created this image in XPM format (as explained in the images block), and the a draw_nbr function, using the cut_img funtion to create the image of the digit acording to the % 10 in an iterative loop. Something similar to what we have done in some putnbr_baase function, but working with images instead of char *.
  
  ![image](https://github.com/merlot-dev/42-so_long/assets/53099349/63fc89f1-ba14-4ddb-b9a8-4fb0db63c814)

* **Enemy patrol**

  First I thought about some moving patrol, but after correcting some so_long and none had a moving one, I decided to have some static ones. And to avoid having a different map depending if it's for the bonus part or not, any ghosts becomes an enemy (a fire) after having been eaten.

  How do I get this?

  When I have finished an animated pacman movement to a new cell, and the original one was a collectible, I just modify in the string map the original 'C' char to an 'F' one. See move_pc_end function.

  Then, in the sl_anime function (more detailed below) I call the draw_fire with a value for the sequence of the fire animation (from 0 to 4) which will be drawn in any cell in the map with de 'F' char.
  
  In the sl_anime I also check if the pacman position is a map position with 'F' and it that case I set the g->dead to 1, which will start the pacman death animation (11 images) before ending the game. And also set back the map char to 'C' to avoid drawing the fire in that cell.

* **Sprite animations**

  This is the difficult part of the bonus, but worth knowing because animation is a key caspect in videogames.

  Minilibx can react to events, like pressing a key or closing the window whith the mlx_hook function. To animate images you need to use the mlx_loop_hook one. With this, the function you pass as an argument it's executed every "loop" of the refreshing part of the library, a frame?

  But animating every loop will be a really fast animation. So I draw animation every FRAMES number of calls to the funtion, sl_anime in my case. For this I use in that funtion an static var that is increased every call, and I do animation just when the var % FRAMES == 0.

  Which are the animations?

  * Fire
    
    Explained above, based on an image with a sequence of 5 and drawn in the draw_fire function
    
  * Pacman movement
    
    I have 4 images, one for each direction, and each is a 4 image sequence. When a movement key is pressed (key_moves) the function corresponding to the direction preseed sets the g->pm.spr to its corresponding set of images. And then the function move_pc, called in sl_anime, will draw the sequence, moving 11 pixels in the corresponding direction, up to the move is completed (move_pc_end)
    
  * Pacman death
    
    The death image it's an 11 sequence image, which are drawn int the draw_dead function, which starts drawing when g->dead is set to 1 and increments it up to 11 to draw the full sequence

**Improvements**

There are many improvements I can think of, but I feel that it has been a good introduction to minilibx and improvements can be out of the scope. Some can be:

* A maximum window size but map with no limits. If map is bigger than window, a dinamic movement of the map to suit the window while having always visible the pacman. In fact, I included in the game structure a map image and a game image to develop this idea: a larger image for the map that would be cut (cut_img function) to suit the game map.
* The enemy could be a moving one, like a ball of fire crossing randomly the screen, or some special ghost moving around the map.
* An Insert coin model, so that when the game is over you can start a new one.

