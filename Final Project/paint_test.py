from tkinter import *
from PIL import Image, ImageDraw
import io

width = 400
height = 400
black = (0, 0, 0)
size = 28, 28

def save():
	global image1
	image1.thumbnail(size, Image.ANTIALIAS)
	image1 = image1.tobytes()
	print(image1)
	exit()

def paint(event):
	global cv, draw
	x1, y1 = (event.x - 5), (event.y - 5)
	x2, y2 = (event.x + 5), (event.y + 5)

	cv.create_oval(x1, y1, x2, y2, fill='white', outline='white')
	draw.ellipse([x1, y1, x2, y2], fill="white")

def main():
	global image1, cv, draw
	root = Tk()

	cv = Canvas(root, width=width, height=height, bg='black')
	cv.pack()

	image1 = Image.new("L", (width, height))
	draw = ImageDraw.Draw(image1)

	cv.pack(expand=YES, fill=BOTH)
	cv.bind("<B1-Motion>", paint)

	button=Button(text="save",command=save)
	button.pack()
	root.mainloop()

if __name__=='__main__':
    main()