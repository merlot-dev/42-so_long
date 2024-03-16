Markdown
# So Long
## First graphical project in 42


This project is about creating a simple 2D game in order to get acknowledge of the Minilibx graphic library, and how to manage windows, images, events, ...

## Table of Contents

* [Introduction](#introduction)
* [Pacman revenge](#pacman-revenge)
* [License](#license)
* [Contributing](#contributing)
* [Contact](#contact)

## Introduction

Although there are some explicit requirements, there are some decissions I've made before starting. Some because you are free to decide, like the theme or the movement keys, others that are game design decission from my own interpretation of the subject. Let's see:
* The theme would be Pacman. It was my first decision, and comes from the fact that I belong to the Pacman coallition
* The movement keys would be just the arrows
* Although you can create windows larger than your screen size, I think it makes the game not playable at all. So I limited the size to the maximum size the screen allows, in my case 44x33. I can parse any size (the subject ask for it) and I check if it's correct or not, but I don't show maps larger than that maximum.
* A square is a rectangle. This is not a free interpretation it's a fact. I say this because some evaluator asked me if I was checking if it was a square, that in some projects they have done. 

## Pacman revenge

The subject ask for an start point, an exit point and and least one collectible, which are to be collected before exiting.

With this requirements and having choosen pacman as the theme, I thought about letting Pacman revenge from ghosts, and then he can freely eat the ghosts (Blinky, Inky, Clyde, Pinky), and then the dessert to finish the game.

## License

Specify the license under which your project is distributed. You can use a pre-existing license like MIT or Apache 2.0, or create your own.

## Contributing

If you welcome contributions to your project, outline the contribution guidelines here. 

## Contact

Information on how to contact you or the project maintainers. 

**Additional Sections**

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
