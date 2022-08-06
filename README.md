
# Programming: Principles and Practice Using C++ (2nd Edition)


The Computer Science course that I'm taking (University of Leeds) decided to focus on teaching Java.\
As someone who is interested in graphics and game development, I knew that I had to learn C++, one way or another.

Thus, I dedicated a portion of my summer breaks to go through this **book by [Bjarne Stroustrup](https://stroustrup.com/)**.

I have  attempted to solve as many of the end-of-chapter exercises as possible.\
Where time was limited, I chose to solve the ones that looked the most interesting to me.

I have not completed the final chapters of the book.\
My intention is to save those as "refreshers", working through them if I need to.

### A note about coding style
I treated this book, and by extension this repository, as a learning experience rather than a project.\
Therefore, the coding style may not be consistent across each chapter.

---

## How To Compile
Most of the exercises can simply be compiled on the command line using a compiler that supports **C++ 14**. (I used MSVC)\
Where multiple files are involved with an exercise, I have provided a CMakeLists.txt file.

### GUI code from Chapter 11-16
The code in these chapters require the [FLTK](https://www.fltk.org/) library to be installed and configured.

Getting this to work with CMake proved too difficult (due to no/outdated documentation and resources).\
As a result I have provided a Visual Studio solution file for any code that requires this library.

Installing and setting up the library isn't very intuitive. I have got it working on my system (Windows 10, Visual Studio 2022) using [vcpkg](https://vcpkg.io/en/index.html).\
Please refer to this link for some more instuctions: [Install FLTK with vcpkg](https://stackoverflow.com/a/60455042).

<br>
<br>
<p align="center" style=>
  <img src="https://www.informit.com/ShowCover.aspx?isbn=0321992784" />
</p>
