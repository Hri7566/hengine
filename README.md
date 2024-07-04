# hengine

This is a (currently featureless) game engine. Yes, I know the name is terrible, but it's better if you pronounce it "hen-gine" instead of "h-engine".

## Requirements

For compilation, you must have [premake5](https://premake.github.io/), [ninja](https://ninja-build.org/), and [raylib](https://www.raylib.com/) installed system-wide.

## Building

```
$ git clone https://github.com/Hri7566/hengine
$ cd hengine
$ git submodule update --init --recursive
$ premake5 ninja && ninja
```

A static library file will be in `bin/hengine/Debug`.

## Why are you making a game engine?

I'm learning.
