# fdf
Help with drawing lines.

https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html

https://pastebin.com/z5bzJjLt

Big project: break it down step by step.

~step 1: 
	parse the info to see if you have a correct map. ft_parse -> parse.c

~step 2: int array. ft_store -> store.c
	main. I want to take in the argument. pull the data. how? I run get next line once. y++ and use the line to find the
	length of my width/x. then run get next line until the end to find total height or my y value. note:( I can possibly store my 
	cartesian points and my z value at the same time). i close my fd and run it again now looking for my z value, strsplit my line and atoi and 
	store it into an int array that is **height(y) by  *width(x). values should be saved into t_map struct

~step 3: ft_enviroment -> enviroment.c
	set up your t_env enviroment struct. this big ass struct will help you carry around 
	useful variables to use and info you might need for calculations.
	x1,y1,x2,y2 values are used to plot your lines. point1 to point 2.
	hmax and hmin are used for color ranges. to show change in height from min height to max height of your z values.
	w, h, and big. width, height, and big = which ever of the two is bigger.
	if it was 15w by 12h. big = 15

	gap:
	first you need to figure out how big of a square or gap between points in your map is.
	so take a number like 600,700,800 and divide by your big value. if my map is a 15w by 10h map, i would take 700/15.
	 in a map of 600 pixels across, each point1 to point 2 would be 46 pixels wide and 46 pixels high. a 46 pixel by 46 pixel square.

	m, rise, run: theese are used for your m = rise/run. m = slope basically.

	max and maxside: max: as a bonus i use my tile to figure out the size of my map needed to make a proper window to fill everything. play around with the numbers.
	i wanted a rectangular window so i just take my max and -300 from it.

	cart: ft_makecartesian will take in your t_map to use thoose numbers to set up your cartesian coordinate points array, a 2-d array of t_points.
	what we want to be storing are pixel coordinates of x and y. the raw z value and then we [scale] the z value/z value multiplied by some number
	like 5 or 20 because the normal z value is too low to show a good perspective usually.
	find the midx = your maps width/2. midy = maps height/2.
	w = 15, h = 10

	j is your moving x coordinate
	i is your moving y coordinate
	((fdf->j - m->midx) * fdf->gap);
	((fdf->i - m->midy) * fdf->gap);
	use this formula to get pixel coordinates where the midpoint is (0,0). your x=0,y=0 will start in negative pixels.
	now if your able to record the midpoint of your grid at 0,0 if you move/add [translation] equal to the middle of ur map,
	 you are moving that 0,0 to the middle of the map. now you are centered everytime. tadah! motha fucka.
	middle of ur map = half your total mapwidth x half your total mapheight.


	Dimension = 1490.000000 x 1190.000000
	pixel gap = 46
	x/width = 15, y/height = 10
	midx = 7, midy = 5
	(0,0) = (-230.000000, -322.000000)
	(0,1) = (-230.000000, -276.000000)
	(1,0) = (-184.000000, -322.000000)
	(5,7) = (0.000000, 0.000000)
	(9,14) = (184.000000, 322.000000)

	(*fdf)->mlx = mlx_init();
	(*fdf)->win = mlx_new_window((*fdf)->mlx, (*fdf)->max, (*fdf)->maxside, "FDF");
	keep your mlx init and mlx new window so you can redraw it and call it later.

~step 4 ft_hooked
	not quite working yet. probably better if i keep this in my env struct actually.
	so i just keep everything at 0 if im adding or 1 if i multiply, i do have it set up for the bonus tho.

ok back to main.
~step 5 ft_draw ->drawlogic.c
	so you have your pixel coordinates. still just using x and y. you have not applied any z values to them. apply rotation then move your new tilted shit to the middle of the map.
