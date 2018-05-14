Robb's i3 configuration
=======================

## Overview

This i3 configuration creates a 2d array of workspaces with labels
like "1.1", "1.2", ... "2.1", "2.2", ... where the first number is the
row and the second number is the column.  The label may be followed by
a dot and an output designator (see below).

Most window manager interaction is with the `Super` modifier (it's
often the key whose label looks like a two-by-two grid of squares
drawn by a child without the use of a ruler).  The main exception is
workspace switching, which uses the `Ctrl` modifier.

## Multiple Outputs

Each output (e.g., monitor, projector) can have its own 2d array of
workspaces. To accomplish this, use a dotted triplet as the workspace
label. The first two elements are the usual row and column and the
third element is a label for the output. For instance, the author
usually has two monitors side by side and uses "L" for the one on the
left and "R" for the one on the right, as in "1.1.L", "1.1.R", etc.

You can run `i3-msg rename workspace to 1.1.R` to change the name of
the current workspace to "1.1.R". The `Super + d` key combo allows you
to run commands without first starting a shell.

## Changing Workspaces

Although the `Super` key in combination with a number still switches
to a single-numbered workspace, this behavior may change in the
future.

The following keys change workspaces:

* `Control + Left` changes to the workspace to the west
* `Control + Right` changes to the workspace to the east
* `Control + Up` changes to the workspace to the north
* `Control + Down` changes to the workspace to the south

Workspaces are arranged in a 2d array where east is a greater column
and south is a greater row.  The motion commands do not wrap when the
get to the northern-, eastern-, southern-, or western-most workspace.

## Container Focusing

In general, this setup uses arrow keys rather than letters for
movement. To switch the focus between containers, use:

* `Super + Left` to move focus to the west
* `Super + Right` to move focus to the east
* `Super + Up` to move focus to the north
* `Super + Down` to move focus to the south

## Container Motion

These commands move containers within a workspace.

* `Super + Shift + Left` to move the container to the west
* `Super + Shift + Right` to move the container to the east
* `Super + Shift + Up` to move the container to the north
* `Super + Shift + Down` to move the container to the south

## Container Splitting

The following commands control how a container is split when adding
another container.

* `Super + h` means split horizontally (add container to east)
* `Super + v` means split vertically (add container to south)
* `Super + s` means stack containers
* `Super + w` means make the containers tabbed
* `Super + e` toggles between the splitting methods

## Container Interaction

* `Super + f` toggles between fullscreen mode for applications that
  don't provide this functionality natively.
  
* `Super + Shift + q` to close a container. This is useful for poorly
  designed applications that don't themselves provide a way to close
  the window.
  
* `Super + Shift + Space` toggles the container between floating mode
  and tiling mode.
  
* `Super + r` enters resize mode where the arrow keys make the
  container wider (`Right`) narrower (`Left`), taller (`Down`) and
  shorter (`Up`). Pressing `Enter` terminates this mode.
  Alternatively to resize mode, you can drag window borders.
  
## Container Effects

Robb likes to see scenery images cycled on his X11 root by making his
windows translucent. To achieve realistic translucency that's not
detrimental to usability, the background also needs to be
substantially blurred, which requires hardware accelerated 2d
rendering (i.e., a good graphics card).  The compton window manager is
run by the configure script, but only if your machine name appears in
the `bin/maybe-run-compton` file.

* `Super + o` turns off translucency for the container
* `Super + Shift + o` makes the container more translucent

Sometimes the mouse wheel in combination with the Super modifer also
works.

## Window Manager Actions

* `Super + Shift + c` reloads the window manager configuration
* `Super + Shift + r` restarts the window manager
* `Super + Shift + l` locks the screen
* `Super + Shift + e` exit the window manager. This action pops up a
  confirmation dialog at the top of the screen that gives you the
  choice to lock the screen, log out; or suspend, hibernate, reboot,
  or power-off the machine.
* `Super + d` prompts for and runs a command
  
## Audio Output Volume

If the keyboard has volume control keys, they can be used to increase,
decrease, mute, and unmute the audio output.  Otherwise, you can use
these:

* `Super + F1` toggles muted state
* `Super + F2` decreases volume
* `Super + F3` increases volume

The volume is initially set to zero percent to prevent surprises and
distractions.

## Screen Brightness

If a keyboard has screen brightness control keys, they will adjust the
screen brightness.
  
## Status Bar

The status bar is located across the top of the screen and includes a
clock, the date, the volume percent, RAM usage percent, CPU usage
percent, and main IP address.  The CPU usage is normalized to be
between 0 and 100 regardless of how many CPUs, cores, and hardware
threads are available.

## Other features

