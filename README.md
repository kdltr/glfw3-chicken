# glfw3

## Description
Bindings to the [GLFW](https://www.glfw.org/) OpenGL window and event management library, version 3.X. Version 3 of GLFW is not backwards compatible with previous major versions of GLFW.

The CHICKEN 5 port of this egg still needs some work and testing regarding OS X and Windows support.

When using with OpenGL ES, make sure GLFW is appropriately compiled (e.g.: `cmake -DGLFW_USE_EGL=ON -DGLFW_CLIENT_LIBRARY=glesv2 -DBUILD_SHARED_LIBS=ON`).

When installing GLFW on OS X through Homebrew, an extra step is needed. Homebrew renames the library’s from the default. You can fix this by creating a link that points to the library that gets installed. E.g. `sudo ln -s <homebrew-lib-dir>/libglfw3.dylib /usr/local/lib/libglfw.dylib`

## Installation
This repository is a [Chicken Scheme](https://call-cc.org/) egg.

It is part of the [Chicken egg index](https://eggs.call-cc.org/5/) and can be installed with `chicken-install glfw3`.

## Requirements
* Bind

## Documentation
glfw3 is separated into two modules: `glfw3-bindingw` and `glfw3`. For almost all purposes, only `glfw3` should be needed.

`glfw3-bindings` provides direct bindings to GLFW generated by [bind](https://wiki.call-cc.org/egg/bind). Names have been converted from camelCase to hyphenated, with GLFW prefixes removed (e.g. `glfwGetTimerValue` becomes `get-timer-value`. Constants are lower-cased and surrounded by `+`s (e.g. `GLFW_ALPHA_BITS` becomes `+alpha-bits+`).

`glfw3` is the high-level interface that should be used in most cases. At the moment it is largely re-exporting `glfw3-bindings`, although many of these functions could still use wrappers (patches welcome!). The not-exactly-the-same-as-the-glfw-api functions are described in the section [High-level interface](#high-level-interface).

For information regarding the GLFW API, see the official [GLFW documentation](https://www.glfw.org/documentation.html).


### High-level interface
    [procedure] (init)

Initializes glfw. Not needed when using `with-window`.

    [parameter] window

Contains the window associated with the current context.

    [procedure] (make-context-current WINDOW)

Performs `glfwMakeContextCurrent` while setting the above `window` parameter to the new value.

    [procedure] (make-window WIDTH HEIGHT NAME #!key (fullscreen? #f) (swap-interval 1) resizable visible decorated red-bits green-bits blue-bits alpha-bits depth-bits stencil-bits accum-red-bits accum-green-bits accum-blue-bits accum-alpha-bits aux-buffers samples refresh-rate sterio srgb-capable client-api context-version-major context-version-minor context-robustness opengl-forward-compat opengl-debug-context opengl-profile)

Create a window with title string `NAME` and dimensions `WIDTH` by `HEIGHT`. The keys correspond to the available [GLFW window hints](https://www.glfw.org/docs/latest/window.html#window_hints). `resizable`, `visible`, `decorated`, `stereo`, `srgb-capable`, `opengl-forward-compat`, `opengl-debug-context` accept boolean arguments, while all other accept either an integer or an appropriate GLFW constant as per the documentation.

Sets the current context to the window that was created. The swap interval of the window is set to the value of the`swap-interval` key. Finally, this initializes all of the window-specific callbacks.

When using with OS X, make sure you ask for the right context. Only OS X 10.7+ support core contexts, and only limited contexts are supported. See [the GLFW FAQ](https://www.glfw.org/faq.html#41---how-do-i-create-an-opengl-30-context). For instance:

    (make-window WIDTH HEIGHT NAME
                 context-version-major: 3
                 context-version-minor: 2
                 opengl-forward-compat: #t
                 opengl-profile: +opengl-core-profile+)
    

    [macro] (with-window (WIDTH HEIGHT NAME . KEYS) BODY ...)

Initializes GLFW, creates a window as per `make-window`, and runs `BODY` before cleaning up.

### Callbacks
`glfw3` provides parameters which contain the functions that are called from GLFW callbacks. The GLFW callbacks are initialized to call these parameters when `init` and `make-window` or `with-window` are used, but they can be changed with the callback setter functions.

    [parameter] window-position-callback

Called when a window is moved. Expects a function with the signature `(lambda (WINDOW X Y) ...)`. `WINDOW` is the window that was moved. `X` and `Y` are the coordinates of the upper-left corner of the window.

    [parameter] window-size-callback

Called when a window is resized. Expects a function with the signature `(lambda (WINDOW W H) ...)`. `WINDOW` is the window that was resized. `W` and `H` are the new dimensions  of the window.

    [parameter] window-close-callback

Called when a window is closed. Expects a function with the signature `(lambda (WINDOW) ...)`. `WINDOW` is the window that was closed.

    [parameter] window-focus-callback

Called when a window comes into or goes out of focus. Expects a function with the signature `(lambda (WINDOW FOCUSED?) ...)`. `WINDOW` is the affected window, while `FOCUSED?` is true when the window has been focused and false otherwise.

    [parameter] window-iconify-callback

Called when a window is iconified or restored. Expects a function with the signature `(lambda (WINDOW ICONIFIED?) ...)`. `WINDOW` is the affected window, while `ICONIFIED?` is true when the window has been iconified and false otherwise.

    [parameter] framebuffer-size-callback

Called when a framebuffer is resized. Expects a function with the signature `(lambda (WINDOW W H) ...)`. `WINDOW` is the window whose framebuffer was resized. `W` and `H` are the new dimensions, in pixels, of the framebuffer.

    [parameter] mouse-button-callback

Called when a mouse button is pressed or released. Expects a function with the signature `(lambda (WINDOW BUTTON ACTION MODS) ...)`. `WINDOW` is the window where the button was pressed, `BUTTON` is the name of the mouse button (one of `+mouse-button-1+` through `+mouse-button-8+`, `+mouse-button-last+`, `+mouse-button-left+`, `+mouse-button-right+`, `+mouse-button-middle+`), `ACTION` is one of `+press+` or `+release+`, and `MODS` is a bit field describing the modifier keys that were held down (any of `+mod-shift+`, `+mod-control+`, `+mod-alt+`, or `+mod-super+`).

    [parameter] cursor-enter-callback

Called when a cursor enters or leaves a window. Expects a function with the signature `(lambda (WINDOW ENTERED?) ...)`. `WINDOW` is the affected window, and `ENTERED?` is true when the window was entered and false otherwise.

    [parameter] cursor-position-callback

Called when a cursor moves. Expects a function with the signature `(lambda (WINDOW X Y) ...)`. `WINDOW` is the affected window. `X` and `Y` is the new coordinates of the cursor.

    [parameter] scroll-callback

Called when a scroll occurs. Expects a function with the signature `(lambda (WINDOW X Y) ...)`. `WINDOW` is the affected window. `X` and `Y` are the scroll offsets.

    [parameter] key-callback

Called when a key is pressed or released. Expects a function with the signature `(lambda (WINDOW KEY SCANCODE ACTION MODS) ...)`. `WINDOW` is the window where the button was pressed, `KEY` is the name of the key, `SCANCODE` is the system-specific scancode of the key, `ACTION` is one of `+press+`, `+release+` or `+repeat+`, and `MODS` is a bit field describing the modifier keys that were held down (any of `+mod-shift+`, `+mod-control+`, `+mod-alt+`, or `+mod-super+`).

    [parameter] char-callback

Called when character is entered. Expects a function with the signature `(lambda (WINDOW CHAR) ...)`. `WINDOW` is the affected window, and  `CHAR` is the unicode code point of the character.

    [parameter] char-mods-callback

Called when character is entered, but also includes modifiers that were active when the character was entered. Expects a function with the signature `(lambda (WINDOW CHAR MODS) ...)`. `WINDOW` is the affected window, and  `CHAR` is the unicode code point of the character, `MODS` is the bitfield of the modifiers that were active.

    [parameter] monitor-callback

Called when a monitor is connected or disconnected. Expects a function with the signature `(lambda (MONITOR EVENT) ...)`. `MONITOR` is a pointer to the affected monitor, `EVENT` is either `+connected+` or `+disconnected+`.

    [parameter] joystick-callback

Called when a joystick is plugged-in or plugged-out. Expects a function with the signature `(lambda (JOYSTICK EVENT) ...)`. `JOYSTICK` is an integer representing the joystick, `EVENT` is either `+connected+` or `+disconnected+`.

    [procedure] (set-window-position-callback! [WINDOW [CALLBACK]])
    [procedure] (set-window-size-callback! [WINDOW [CALLBACK]])
    [procedure] (set-window-close-callback! [WINDOW [CALLBACK]])
    [procedure] (set-window-focus-callback! [WINDOW [CALLBACK]])
    [procedure] (set-window-iconify-callback! [WINDOW [CALLBACK]])
    [procedure] (set-framebuffer-size-callback! [WINDOW [CALLBACK]])
    [procedure] (set-mouse-button-callback! [WINDOW [CALLBACK]])
    [procedure] (set-cursor-enter-callback! [WINDOW [CALLBACK]])
    [procedure] (set-cursor-position-callback! [WINDOW [CALLBACK]])
    [procedure] (set-scroll-callback! [WINDOW [CALLBACK]])
    [procedure] (set-key-callback! [WINDOW [CALLBACK]])
    [procedure] (set-char-callback! [WINDOW [CALLBACK]])
    [procedure] (set-char-mods-callback! [WINDOW [CALLBACK]])
    [procedure] (set-monitor-callback! [CALLBACK])
    [procedure] (set-joystick-callback! [CALLBACK])

Set the callback functions associated with `WINDOW`. Used when the callback parameters are not desired. `WINDOW` defaults to `window`. `CALLBACK` defaults to an external function that calls the corresponding callback parameter.

### Modified functions 
The following functions take a different number of arguments than their GLFW counterparts. This is because the original function accepted values passed by reference for modification.

    [procedure] (get-version)

Returns three values: the major version , minor version , and revision number of the GLFW library.

    [procedure] (get-monitors)

Returns two values: A pointer to an array of GLFWmonitor references, and the number of values in the array.

    [procedure] (get-monitor-position MONITOR)

Returns two values: the x and y position, in screen coordinates, of the upper-left corner of the `MONITOR`’s viewport on the virtual screen.

    [procedure] (get-monitor-physical-size MONITOR)

Returns two values: the physical width and height, in millimetres, of the `MONITOR`.

    [procedure] (get-video-modes MONITOR)

Returns two values: A pointer to an array of video modes, and the number of values in the array.

    [procedure] (get-window-position WINDOW)

Returns two values: the x and y position, in screen coordinates, of the upper-left corner of the `WINDOW`.

    [procedure] (set-window-position WINDOW X Y)

Set the position of the upper-left corner of the `WINDOW`.

    [procedure] (get-window-size WINDOW)

Returns two values: the width and height, in screen coordinates, of the `WINDOW`.

    [procedure] (get-framebuffer-size WINDOW)

Returns two values: the width and height, in pixels, of the framebuffer of `WINDOW`.

    [procedure] (get-cursor-position WINDOW)

Returns two values: the x and y position of the cursor, relative to the upper-left edge of the client area of the `WINDOW`.

    [procedure] (set-cursor-position WINDOW X Y)

Set the position of the cursor, relative to the upper-left edge of the client area of the `WINDOW`.

    [procedure] (get-joystick-axes JOYSTICK)

Returns two values: a pointer to an array of floats representing the values of all axes of the specified joystick, and the number of values in the array.

    [procedure] (get-joystick-buttons JOYSTICK)

Returns two values: a pointer to an array of bytes representing the state of all buttons on the specified joystick, and the number of values in the array.

## Example
``` Scheme
(use (prefix glfw3 glfw:))

(glfw:key-callback (lambda (window key scancode action mods)
                     (cond
                      [(and (eq? key glfw:+key-escape+) (eq? action glfw:+press+))
                       (glfw:set-window-should-close window #t)])))

(glfw:with-window (640 480 "Example" resizable: #f)
    (let loop ()
      (glfw:swap-buffers (glfw:window))
      (glfw:poll-events)
      (unless (glfw:window-should-close (glfw:window))
        (loop))))
```

## Version history
### Version 0.7.0
15 March 2019

* Maintenance given to [Kooda](/users/kooda)
* Port to CHICKEN 5
* Update to GLFW 3.2
* Windows and OS X support has not been tested

### Version 0.6.1
20 November 2014

* Add OpenGL ES, Windows, and OS X support
* Remove Scheme-settable error callback

### Version 0.5.2
20 October 2014

* Add `swap-interval` keyword to `make-window`
* Add some aliases for consistency

**Version 0.5.1**

11 June 2014

* Remove unintended use of miscmacros

**Version 0.5.0**

10 June 2014

* Return output values passed by reference

### Version 0.4.1
23 May 2014

* Remove magic opengl-glew initialization (Thanks to terpri!)

**Version 0.4.0**

22 May 2014
* Reorganize into two modules
* Add callback functions and parameters
* Add `init`
* Add `make-context-current`
* Fix a number of unsafe bindings that could potentially call back to Scheme

### Version 0.3.0
* Make `*window*` a parameter named `window`

### Version 0.2.0
* Add `make-window`, `with-window`

### Version 0.1.0
* Initial release

## Source repository
Source available [here](https://www.upyum.com/cgit.cgi/glfw3-chicken/).

Bug reports and patches welcome! Bugs can be reported to kooda@upyum.com

## Authors
Alex Charlton
Adrien (Kooda) Ramos

## Licence
BSD
