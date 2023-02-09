# SubD and Conquer


## Features

TODO

## Gallery

* Custom made Half-edge Data Structure

* Loading of general polygon mesh (i.e. mesh with n-gons) using `tinyobjloader`.

## Build

### Build Instructions

This project uses CMake as build system generator. It's necessary to have it installed on your system. Additionaly, `git submodules` is used to add `vcpkg` as a dependency manager and to add `geometry-central` as a dependency. Execute the following commands on the command-line to clone, configure and build the project:

```
# If you hadn't clone the repository yet:
git clone --recurse-submodules https://github.com/math-araujo/subd-and-conquer.git
# NOTE: Did you remember to clone recursively using --recurse-submodules?

cd subd-and-conquer

# On Windows + MSVC
cmake --preset=msvc

cmake --build build --config Release

# On Unix
cmake --preset=default-unix

cmake --build build

```

In case you forgot to clone the repository recursively, run the following command with the command line open on the root of the repository:

```
git submodule update --init --recursive
```

Feel free to open an issue should any problem arise. 

<details><summary>Failure to use FetchContent</summary>
Usually I don't use git submodules and use CMake FetchContent module, even for downloading and building vcpkg. However, an enigmatic error arised when trying to use FetchContent to download both vcpkg **and** geometry-central. The configuration was successfull using either one, but failed when I tried to use FetchContent for both repositories simultaneously. I'm still investigating this issue, but for the time being I settled with using both vcpkg and geometry-central through git-submodules. 
</details>

## Controls

* A/S/D/W Key - Move left/backward/right/forward

* Q/E Key - Move down/up

* F Key - Switch between free FPS movement and locked FPS movement

* P Key - Switch between polygon mode and wireframe mode

* ESC Key - Exit application

* Left Mouse Button - Hold and move mouse to look-around when in locked FPS mode


## LICENSE

All the code is released under MIT License. Check the LICENSE file on this repository for details.