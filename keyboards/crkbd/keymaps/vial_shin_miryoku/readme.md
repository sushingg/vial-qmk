[JSON file of the Miryoku from manna-harbour](https://www.reddit.com/r/crkbd/comments/1bxrv2y/corne_keyboard_want_to_use_miryoku_qmk_how_to_add/)

qmk generate-compilation-database -kb crkbd/rev1 -km vial_shin_miryoku

# Crkbd with Miryoku and custom layers displays.

1 - I got a JSON file of the Miryoku from manna-harbour.

https://github.com/manna-harbour/miryoku/blob/master/data/configurator/miryoku-configurator-crkbd.json

2 - I used this link to make the JSON more readable:

https://jhelvy.shinyapps.io/qmkjsonconverter/

3 - You can upload the readable JSON to QMK Configurator for some custom modifications to be visualized: https://config.qmk.fm/

4 - After downloading the JSON from QMK Configurator (step 3), upload it again to step 2 to convert it back to readable code.

Now you can get this code and create a keymap.c file (QMK toolbox is necessary to compile your custom images and keymap).

Link to my files (for reference):

https://github.com/memmoxt/qmk_firmware/tree/master/keyboards/crkbd/keymaps/memmoxt/files/current

5 - To make custom OLED layers you can use this site:

https://joric.github.io/qle/

(I use the "Raw data" tab to get the code).

Now you can simply copy and paste the code to your keymap.c according to your layer.

6 - Flash your config with QMK toolbox.

I use Linux with the CLI terminal command: qmk flash -kb crkbd -km [mycustomkeymap] -bl dfu

I hope this helps you out. I don't think it's the best way to configure the keyboard, but it's the way I got it working for me.

# compile

```bash
make crkbd/rev1:vial_shin_miryoku CONVERT_TO=rp2040_ce
```