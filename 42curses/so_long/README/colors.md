## Colors
Colors are presented in an in format. It therefore requires some tricky things in order to obtain an int which can contain the ARGB values.
### The color integer standard
We shift bits to use the TRGB format. To define a color, we initialize it as follow: `0xTTRRGGBB, where each character represents the following:
|Letter		|	Description		|
|-----------|-------------------|
|`T`		| Transparency 		|
|`R`		| red component		|
|`G`		| green component	|
|`B`		| blue component	|
RGB colors can be initialized as above. a few examples would be:

|Color		|	Description		|
|-----------|-------------------|
|red		| `0x00FF0000`		|
|green		| `0x0000FF00`		|
|blue		| `0x000000FF`		|
### Encoding and decoding colors
Since each byte contains 2^8 values, and RGB values range from 0 to 255, we can perfectly fit a integer (as an int is 4 bytes). In order to set the values programatically we use `bitshifting`. Let's create a function which does precisely that for us.
```c
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
```
Because ints are stored from right to left, we need to bitshift each value the according amount of bits backwards. We can also do the exact opposite and retrieve integer values from a encoded TRGB integer.
```c
int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
```

### Test your skills!
Now that you understand the basics of how the colors can be initialized, get
comfy and try creating the following color manipulation functions:
- `add_shade` is a function that accepts a double (distance) and a int (color)
as arguments, 0 will add no shading to the color, whilst 1 will make the color
completely dark. 0.5 will dim it halfway, and .25 a quarter way. You get the
point.
- `get_opposite` is a function that accepts a int (color) as argument and that
will invert the color accordingly.
