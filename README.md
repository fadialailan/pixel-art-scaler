# pixel-art-scaler

pixel-art-scaler is a tool to enlarge pixel art for plaforms that blur it when you upload to them.

# Why use this tool

Has the following happended to you before. you have a low res image that is meant to be viewed
with anti-aliasing off, you upload it to some plaform that when completly destroys it like this

`orignal:`

<img src="docs/assets/example-one.png" alt="orignal size grid image" />

<img src="docs/assets/example2.png" alt="orignal size circle image" />

**smooth:**

<img src="docs/assets/example-one.png" width="400px" style="image-rendering: smooth;" alt="smooth grid image"/>
<img src="docs/assets/example2.png" width="400px" style="image-rendering: smooth;" alt="smooth circle image"/>

NOTE: if the `pixelated` images look blurry, then you are viewing this on a plaform that does not support the `image-rendering` CSS property, and it is for reasons like this that this tool was made

**pixelated:**

<img src="docs/assets/example-one.png" width="400px" style="image-rendering: pixelated;" alt="pixelated grid image" />

<img src="docs/assets/example2.png" width="400px" style="image-rendering: pixelated;" alt="pixelated circle image"/>

The images you see above are all from 2 files only, the difference is the size and the
image-rendering technique (you are seeing the different techniques available in the browser,
you can read more at [MDN Web Docs][MDN Web Docs image-rendering]) , when dealing with
pixel art you do not want smoothing to happen as it makes the image way too different
from the intended way to view it. 
In the case of the web you can change the image-rendering technique but that is not always an option

This is where this program comes in, it enlarges pixel art while keeping them pixelated,
it also supports adding a grid to seperate the pixels (useful if you want to indicate the pixel boundaries)

NOTE: these images are rendered using smooth rendering

<img src="docs/assets/example-oneX30.png" style="image-rendering: smooth;" alt="30x grid image" />
<img src="docs/assets/example-oneX30-grid.png" style="image-rendering: smooth;" alt="30x grid image with pixel grid" />

<img src="docs/assets/example2X30.png" style="image-rendering: smooth;" alt="30x grid image" />
<img src="docs/assets/example2X30-grid.png" style="image-rendering: smooth;" alt="30x grid image with pixel grid" />

Even with the smooth rendering, the picture's pixel art is still recognizable.

# Building

This tool is writen using C++ and meant to be built using CMake.

## Dependencies

* [CLI11][cli11 github]
* [ImageMagick][ImageMagick github] (specifically Magick++, tho it should be included
in most ImageMagick installs)
* [fmt][fmtlib github]

Make sure they are in a place where CMake's `find_package` can find them.  

NOTE: I am still learning how to use CMake, so if there is a better way to do
this, feel free to open an issue mentioning how the build process can be made
better and easier for others.

## Building (done only on linux)

After installing the dependencies, run the following command

```
$ cmake -S . -B build/
```

This should create a folder called `build` that contains a plaform specific build system
(in the case of Linux it will use Make), in the case of Make, the project can be built by running

```
$ cd build
$ make
```

For a cross-plaform command (only tested on Linux with Make), run:

```
$ cmake --build build
```

This should add an executable called `pixel-art-scaler` to the build folder and
this executable is the application itself.

# Usage

The project comes with a help menu that that is shown when you run it with the `-h` option

```
pixel resizer
Usage: pixel-art-scaler [OPTIONS] input-files...

Positionals:
  input-files TEXT:FILE ... REQUIRED
                              the input file to resize

Options:
  -h,--help                   Print this help message and exit
  -o,--output TEXT            specify the output format (more details in the docs)
  --resize-factor UINT        the image's resize factor
  --grid-border-size UINT     the image's grid size (set to 0 to disable)
  --grid-color TEXT           the image's grid color
  --grid-method TEXT          grid method [strokes, accurate]
```

This gives a basic overview on how to use the application

## Exeplenation of options

`-h`: shows the help menu

`-o`: specify the output format

The output format uses the fmt's library format style so special variables are surrounded by
currly brackets `{}`, to include the actual currly bracket character, it can be escaped by
doubling them `{{` and ``}}`.

All examples will assume you gave the following path for an image `/home/bob/image.png`
the following variables are available

`{stem}`: the name of the input file, in this case it is `image`  
`{extension}`: the file extension of the file including the dot, in this case it is `.png`  
`{resize_factor}`: the resize factor of the image (the number given to the --resize-factor option)  
`{parent}`: the parent path of the file, in this case it is `/home/bob`

the default format is `{stem}X{resize_factor}{extension}`.

## Building steps on Linux


[MDN Web Docs image-rendering]: https://developer.mozilla.org/en-US/docs/Web/CSS/image-rendering
[cli11 github]: https://github.com/CLIUtils/CLI11
[ImageMagick github]: https://github.com/ImageMagick/ImageMagick
[fmtlib github]: https://github.com/fmtlib/fmt

