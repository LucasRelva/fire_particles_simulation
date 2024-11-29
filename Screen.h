//
// Created by lucas.relva on 28/11/2024.
//

#ifndef SCREEN_H
#define SCREEN_H
#include <SDL2/SDL.h>

namespace mystf {
    class Screen {
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;
        Uint32 *m_buffer_2;

    public:
        static constexpr int SCREEN_WIDTH = 800;
        static constexpr int SCREEN_HEIGHT = 600;

        Screen();
        bool init();
        void update();
        void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) const;
        bool process_events();
        void close();
        void box_blur();
    };
} // mystf

#endif //SCREEN_H
