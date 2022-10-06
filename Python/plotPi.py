import matplotlib.pyplot as plt
from math import pi
import numpy as np
import pyautogui as gui

def PrintLeibnizsPI():
    approx_pi = 0;
    prev = 0
    for i in range(1000):
        den = i*2 + 1
        prev = approx_pi
        if i&1:
            approx_pi -= (4.0/den)
            # plt.text(i+1, approx_pi-0.04, f'{approx_pi:.5f}', fontsize='5')
        else:
            approx_pi += 4.0/den
            # plt.text(i+1, approx_pi+0.01, f'{approx_pi:.5f}', fontsize='5')
        if prev:
            x1 = np.linspace(i, i+1, 2)
            y1 = np.linspace(prev, approx_pi, 2)
            plt.plot(x1, y1)
        error = abs(pi-approx_pi)
        x2 = np.linspace(i, i+1, 2)
        y2 = [pi]*len(x2)
        plt.plot(x2, y2, 'b--')
        plt.title(r"Leibniz's Formula for Pi")
        plt.xlabel(f'Current Approximation: {approx_pi}\nError: {(error)}', color='r', fontsize='22')
        plt.tight_layout()
        plt.pause(0.001)
        mousePos = gui.position()[0]
        if mousePos<50:
            # Hover to left of screen to stop the animation
            print('Fuck! not again!')
            exit(0)
        if mousePos>1200:
            # Hover to right of screen to restart the animation
            plt.clf()
            PrintLeibnizsPI()
    plt.show()

if __name__ == '__main__':
    PrintLeibnizsPI()