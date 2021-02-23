# How to contribute to **ffmpeg-coder**

I'm really happy that you are here & reading this. If you are interested in contributing to this project and make it larger then this section will help you get started.

This project needs more contributors. And any beginner **C++** programmer will be able to contribute to this project.

### Some important links & resources
- In case you need more details, you can [mail](mailto:abirtx@yandex.com) me at this address abirtx@yandex.com

- If you want to test the tool or use it in your system before contributing [here](https://github.com/Abir-Tx/ffmpeg-coder#installation) is the installation guide for different OS

- My goal is to add all the ffmpeg options to this tool with easy instructions so that users can generate commands without any hassle or knowing.

- You can contribute by submitting issues, or by fixing a problem/bugs or by implementing new features by submitting **Pull requests**.

- As the project is based on ffmpeg commands generation you should have a basic knowledge about **ffmpeg** CLI and how to create commands for converting videos with different options using ffmpeg command line interface. You can get to know about ffmpeg from [here](https://ffmpeg.org/ffmpeg.html).

## Found Bugs ?
- Submit the issue [here](https://github.com/Abir-Tx/ffmpeg-coder/issues/new/choose)

Read more from the [**Having Issues**](https://github.com/Abir-Tx/ffmpeg-coder#having-issues-) section.

## Did you find patch or a fix for a Bug?

- Open a [new GitHub Pull Request](https://github.com/Abir-Tx/ffmpeg-coder/compare) with your patch or code changes.

- Describe the problem and your fix/code changes clearly. Include the relevant issue number if applicable.

## Contributing to documentations?

You can also contribute to the project by adding documentation as the projects documentation or wiki is not completed yet. So if you are interested to enhance the documentation then you are most welcome.

Just creare a pull request with your documentation changes or you can email me too.

## Adding new features or extending the tool

If you really want to contribute to this project, the best way is to get familiar with the project structure and files and then implement the features needed. So much features are left to add to this project as **ffmpeg** is a very powerfull tool and has so many commands to offer. So you can add any ffmpeg video converting command generation feature to this project. 

- First you need to know some basics of ffmpeg CLI commands so that you can use those commands in this project to add features

- Get familiar with the source code and project structure so that is becomes easier for you to implement the features. The project structure & source code is described [here](https://github.com/Abir-Tx/ffmpeg-coder/doc/source-code.md)

- Add your code/feature by forking this project first & then write your codes & then submit the changes by creating a pull request

- Further discussions can be done with me using my mail address provided above.

## Submitting chnages
Please follow the projects coding conventions (below) and make sure all of your commits are atomic (one feature per commit).

Always write a clear log message for your commits. One-line messages are fine for small changes, but bigger changes should look like this:

    $ git commit -m "A brief summary of the commit
    > 
    > A paragraph describing what changed and its impact."

## Building/compiling the source code

When writing codes for this project you will need to test the code first before submitting. To test the code you will need to compile the code. I have made it easier to compile the whole source code with all the header files using **Makefile**. So first ensure that **make** is installed in your system.

The build process is described in the projects readme in the installation section. 

- [Get to know about the build process](https://github.com/Abir-Tx/ffmpeg-coder#install-from-source)


## Coding Conventions
The project uses a [```.clang-format```](https://github.com/Abir-Tx/ffmpeg-coder/blob/main/.clang-format) file to maintain the coding convention across the whole project for all the cpp & hpp (source & header) files. 

After you finished your code writing for this project always try to format your code/file using the projects [```.clang-format```](https://github.com/Abir-Tx/ffmpeg-coder/blob/main/.clang-format) file.

To do so - 

- Install clang-format in you system & set up. Know more about [clang-format](https://clang.llvm.org/docs/ClangFormat.html)

- Use this command to use this projects clang format file while formatting the source code 

```bash
clang-format -style=file -i your-changed-file.cpp
```


