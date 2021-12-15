# Images

## Introduction

Images are a very important tool in MiniLibX in order to embrace its full
potential. These functions will allow you to read files directly into a image
object. This is very useful for textures or sprites of course.

## Reading images

To read from a file to a image object, you need either the XMP or PNG format. In
order to read we can call the functions `mlx_xpm_file_to_image` and
`mlx_png_file_to_image` accordingly. Do mind that `mlx_png_file_to_image`
currently leaks memory. Both functions accept exactly the same parameters and
their usage is identical.

Now, lets read from an image, shall we?

```c
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}
```

If the `img` variable is equal to `NULL`, it means that the image reading has
failed. It will also set the `img_width` and `img_height` accordingly, which
is ideal when reading sprites.

## Test your skills!

Now that you know how to read from files, lets get started on making more
graphical stuff ;). Create the following programs:
- Import a cursor of your choice and allow it to roam within the window freely.
- Import a texture and replicate it accross your entire window.