*step 6 ft_rotate ->rotate.c
	https://en.wikipedia.org/wiki/Rotation_matrix
	go here and down to the 3 dimensional rotation
	gang sign tutorial:
	hold your left hand out. point your thumb to yourself. index finger up to the sky and middle finger to your right. thumb is your z value, middle finger is your x, and index finger is your y.

	º = degree angle in radians.
	5 sec matrix math rule tutorial: variable on sides = top variables mulitiplied down then added together.

	keep your thumb the same position pointing towards yourself and bend your wrist down to your right. index points from sky to the right 
	and middle finger goes from right to down. this is rotating around the z axis. z doesnt change.
		x 		y 	  z
	x[cosº + -sinº  + 0]
	y[sinº +  cosº  + 0]
	z[0	   +   0    + 1]

	x = x * cos(0.7854) - y * sin(0.7854);
	y = x * sin(0.7854) + y * cos(0.7854);
	/* .7854 radians = 45 degrees*/ 

	keep your middle finger in the spot point right and rotate your wrist forward and back, index finger should go from pointing up to pointing foward. thumb from you to the sky. this is rotating around the x axis.
		x 	  y 	     z
	x[  1 +   0    +     0]
	y[  0 +  cosº  + -sinº]
	z[  0 +  sinº  +  cosº]

	y = (y * cos(0.6982) - z * sin(0.6982));
	z = (y * sin(0.6982) + z * cos(0.6982));
	/* .6982 radians = 40 degrees*/ 

	Rotate your wrist left and right, keeping your index finger at the same spot. your thumb and middle finger will point at different spots. you are rotating around the y axis.
		x 	   y 	    z
	x[cosº  +  0   + sinº]
	y[  0   +  1   +    0]
	z[-sinº +  0   + cosº]

	x = x * cos(0.0524) + z * sin(0.0524);
	z = -(x * sin(0.0524)) + z * cos(0.0524);
	/* .0524 radians = 3 degrees*/ 


	depending on which you rotate first, it will look different. try z x y.

*step 7 ft_translate
	Now for it to work you actually have to rotate your values first then translate to the middle. doing it in the wrong order will give you a headache.

	so right now the mid point of your grid is at 0,0. if we add the middle of your map to all of your x and y pixel coordinates you will center your grid.

	x = x + ((*f)->max / 2);
	y = y + ((*f)->maxside / 2);
	translation = [max/2 = 742.000000] [maxside/2 = 371.000000]

~step 8 ft_drawlogic again.

brian will has a cool video on bresenham's line algorithm. watch if you want. not rly needed.
https://youtu.be/IDFB5CDpLDE?t=3m5s
ok you got the right numbers lets draw this son of a bitch.
split up your drawing points to drawing right and drawing down. you will use the same algorithm for both just your 2nd point will be slightly different.
if you draw right then 
	x1 = x, y1 = y. [x2 = x + 1], y2 = y.
if your draw down then
	x1 = x, y1 = y. x2 = x, [y2 = y + 1].

we are going to take this algorithmn and turn into c however you can.:
	void bresenhamLineUnoptimized(point1, point2, color)
{
	x1, y1 
	x2, y2
	rise = y2 - y1;
	run = x2 - x1;
	if (run == 0)
	{
		if (y2 < y1)
			y1, y2 = (y2, y1)
		for y in range(y1, y2+1)
			mlx_pixel_put(x1, y, color)
	}
	else
	{
		m = float(rise) / run;
		m >= 0 ? adjust = 1 : adjust = -1; (adjust = 1 if m >= 0 else -1)
		offset = 0;
		threshold = 0.5
		if (m <= 1 && m >= -1)
		{
			delta = abs(m);
			y = y1;
			if (x2 < x1)
			{
				x1, x2 = (x2, x1);
				y = y2;
			}
			for (x in range (x1, x2+1))
			{
				mlx_pixel_put(x, y, color)
				offset += delta
				if offset >= threshold
				{
					y += adjust;
					threshold += 1;
				}
			}
		}
		else
		{
			delta = abs(float(run) / rise);
			x = x1;
			if (y2 < y1)
			{
				y1, y2 = (y2, y1);
				x = x2;
			}
			for y in range (y1, y2+1)
			{
				mlx_pixel_put(x, y, color)
				offset += delta
				if (offset >= threshold)
				{
					x += adjust;
					threshold += 1;
				}
			}
		}
	}
}

so lets break it down. first part is just setting up your x1, x2, y1, y2. lets do drawright first

void bresenham

	x1, y1 
	x2, y2
	rise = y2 - y1;
	run = x2 - x1;
	if (run == 0)
	{
		if (y2 < y1)
			y1, y2 = (y2, y1)
		for y in range(y1, y2+1)
			mlx_pixel_put(x1, y, color)
	}

