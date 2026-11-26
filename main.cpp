#include <iostream>
#include <SDL3/SDL.h>

#include "src/graphics.h"

gfx_context* gfx_debug_ctx = nullptr;
gfx_context* gfx_render_ctx = nullptr;

void core_init_gfx_context();

int main()
{
    std::cout << "Hello world" << std::endl;
    core_init_gfx_context();
    return 0;
}

void core_init_gfx_context()
{
    const SDL_Color COLOR_BLACK = {0, 0, 0, 0};

    gfx_debug_ctx = gfx_init(256, 256, "Debug");
    gfx_clear(gfx_debug_ctx, COLOR_BLACK);
    gfx_update(gfx_debug_ctx);

    gfx_render_ctx = gfx_init(256, 256, "GameBoy");
    gfx_clear(gfx_render_ctx, COLOR_BLACK);
    gfx_update(gfx_render_ctx);
}
