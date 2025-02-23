#!/data/data/com.termux/files/usr/bin/python3
# -*- coding: utf-8 -*-
# Ahad-23-Feb 18:51:50 2025 🦊 || anonvict

'''
pip install blessed
'''

import blessed
import time, random

term = blessed.Terminal()
emoji = ["😁","💀","🥶","😆","🤣","😘","😜"]

def emoji_berantakan(x, y, emoji_type, size):
    scaled_flower = emoji_type * size
    with term.location(x, y):
        print(term.random_color() + scaled_flower)

with term.fullscreen() and term.hidden_cursor():
    for frame in range(200):
        for i in range(50):
            emoji_type = random.choice(emoji)
            size = random.randint(1, 3)
            x = random.randint(0, term.width - 1 - 3 * size)
            y = random.randint(0, term.height - 1)
            emoji_berantakan(x, y, emoji_type, size)
        time.sleep(0.05)
        print(term.clear)
