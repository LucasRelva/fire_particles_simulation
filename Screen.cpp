//
// Created by lucas.relva on 28/11/2024.
//
#include "Screen.h"
#include <iostream>

using namespace std;

namespace mystf {
    Screen::Screen() {
        m_window = nullptr;
        m_renderer = nullptr;
        m_texture = nullptr;
        m_buffer = nullptr;
        m_buffer_2 = nullptr;
    }

    bool Screen::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            cerr << "Failed to initialize SDL: " << SDL_GetError() << endl;
            return false;
        }

       m_window = SDL_CreateWindow(
            "Explosion",
            100,
            100,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );

        if (m_window == nullptr) {
            cerr << "Failed to create m_window: " << SDL_GetError() << endl;
            SDL_Quit();
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(
            m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT
        );

        if (m_texture == nullptr) {
            cerr << "Failed to create m_texture: " << SDL_GetError() << endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        if (m_renderer == nullptr) {
            cerr << "Failed to create m_renderer: " << SDL_GetError() << endl;
            SDL_DestroyTexture(m_texture);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        m_buffer_2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(m_buffer_2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        return true;
    }

    void Screen::update() {
        SDL_UpdateTexture(m_texture, nullptr, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
        SDL_RenderPresent(m_renderer);
    }

    void Screen::set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) const {
        if (x<0 || x>=SCREEN_WIDTH || y<0 || y>=SCREEN_HEIGHT) {
            return;
        }

        Uint32 color = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        m_buffer[y * SCREEN_WIDTH + x] = color;
    }

    bool Screen::process_events() {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
        }

        return true;
    }

    void Screen::close() {
        delete[] m_buffer;
        delete[] m_buffer_2;
        SDL_DestroyTexture(m_texture);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    void Screen::box_blur() {
        // * swap buffers so pixel is in m_buffer_2, and we draw to m_buffer
        Uint32 *aux_buffer = m_buffer;

        m_buffer = m_buffer_2;
        m_buffer_2 = aux_buffer;

        // * blur the screen
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {

                int red_total = 0;
                int green_total = 0;
                int blue_total = 0;

                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {
                        int x_pos = x + col;
                        int y_pos = y + row;

                        if (x_pos >= 0 && x_pos < SCREEN_WIDTH && y_pos >= 0 && y_pos < SCREEN_HEIGHT) {
                            Uint32 color = m_buffer[y_pos * SCREEN_WIDTH + x_pos];
                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;

                            red_total += red;
                            green_total += green;
                            blue_total += blue;
                        }
                    }
                }

                Uint8 red = red_total / 9;
                Uint8 green = green_total / 9;
                Uint8 blue = blue_total / 9;

                set_pixel(x, y, red, green, blue);

            }
        }
    }
} // mystf
