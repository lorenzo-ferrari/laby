# Labyrinth Generator

### Description

This is a labyrinth generator.
* The program uses a recursive approach to randomly build a tree on a ```ROWSxCOLUMNS``` plan.
* ```ROWS``` and ```COLUMNS``` are both constants declared in [constants.h](/src/constants.h).
* Make sure you use c++17 or later.

### I/O

* By default, the program writes to stdout.
* this setting can be easily modified in the [main](/src/main.cpp) defining ```OUTPUT_FILE``` and uncommenting "```freopen(OUTPUT_FILE, "w", stdout);```" (line 14).

### Example:

```
#####################################################
# #   #                       #     #               #
# # # ### ########### ######### # ### ########### ###
# # #   #   #   #   #         # #       #       #   #
# # ### ##### # # # ### ##### # ######### ##### ### #
# # #   #     # # #   # # #   #       #   # #   #   #
# # # ### ##### # ### # # # ######### # ### # ### # #
# # # # #     #   # # #   #       #   # #     #   # #
# # # # # ### ##### # ####### ##### ### # ##### # # #
#   # #     #   #   #     #   #       # # #   # # # #
##### ##### ### # ####### # ### ####### # # ### # # #
#   #     # #   #       # # #       #   # #     # # #
# # ##### # # ### ### # # # # ####### ### # ##### # #
# # #     # # # # #   # # # # #       #   # #     # #
# ### ####### # # # ### # # # # ####### ##### ##### #
#   # #       # # # #   # #   # #     #   #   #     #
# # # ##### ### # # ##### # ### # # ##### # ##### ###
# # #     # #   # # #   # # #   # #       #     #   #
# # ##### # # # # # # # # # # ### ############# ### #
# # #     # # #   #   # # # #   #   #   #     #   # #
# # # ##### # ######### # ##### ### # # # ### ### # #
# #         #         #         #     #   #       # #
#####################################################
```