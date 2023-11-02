## Extra content

This is entirely optional content for those who really want to print large scale versions of their gestural drawing tools that document the history of your movement by drawing the pixel values to an FBO. 

It's a bit of a hack, but might be enough to start playing with. 

The principle behind this sketch is that an A4 page at 72 DPI (good for screens) is 595 x 842 seen here: https://www.a4-size.com/a4-size-in-pixels/
At 300 DPI (good for printing) you'd need it to be 2480 x 3508 to print a crisp A4 image. 

If you export a larger bitmap image, then in an image editing software you change the DPI to 300 which will make your image ready for print. The best way to do that is to not resample the image when you change the DPI (see tutorial below which explains resampling and not resampling).

How-to in photoshop:
https://www.alphr.com/change-dpi-photoshop/

