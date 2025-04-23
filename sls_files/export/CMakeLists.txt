SET(SOURCES ui_mainScreen.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_img_640501820.c
    ui_img_472354705.c
    ui_img_901948647.c
    fonts/ui_font_14segment10.c
    fonts/ui_font_14segment18.c
    fonts/ui_font_7segment18.c
    fonts/ui_font_7segment36.c)

add_library(ui ${SOURCES})
