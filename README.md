# DataLogger
connects to sensor board via SPI connector on the CYD labelled CN1, chip select pins are on connector P3. Shows graphical interface for reading data, transfering files and reading sensor data.

## Building and Flashing

Recommend putting this project into `C:/Users/username/esp/`. Do this with:
```sh
> cd \
> cd Users\username\
> mkdir esp\
> git clone --recursive [To be determined]
```

### Install Tools

First you will need to download the [ESP-IDF tools](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html#installation). The process is documented on the ESP wiki site and is easy to follow.

After Installing the ESP-IDF, open the ESP-IDF command prompt, using this automatically adds the required tools to your path which would not otherwise be available. *You cannot open regular command prompt and run idf.py.*

### Getting dependencies

Dependencies are managed by ESP-IDF so you do not need to bother with manually including things and keeping the components up to date.
There are two kinds of dependencies in the IDF:

1. Default components, that can be found in `C:\Espressif\frameworks\esp-idf-vX.X.X\components`
2. Managed components, they are initially listed in `[project dir]/main/idf_component.yml` but are put in `[project dir]/main/managed_components/` automatically by the IDF when the command `idf.py menuconfig` is run.

Some available components that can be added to your project can be found in the [ESP Board Support Packages List](https://github.com/espressif/esp-bsp).
There are other lists of available packages in the Espressif github repos.

For the dependencies in this project, the idf_component.yml will look like this:

```yml
dependencies:
  espressif/esp_lcd_ili9341: "^2.0.0"
  atanisoft/esp_lcd_touch_xpt2046: "^1.0.3"
  espressif/esp_lvgl_port: "^2.0.0"
  lvgl/lvgl: "^9.1.0"

  idf:
    version: ">=5.2.0"
```

### Configuring Environment

You can choose to add the collowing lines to the `.vscode\c_cpp_properties.json` file for the intellisense to find your libraries

```JSON
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/Espressif/frameworks/esp-idf-v5.4.1/components/**",
                "C:/Espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/xtensa-esp-elf/include/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.22621.0",
            "compilerPath": "cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}

```

If you have installed additional libraries that are not managed by ESP-IDF they can also be included here under the IncludePath. Just remember to exchange the backslash for a forwardslash when copying paths on windows. The `**` at the end of the path means search recursively in that location for the included files.

### Compile

Before you compile for the first time you must run:

```sh
> idf.py menuconfig
```

This command will scan the idf_component.yml file and download your dependencies for you, without doing this you will get many errors, it will be very sad. Run the menuconfig. After running the menuconfig to generate the required file you will not need to run it again, from now on you can just run:

```sh
> idf.py build
```

Which will invoke cmake and ninja to build your project. This creates a folder called `build` in the project directory, if you want to clean build you can delete this folder and run the build command again. This can be useful if you encounter some linker errors sometimes.

### Flash

In the ESP-IDF command prompt session run the idf.py with `-p COM[number] flash` arguments.
You can find the COM port number from the device manager window under  `Ports (COM & LPT)`. The ESP will show up as `USB-SERIAL CH430 (COM3)

```sh
> idf.py -p COM3 flash
```

## Using the IDF

## Using LVGL

# See also:

* Graphics library used: [lvgl](https://github.com/lvgl/lvgl/)
* Port of Graphics library: [esp_lvgl_port](https://components.espressif.com/components/espressif/esp_lvgl_port)
* Original repo of code: [ESP32-2432S028R](https://github.com/limpens/esp32-2432S028R)
* Info on the hardware: [The CYD github](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main)
