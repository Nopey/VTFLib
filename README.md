# VTFLib - Magnus' fork
Notable changes:
- Added **read-only** support for more HDR Formats, including BC6H
- Wrote cmake scripts for VTF utilities (VTFEdit, VTFCmd)
- Removed binary blobs for thirdparties

Known issues:
- Linux port has likely regressed
- The only non-floating point HDR format I've tested, RGBA16161616,
  appears darker than the other HDR formats;
  may be an issue with how I'm creating my test files.

Planned changes:
- PFM Import
- Support writing BC6H and other HDR formats

Includes code from the following VTFLib versions:
- Neil 'Jed' Jedrzejewski & Ryan Gregg's original work, https://github.com/NeilJed/VTFLib
- Joshua-Ashton's fork, https://github.com/Joshua-Ashton/VTFLib  
  ("VTFEdit Reloaded", Compressonator port, many other changes taken for granted)
- StrataSource fork, https://github.com/StrataSource/VTFLib  
  (Partial CMake port, VTF 7.6 support, BC7 support)

Honorable mention:
- TricoEverfire's fork https://github.com/Trico-Everfire/VTFLib/tree/feat/floating_point_support  
  Did not notice their fork or [PR] to Strata before starting work.

[PR]: https://github.com/StrataSource/VTFLib/pull/9

# VTFLib - A Valve VTF and VMT image format programming library.

VTFLib is a LGPL open source programming library that provides a C and C++ API that, with a few simple functions, can open and save .vtf and .vmt files, providing access to all known features. The library functions independent of Steam, allowing third party applications to use the library without Steam present or runningi on the target system.

VTFLib includes two GPL example applications, VTFCmd and VTFEdit. VTFCmd is a C command line frontend for VTFLib that can create .vtf and .vmt files from various source formats. It is similar in functionality to Valve's vtex Source SDK utility, but offers a lot more control. VTFEdit is a C++ .NET graphical frontend for VTFLib with viewing and creation capabilities. Both VTFCmd and VTFEdit support several source image formats, including, but not limited to .bmp, .dds, .gif, .jpg, .png and .tga.

## Library/Author Information

