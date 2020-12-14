# Timer

## C++, Qt Quick

### Features
- Start/Pause/Reset Timer
- Set Time on Timer
- Notification on Time Out (Alarm Sound)
- Set Custom Alarm Sound
- List of Saved Time
- Material Design
- Light and Dark Themes
- Responsive Design
- Logger

### How to build and how to run
Probably the simplest way to launch the application is to do it from `Qt Creator`.
However, if this is not an option for you, next I will show how to do it with `command line` and `cmake`

**Before we start, please add `Qt bin` location (e.g. `C:\Qt\5.15.1\mingw81_64\bin`) to your `path` environment variable.**
Otherwise, you will have to manually copy dlls to your build directory, 
define environment variables in your run configuration (e.g. `QT_QPA_PLATFORM_PLUGIN_PATH`) and configure other nasty stuff

```
- cd <project root>
- mkdir build
- cd build
- cmake -G <Generator> ..
- make
- Timer
```
`cmake -G` - To list all generators

If `make` doesn't work for you, try `cmake --build build --target Timer` from project root