ft_setpointsright
set your points. 
currrent z and next z is for color to show change and altitude. lower z percentage wil b a different color, higher z values will have a different color. worry about color later. 
x1 = x, x2 = x + 1, y2 = y, y1 = y.
rise  = y2 - y1
run = x2 - x1

if the run == 0
then its a straight line so ft_slopestraight
swap ints if y2 is smaller then y1. then draw!

next is split into different slopes.
	m = float(rise) / run;
	m >= 0 ? adjust = 1 : adjust = -1; (adjust = 1 if m >= 0 else -1)
	offset = 0;
	threshold = 0.5

 if slope is in the decimal values, m <= 1 && m >= -1 then its a gradual slope
 ft_slopegradual
 if (m <= 1 && m >= -1)
		{
			delta = abs(m);
			y = y1;
			if (x2 < x1)
			{
				x1, x2 = (x2, x1);
				y = y2;
			}
			for (x in range (x1, x2+1))
			{
				mlx_pixel_put(x, y, color)
				offset += delta
				if offset >= threshold
				{
					y += adjust;
					threshold += 1;
				}
			}
		}

otherwise slope is very sharp up or down.
ft_slopesharp
else
		{
			delta = abs(float(run) / rise);
			x = x1;
			if (y2 < y1)
			{
				y1, y2 = (y2, y1);
				x = x2;
			}
			for y in range (y1, y2+1)
			{
				mlx_pixel_put(x, y, color)
				offset += delta
				if (offset >= threshold)
				{
					x += adjust;
					threshold += 1;
				}
			}
		}
thats it. now drawdown and you should be done



pick any color
http://hdwall.us/wallpaper/colorful_hex_palette_desktop_1280x1024_hd-wallpaper-207544.jpg


/* old info with isometric math if you want to skip the z rotation, i feel this is harder.*/
http://clintbellanger.net/articles/isometric_math/
read the website.

you can divide gap again by half if you want.
tile = gap.
tile height = half of tile width for isometric projection values.
tilew = 48, tileh = 24.
screen.x = (map.x - map.y) * TILE_WIDTH_HALF; 
screen.y = (map.x + map.y) * TILE_HEIGHT_HALF;
for (0,0) -> (0,0)
x = (0 - 0) * 24 = 0
y = (0 - 0) * 12 = 0
for (0, 1) -> (12, 24)
x = (1 - 0) * 24 = 24
y = (1 + 0) * 12 = 12
for (1, 0) ->(12, -24)
x = (0 - 1) * 24 = -24
y = (0 + 1) * 12 = 12

this we start giving you the diamond look. (0,0) is the top of your. 
when you increase x, you are going down 12 pixels and to the right 24, positive pixels. (12, 24)
when you increase y, you are going down 12 pixels and to the left 24 pixels, negative from the 0,0 start point.
		(0,0)
		/	\
	   /     \
 (12,-24)	  (12, 24)

 so i want my starting point on my map to be at a certain point so i apply a [translation] to the coordinates by adding to it. i add 650 to x and 500 to y. they are just numbers i chose.
x/width = 15, y/height = 10
midx = 7, midy = 5
(0,0) = (500.000000, 650.000000)
(0,1) = (512.000000, 674.000000)
(1,0) = (512.000000, 626.000000)
(5,7) = (644.000000, 698.000000)

 	  (500,650)
		/	\
	   /     \
 (512,626)	 (512,674)

i tried to center it more by applying ths formula
c[i][j].x = ((j - midx) * tilewh) + m->isox;
c[i][j].y = ((i - midy) * tilehh) + m->isoy;
midx = 7, midy = 5
(0,0) = (440.000000, 482.000000)
(0,1) = (452.000000, 530.000000)
(1,0) = (464.000000, 458.000000)
(5,7) = (644.000000, 698.000000)

c[0][0].x = (-7) * 24 + 650 = -168 + 650
play around with it. start with just using the isox and isoy values and see where you end up.
c[fdf->i][fdf->j].x = m->isox;
c[fdf->i][fdf->j].y = m->isoy;
*/






# fdf_1.0
# fdf_1.0
