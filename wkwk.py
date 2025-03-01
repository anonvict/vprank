#!/data/data/com.termux/files/usr/bin/python3
# -*- coding: utf-8 -*-
# Ahad-23-Feb 18:58:57 2025 🐬 || anonvict

import curses
import time, signal, sys

def utama(layar):
    curses.curs_set(0)
    layar.nodelay(1)

    curses.start_color()
    curses.init_pair(1, curses.COLOR_GREEN, curses.COLOR_BLACK)

    pesan = "SESI INI TERKUNCI"
    masukan_pengguna = []
    tampilkan_pesan = True

    def keluar_dengan_aman(sinyal, bingkai):
        layar.addstr(layar.getmaxyx()[0] // 2, layar.getmaxyx()[1] // 2 - len("haha") // 2, "haha", curses.color_pair(1))
        layar.refresh()
    def abaikan_tstp(sinyal, bingkai):
        layar.addstr(layar.getmaxyx()[0] // 2, layar.getmaxyx()[1] // 2 - len("haha") // 2, "haha", curses.color_pair(1))
        layar.refresh()
    def abaikan_keluar(sinyal, bingkai):
        layar.addstr(layar.getmaxyx()[0] // 2, layar.getmaxyx()[1] // 2 - len("haha") // 2, "haha", curses.color_pair(1))
        layar.refresh()
    signal.signal(signal.SIGINT, keluar_dengan_aman)
    signal.signal(signal.SIGTSTP, abaikan_tstp)
    signal.signal(signal.SIGQUIT, abaikan_keluar)

    while True:
        layar.clear()
        baris, kolom = layar.getmaxyx()
        x = kolom // 2 - len(pesan) // 2
        y = baris // 2

        if tampilkan_pesan:
            layar.addstr(y, x, pesan, curses.color_pair(1) | curses.A_BOLD)

        layar.refresh()
        tombol_ditekan = layar.getch()

        if tombol_ditekan != -1:
            masukan_pengguna.append(chr(tombol_ditekan))

        teks_masukan_pengguna = "".join(masukan_pengguna)
        if teks_masukan_pengguna == "I":
            exit()

        time.sleep(0.05)
        tampilkan_pesan = not tampilkan_pesan

if __name__ == "__main__":
    curses.wrapper(utama)
