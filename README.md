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

Since I read something about Minilibx leaks if using png images, I decided to use XPM format. I found some in this format others I had to create. Let's see
* **Pacman, Ghosts and pills:**  
I found them in the [codingteam github repository](https://github.com/codingteam/pacmacs.el/tree/master/sprites)
They are 40x40, and after some tests drawing walls and images I decided to leave some room between image and cell, so I will use cells of 44x44 (CELLDIM)
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
I won't go to details of the code
## Bonus

Information on how to contact you or the project maintainers. 

**Improvements**

You can add additional sections to your README.md file as needed, using the same heading format (## for major sections, ### for subsections, etc.). Here are some examples:

* **Features:**  
  A list of the key features of your project.
* **Requirements:**  
  Any software or libraries required to run your project.
* **Testing:**  
  How to test your project.
* **Authors:**  
  A list of the project's contributors.
* **Credits:**  
  Acknowledge any third-party libraries or resources used.

**Remember to replace the bracketed information with your specific details.**
Some sprites
https://github.com/codingteam/pacmacs.el/tree/master/sprites
To write text
Using pacman ttf
write text in https://fontdrop.info/
Capture image
Convert to ascci in https://www.asciiart.eu/image-to-ascii
Fine edition with vim
