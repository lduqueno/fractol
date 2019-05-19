__kernel void julia_float(__global int* pixels, int win_height,
			int win_width, int max_iteration, float zoom, float move_x,
			float move_y, int color_count, __global int *colors)
{
	int iteration = 0;
	int x = get_global_id(0);
	int y = get_global_id(1);
	float cRe = 1.5 * (x - win_width / 2) / (0.5 * zoom * win_width) + move_x;
	float cIm = 1.5 * (y - win_height / 2) / (0.5 * zoom * win_height) + move_y;
	float powRe = cRe * cRe;
	float powIm = cIm * cIm;
	
	while (iteration < max_iteration && powRe + powIm < 4)
	{
		cIm = 2 * cRe * cIm + 0.27015;
		cRe = powRe - powIm + -0.7;
		powRe = cRe * cRe;
		powIm = cIm * cIm;
		iteration++;
	}
	if (iteration == max_iteration)
		pixels[y * win_width + x] = 0x00000;
	else
		pixels[y * win_width + x] = colors[iteration % color_count];
}
