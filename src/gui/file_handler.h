#ifndef PATHFIND_FILE_HANDLER_H
#define PATHFIND_FILE_HANDLER_H

#include "../engine/canvas.h"

enum {
    MAX_CANVAS_WIDTH_EXCEEDED = -1,
    MAX_CANVAS_HEIGHT_EXCEEDED = -2,

    INCONSISTENT_CANVAS_SIZE = -11,

    ILLEGAL_BORDER_ELEMENT = -21,
    ILLEGAL_ELEMENT = -22,
    ILLEGAL_START_COUNT = -23,
    ILLEGAL_END_COUNT = -24,

    CANVAS_FILE_READ_REALLOC_FAILURE = -31,
    CANVAS_PIXEL_ARRAY_MEMCPY_FAILURE = -32,
};

int write_canvas_to_file(char *file_name, canvas *c);
int read_canvas_from_file(char *file_name, canvas *return_canvas);

#endif