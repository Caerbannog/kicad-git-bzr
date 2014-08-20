/**
 * @file 3d_viewer_id.h
 */

/**
 * Command IDs for the 3D viewer.
 *
 * Please add IDs that are unique to the 3D viewer here and not in the global
 * id.h file.  This will prevent the entire project from being rebuilt when
 * adding new commands to the 3D viewer.
 * However the number of IDs should be < ROOM_FOR_3D_VIEWER, defined in id.h
 * Please change the value of ROOM_FOR_3D_VIEWER if too small.
 */

#include <id.h>        // Generic Id.

enum id_3dview_frm
{
    ID_START_COMMAND_3D = ID_KICAD_3D_VIEWER_START,
    ID_ROTATE3D_X_NEG,
    ID_ROTATE3D_X_POS,
    ID_ROTATE3D_Y_NEG,
    ID_ROTATE3D_Y_POS,
    ID_ROTATE3D_Z_NEG,
    ID_ROTATE3D_Z_POS,
    ID_RELOAD3D_BOARD,
    ID_TOOL_SCREENCOPY_TOCLIBBOARD,
    ID_MOVE3D_LEFT,
    ID_MOVE3D_RIGHT,
    ID_MOVE3D_UP,
    ID_MOVE3D_DOWN,
    ID_ORTHO,
    ID_MENU3D_COLOR,
    ID_MENU3D_BGCOLOR_SELECTION,
    ID_MENU3D_BGCOLOR_TOP_SELECTION,
    ID_MENU3D_USE_COPPER_THICKNESS,
    ID_MENU3D_AXIS_ONOFF,
    ID_MENU3D_MODULE_ONOFF,
    ID_MENU3D_ZONE_ONOFF,
    ID_MENU3D_LAYERS,
    ID_MENU3D_ADHESIVE_ONOFF,
    ID_MENU3D_SILKSCREEN_ONOFF,
    ID_MENU3D_SOLDER_PASTE_ONOFF,
    ID_MENU3D_SOLDER_MASK_ONOFF,
    ID_MENU3D_COMMENTS_ONOFF,
    ID_MENU3D_ECO_ONOFF,
    ID_MENU3D_SHOW_BOARD_BODY,
    ID_MENU3D_REALISTIC_MODE,
    ID_MENU3D_FL_RENDER_SHADOWS,
    ID_MENU3D_FL_RENDER_SHOW_HOLES_IN_ZONES,
    ID_MENU3D_FL_RENDER_TEXTURES,
    ID_MENU3D_FL_RENDER_SMOOTH,
    ID_MENU3D_FL_RENDER_MATERIAL,
    ID_END_COMMAND_3D,

    ID_TOOL_SET_VISIBLE_ITEMS,

    ID_MENU3D_GRID,
    ID_MENU3D_GRID_NOGRID,
    ID_MENU3D_GRID_10_MM,
    ID_MENU3D_GRID_5_MM,
    ID_MENU3D_GRID_2P5_MM,
    ID_MENU3D_GRID_1_MM,
    ID_MENU3D_GRID_END,

    ID_MENU_SCREENCOPY_PNG,
    ID_MENU_SCREENCOPY_JPEG,
    ID_MENU_SCREENCOPY_TOCLIBBOARD,

    ID_POPUP_3D_VIEW_START,
    ID_POPUP_ZOOMIN,
    ID_POPUP_ZOOMOUT,
    ID_POPUP_VIEW_XPOS,
    ID_POPUP_VIEW_XNEG,
    ID_POPUP_VIEW_YPOS,
    ID_POPUP_VIEW_YNEG,
    ID_POPUP_VIEW_ZPOS,
    ID_POPUP_VIEW_ZNEG,
    ID_POPUP_MOVE3D_LEFT,
    ID_POPUP_MOVE3D_RIGHT,
    ID_POPUP_MOVE3D_UP,
    ID_POPUP_MOVE3D_DOWN,
    ID_POPUP_3D_VIEW_END
};
