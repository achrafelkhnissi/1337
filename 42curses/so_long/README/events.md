# Events

## Introduction

Events are the foundation of writing interactive applications in MiniLibX. It is
therefore of essence that you fully comprehend this chapter as this will be of
use in your future graphical projects.

All hooks in MiniLibX are nothing more than a function that gets called whenever
a event is triggered. Mastering all these events won't be neccessary, however,
we will quickly go over each X11 event accordingly.

## X11 events

X11 is the library that is used alongside of MiniLibX. It therefore is no secret
that this header is very useful for finding all the according events of
MiniLibX. There are a number of events to which you may describe.

Key  | Event
:---:| -----
`02` | KeyPress
`03` | KeyRelease
`04` | ButtonPress
`05` | ButtonRelease
`06` | MotionNotify
`07` | EnterNotify
`08` | LeaveNotify
`09` | FocusIn
`10` | FocusOut
`11` | KeymapNotify
`12` | Expose
`13` | GraphicsExpose
`14` | NoExpose
`15` | VisibilityNotify
`16` | CreateNotify
`17` | DestroyNotify
`18` | UnmapNotify
`19` | MapNotify
`20` | MapRequest
`21` | ReparentNotify
`22` | ConfigureNotify
`23` | ConfigureRequest
`24` | GravityNotify
`25` | ResizeRequest
`26` | CirculateNotify
`27` | CirculateRequest
`28` | PropertyNotify
`29` | SelectionClear
`30` | SelectionRequest
`31` | SelectionNotify
`32` | ColormapNotify
`33` | ClientMessage
`34` | MappingNotify
`35` | GenericEvent
`36` | LASTEvent

If you can't figure out what some events are, don't worry, because you probably
won't need them. If you do, go read the documentation of each X11 function.

## X11 masks

Each X11 event, also has a according mask. This way you can register to only
one key when it triggers, or to all keys if you leave your mask to the default.
Key masks therefore allow you to whitelist / blacklist events from your event
subscriptions. The following masks are allowed:

Mask       | Description
:---------:| -----------
`0L`       | NoEventMask
`(1L<<0)`  | KeyPressMask
`(1L<<1)`  | KeyReleaseMask
`(1L<<2)`  | ButtonPressMask
`(1L<<3)`  | ButtonReleaseMask
`(1L<<4)`  | EnterWindowMask
`(1L<<5)`  | LeaveWindowMask
`(1L<<6)`  | PointerMotionMask
`(1L<<7)`  | PointerMotionHintMask
`(1L<<8)`  | Button1MotionMask
`(1L<<9)`  | Button2MotionMask
`(1L<<10)` | Button3MotionMask
`(1L<<11)` | Button4MotionMask
`(1L<<12)` | Button5MotionMask
`(1L<<13)` | ButtonMotionMask
`(1L<<14)` | KeymapStateMask
`(1L<<15)` | ExposureMask
`(1L<<16)` | VisibilityChangeMask
`(1L<<17)` | StructureNotifyMask
`(1L<<18)` | ResizeRedirectMask
`(1L<<19)` | SubstructureNotifyMask
`(1L<<20)` | SubstructureRedirectMask
`(1L<<21)` | FocusChangeMask
`(1L<<22)` | PropertyChangeMask
`(1L<<23)` | ColormapChangeMask
`(1L<<24)` | OwnerGrabButtonMask

## Hooking into events

Hooking into events is one of the most powerful tools that MiniLibX provides. It
allows you to register to any of the aforementioned events with the call of a
simple hook registration function. For example instead of calling `mlx_key_hook`,
we can also register to the `KeyPress` and `KeyRelease` events.

To achieve this, we call the function `mlx_hook`. Lets take a look:

```c
#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
```

Here we register to the `KeyPress` event with the according `KeyPressMask`. Now
whenever we press a key, the window will be closed.

## Test your skills!

Now that you have a faint idea of how all of this works, we encourage you to
make the hook handlers. Whenever the:
- <kbd>ESC</kbd> key is pressed, your window should close.
- window is resized, you should print something in your terminal.
- the red cross is clicked, your window should close.
- you press a key longer than x seconds, you should print something in your
terminal.
- mouse enters the window, you should print `Hello!` in your terminal, when it
leaves, you should print `Bye!`.