* **Title**: VTFLib
* **Written In**: C/C++
* **Date**: July 25th, 2011
* **Authors**: [Neil 'Jed' Jedrzejewski](https://github.com/NeilJed) & [Ryan Gregg](http://nemesis.thewavelength.net/)

## Project Structure

The library contains five folders:

* **Bin** - Contains library and example program binaries.
* **Lib** - Contains library C and C++ Header and Inline Files.
* **Sln** - Contains Visual Studio solutions.
* **VTFCmd** - Contains C example program source code.
* **VTFEdit** - Contains C++ .NET example program source code.
* **VTFLib** - Contains C++ library source code.

The project files are for Visual Studio .NET 2003 and 2005; no .NET extensions are used except in VTFEdit. Visual Studio 6.0 project files have also been
included, but nvDXTLib does not come with the correct .lib files to link with. nvDXTLib is required for VTF creation and can be downloaded from:

http://developer.nvidia.com/object/dds_utilities_legacy.html

## VTFCmd Usage

```
Correct vtfcmd usage:
 -file <path>             (Input file path.)
 -folder <path>           (Input directory search string.)
 -output <path>           (Output directory.)
 -prefix <string>         (Output file prefix.)
 -postfix <string>        (Output file postfix.)
 -version <string>        (Ouput version.)
 -format <string>         (Ouput format to use on non-alpha textures.)
 -alphaformat <string>    (Ouput format to use on alpha textures.)
 -flag <string>           (Output flags to set.)
 -resize                  (Resize the input to a power of 2.)
 -rmethod <string>        (Resize method to use.)
 -rfilter <string>        (Resize filter to use.)
 -rwidth <integer>        (Resize to specific width.)
 -rheight <integer>       (Resize to specific height.)
 -rclampwidth <integer>   (Maximum width to resize to.)
 -rclampheight <integer>  (Maximum height to resize to.)
 -gamma                   (Gamma correct image.)
 -gcorrection <single>    (Gamma correction to use.)
 -nomipmaps               (Don't generate mipmaps.)
 -mfilter <string>        (Mipmap filter to use.)
 -nwrap                   (Wrap the normal map for tiled textures.)
 -bumpscale <single>      (Engine bump mapping scale to use.)
 -nothumbnail             (Don't generate thumbnail image.)
 -noreflectivity          (Don't calculate reflectivity.)
 -shader <string>         (Create a material for the texture.)
 -param <string> <string> (Add a parameter to the material.)
 -recurse                 (Process directories recursively.)
 -exportformat <string>   (Convert VTF files to the format of this extension.)
 -silent                  (Silent mode.)
 -pause                   (Pause when done.)
 -help                    (Display vtfcmd help.)

Example vtfcmd usage:
vtfcmd.exe -file "C:\texture1.bmp" -file "C:\texture2.bmp" -format "dxt1"
vtfcmd.exe -folder "C:\input\*.tga" -output "C:\output" -recurse -pause
vtfcmd.exe -folder "C:\output\*.vtf" -output "C:\input" -exportformat "jpg"
```

## VTFEdit Reloaded Changelog

  v2.0.0
  - Migrated to using AMD Compressonator for DXT compression.
  - Fix the green tinge when exporting textures
  - Respect sRGB-ness when generating mipmaps and resizing.
  - Ported to using the latest CLR and VS 2019.
  - Removed crufty sharpening filters (no longer needed with proper sRGB)
  - Use monospace font for VMT editor
  - High DPI support
  - Syntax highlighting support for VMTs
  - Fixed cubemap previews
    - Previously they were doing integer maths on what should be floats
    - Replaced overly complex controls with a simple exposure slider
    - Very simple Reinhard tonemapper for previewing exposure

## Library Changelog

  v1.3.2
  - Improved support for version 7.5 of the VTF format.

  v1.3.1
  - Added support for version 7.5 of the VTF format.

  v1.3.0
  - Added support for x64.
  - Removed Visual Studio 2003 solution.
  - Removed Visual Studio 6 solution.
  - Upgraded NVDXT library to 8.31.1127.

  v1.2.7
  - Added support for version 7.4 of the VTF format.
  - Added custom author information resource.

  v1.2.6
  - Added support for version 7.3 of the VTF format.
  - Added loose VMT parsing mode.
  - Added Visual Studio 2005 solution.
  - Added Visual Studio 6 solution.
  - Improved various error messages.

  v1.2.5
  - Tightly packed all structures to ease importing.
  - Upgraded NVDXT library to 8.31.0225.

  v1.2.4
  - Added recognition for new HDR formats.
  - Added optimal convertion paths for common convertions.
  - Improved .vmt parsing.

  v1.2.3
  - Added linear shifting and gamma correction to tone mapping.

  v1.2.2
  - Added support for zero mipmap textures.
  - Fixed volume texture image data offsets.
  - Fixed volume texture reflectivity calculation.

  v1.2.1
  - Added tone mapping.
  - Rewrote all format conversion code.

  v1.2.0
  - Added partial support for version 7.2 of the VTF format.
  - Fixed RGBA16161616F encoding and decoding.

  v1.1.3
  - Improved .vmt parsing.

  v1.1.2
  - Upgraded NVDXT library to 7.83.0629.

  v1.1.1
  - Extended CVTFFile class.

  v1.1.0
  - Added .vtf and .vmt proc load and save code.
  - Added .vtf signature check.

  v1.0.2
  - Added .vtf resize code.
  - Improved reflectivity compution code.
  - Improved NVDXT library error detection.

  v1.0.1
  - Added C .vmt saving routines.
  - Added additional C .vmt transversal routines.
  - Rewrote .vmt parser to be more lenient.

  v1.0.0
  - Original build.

## VTFCmd Changelog

  v1.1.1
  - Improved support for version 7.5 of the VTF format.

  v1.1.1
  - Added support for version 7.5 of the VTF format.

  v1.1.0
  - Added support for x64.

  v1.0.10
  - Added support for version 7.4 of the VTF format.

  v1.0.9
  - Added support for version 7.3 of the VTF format.
  - Added export format option.
  - Improved help.

  v1.0.8
  - Added .vtf alpha format, clamp resize, no mipmap and version options.
  - Improved drag-and-drop suport.

  v1.0.7
  - Added the ability to convert .vtf files to .tga.

  v1.0.6
  - Added partial support for version 7.2 of the VTF format.

  v1.0.5
  - Added drag-and-drop support.

  v1.0.4
  - Fixed -recurse option bug.
  - Improved output.

  v1.0.3
  - Added .vtf normal map wrap option.

  v1.0.2
  - Added .vtf resize option.

  v1.0.1
  - Added .vmt creation option.
  - Fixed folder wildcard bug.

  v1.0.0
  - Original build.

## VTFEdit Changelog:

  v1.3.3
  - Updated to HLLib v2.4.2.
  - Improved support for version 7.5 of the VTF format.

  v1.3.2
  - Updated to HLLib v2.4.0.

  v1.3.1
  - Added support for version 7.5 of the VTF format.

  v1.3.0
  - Added support for x64.
  - Updated to HLLib v2.3.0.

  v1.2.5
  - Added support for version 7.4 of the VTF format.
  - Added custom author information resource.
  - Updated to HLLib v2.0.8.

  v1.2.4
  - Added support for version 7.3 of the VTF format.
  - Added VTF version option.
  - Added VMT parsing strictness option.
  - Added resource creation tab.
  - Added resource info tab.
  - Added configurable batch export format.
  - Added png export format.

  v1.2.3
  - Added workaround for threading state bug.
  - Updated to HLLib v2.0.6.

  v1.2.2
  - Added drag and drop support.
  - Updated to HLLib v2.0.2.

  v1.2.1
  - Fixed several export bugs.

  v1.2.0
  - Added linear shifting and gamma correction to tone mapping.
  - Fixed thread apartment state bug.

  v1.1.9
  - Added "Export All" option.
  - Added several advanced VTF creation options.
  - Added "from .vtf" support to batch conversion tool.

  v1.1.8
  - Added tone mapping control.

  v1.1.7
  - Added partial support for version 7.2 of the VTF format.

  v1.1.6
  - Added file system watching.
  - Added .vmt text editing capabilities.
  - Improved .vmt parsing.
  - Fixed some minor menu bugs.

  v1.1.5
  - Added batch conversion tool.
  - Added no alpha and alpha format option.
  - Improved WAD conversion tool.

  v1.1.4
  - Added .vmt creation tool.
  - Added default .vmt creation option.

  v1.1.3
  - Added .vtf file info group.
  - Fixed .vtf tile setting bug.
  - Improved interface.

  v1.1.2
  - Added .vtf tile feature.
  - Added .vtf normal map wrap option.

  v1.1.1
  - Added convert WAD dialog.
  - Added .vtf resize option.
  - Fixed toolbar save button bug.

  v1.1.0
  - Added a toolbar.
  - Added a file system browser tab.
  - Added .vtf paste as new option.
  - Added .vtf zooming feature.
  - Added .vtf alpha channel mask.

  v1.0.0
  - Original build.


## Program Copyright-Permissions

See the lgpl.txt (VTFLib) and gpl.txt (VTFCmd & VTFEdit) files contained in the distribution.
