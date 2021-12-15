## Introduciton
MiniLibX is a tiny graphics library which allows you to do the most basic things for rendering something in screens without knowledge of X-Window and Cocoa. It provides so-called simple window creation, a questionable drawing tool, half-ass image functions and a weird event management system.
### About X-Window
X-Window is a network-oriented graphical system for unix. For example this is used when connecting to remote disktops. One of the most common examples of such implementation would be TeamViewer.
### About macOS
macOS handles the graphical access to its screen, however to access this, we must register our application to the underlzing macOS graphical framework that handles the screen, windowing system, keyboard and mouse.

