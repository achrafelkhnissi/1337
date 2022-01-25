<h1 align="center">
	42cursus' so_long 
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' so_long project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/achrafelkhnissi/1337/42curses"><b>42cursus repo</b></a>.
</p>


<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#how-to-play">How to play</a>
	<span> · </span>
	<a href="#resources">Resources</a>
</h3>

---

### How to play
---
#### Maps
The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |

* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

#### Controls

Use `WASD` to move. 

| Character | Move |
| - | - |
| W | UP |
| S | DOWN |
| D | RIGHT |
| A | LEFT |

Enemies move after you and will kill you when you move into their tile or they move into yours. After picking up all collectibles, the exits open and you may leave the map.

You can exit the game with `esc` or by pressing the closing window botton.

#### Execute the game
To play you can use some of the makefile rules, or execute the file _so_long_ if it's been generated, passing the map you want to play as parameter (``./so_long map.ber``). The make file has the following rules:

| Rule | Function |
| - | - |
| ``make`` | Generates _so_long_ and an object file for each .c. |
| ``make clean`` | Deletes all object files. |
| ``make fclean`` | Deletes the object files and the _so_long_. |
| ``make re`` | makes ``fclean`` and ``make`` again. |
| `` make play`` | Allows you to play all maps one at a time. To play the next map just press ``esc``. |

## Resources
- [42 Docs - MinilibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [MinilibX - Tutorial](https://gontjarow.github.io/MiniLibX/)
- [Github - ft_libgfx Repo](https://github.com/qst0/ft_libgfx)
- [Github - Images example](https://github.com/keuhdall/images_example)
